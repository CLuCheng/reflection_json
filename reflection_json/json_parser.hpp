#pragma once
#include <list>
#include <vector>

#include "reflection.h"

template <class... T>
constexpr bool always_false = false;

template <class T, class V = void>
class is_direct_serialization : public std::false_type {};

template <>
class is_direct_serialization<std::string> : public std::true_type {};

template <>
class is_direct_serialization<bool> : public std::true_type {};

template <class T>
class is_direct_serialization<
    T, std::void_t<typename std::enable_if<std::is_convertible<T, int>::value,
                                           int>::type>>
    : public std::true_type {};

template <class T>
struct is_vector {
  static bool constexpr value = false;
};

template <class T>
struct is_vector<std::vector<T>> {
  static bool constexpr value = true;
};

template <class T>
constexpr bool is_vector_v = is_vector<T>::value;

template <class T>
struct is_list {
  static bool constexpr value = false;
};

template <class T>
struct is_list<std::list<T>> {
  static bool constexpr value = true;
};

template <class T>
constexpr bool is_list_v = is_list<T>::value;

template <class T>
constexpr bool is_seq_container = is_vector_v<T> || is_list_v<T>;

namespace details {
template <class T>
struct JsonBase {
  using value_type = typename T::value_type;
  using const_ref_value_type = typename T::const_ref_value_type;
  using ref_value_type = typename T::ref_value_type;

  template <typename U>
  static constexpr bool is_json_value_v = T::template is_json_value<U>::value;

  value_type static inline json_parser(const std::string& row_str) noexcept {
    return T::json_parser(row_str);
  }

  template <class U>
  void static inline constexpr set(ref_value_type value, U&& field) noexcept {
    T::set(value, std::forward<U>(field));
  }

  template <class U>
  void static inline constexpr set(ref_value_type value,
                                   const std::string& name,
                                   U&& field) noexcept {
    T::set(value, name, std::forward<U>(field));
  }

  template <class U>
  void static inline constexpr get(const_ref_value_type value,
                                   U&& field) noexcept {
    T::get(value, std::forward<U>(field));
  }

  template <class U>
  void static inline constexpr get(const_ref_value_type value,
                                   const std::string& name,
                                   U&& field) noexcept {
    T::get(value, name, std::forward<U>(field));
  }

  template <class U>
  void static inline constexpr set_array_index(ref_value_type value, int index,
                                               U&& obj) {
    T::set_array_index(value, index, std::forward<U>(obj));
  }

  template <class Function>
  void static inline constexpr for_each_array(const_ref_value_type value,
                                              const std::string& name,
                                              Function fn) {
    T::for_each_array(value, name, std::forward<Function>(fn));
  }

  template <class Function>
  void static inline constexpr for_each_array(const_ref_value_type value,
                                              Function&& fn) {
    T::for_each_array(value, std::forward<Function>(fn));
  }

  static std::string to_string(const_ref_value_type value) noexcept {
    return T::to_string(value);
  }
};

template <class Policy>
class JsonReflection {
  using value_type = typename Policy::value_type;
  using const_ref_value_type = typename Policy::const_ref_value_type;
  using ref_value_type = typename Policy::ref_value_type;

 public:
  template <class T>
  static inline value_type to_json(const T& obj) noexcept {
    value_type root;
    ForEachField(obj, [&root](auto&& field, auto&& name) {
      using type = std::decay_t<decltype(field)>;
      if constexpr (is_direct_serialization<type>{} ||
                    Policy::template is_json_value_v<type>) {
        Policy::set(root, name, std::forward<decltype(field)>(field));
      } else if constexpr (std::is_array<
                               std::remove_reference_t<decltype(field)>>{}) {
        static_assert(always_false<type>, "array can't support");
      } else if constexpr (is_seq_container<type>) {
        value_type tmp;
        int idx = 0;
        for (auto& ele : field) {
          if constexpr (is_direct_serialization<type>{} ||
                        Policy::template is_json_value_v<type>) {
            value_type value;
            Policy::set(value, ele);
            Policy::set_array_index(tmp, idx, value);
          } else {
            Policy::set_array_index(
                tmp, idx++,
                JsonReflection::to_json<typename type::value_type>(ele));
          }
        }
        Policy::set(root, name, std::move(tmp));
      } else {
        Policy::set(root, name, JsonReflection::to_json<type>(field));
      }
    });
    return root;
  }

  template <class T>
  static inline std::string to_string(const T& obj) noexcept {
    return Policy::to_string(to_json(obj));
  }

  static inline std::string to_string(const_ref_value_type obj) noexcept {
    return Policy::to_string(obj);
  }

  template <class T>
  static inline T from_json(const_ref_value_type root) noexcept {
    T value;
    ForEachField(value, [&root](auto&& field, auto&& name) {
      using type = std::decay_t<decltype(field)>;
      if constexpr (is_direct_serialization<type>{} ||
                    Policy::template is_json_value_v<type>) {
        Policy::get(root, name, field);
      } else if constexpr (std::is_array<
                               std::remove_reference_t<decltype(field)>>{}) {
        static_assert(always_false<type>, "array can't support");
      } else if constexpr (is_seq_container<type>) {
        Policy::for_each_array(root, name, [&](const_ref_value_type node) {
          if constexpr (is_direct_serialization<type>{} ||
                        Policy::template is_json_value_v<type>) {
            value_type tmp;
            Policy::get(node, tmp);
            field.push_back(tmp);
          } else {
            field.push_back(
                JsonReflection::from_json<typename type::value_type>(node));
          }
        });
      } else {
        field = JsonReflection::from_json<type>(root[name]);
      }
    });
    return value;
  }

  template <class T>
  static inline T from_json(const std::string& row) noexcept {
    return from_json<T>(Policy::json_parser(row));
  }
};

}  // namespace details
