#pragma once
#include "json_parser.hpp"
#include "json/json.h"

namespace details {
struct JsonCPP {
  using value_type = ::Json::Value;
  using const_ref_value_type = const value_type&;
  using ref_value_type = value_type&;

  template <class U>
  struct is_json_value {
    static bool constexpr value = false;
  };
  template <>
  struct is_json_value<::Json::Value> {
    static bool constexpr value = true;
  };

 public:
  template <class U>
  static constexpr bool is_json_value_v = is_json_value<U>::value;

  value_type static inline json_parser(const std::string& row_str) noexcept {
#pragma warning(disable : 4996)
    value_type root;
    Json::Reader reader;
    reader.parse(row_str, root);
    return root;
  }

  template <class T>
  void static inline constexpr set(ref_value_type value, T&& field) noexcept {
    value = std::forward<T>(field);
  }

  template <class T>
  void static inline constexpr set(ref_value_type value,
                                   const std::string& name,
                                   T&& field) noexcept {
    set<T>(value[name], std::forward<T>(field));
  }

  template <class T>
  void static inline constexpr get(const_ref_value_type value,
                                   T&& field) noexcept {
    if (value.isNull())
      return;
    if constexpr (std::is_same_v<std::decay_t<T>, int>) {
      field = value.asInt();
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
      field = value.asCString();
    } else if constexpr (std::is_same_v<std::decay_t<T>, bool>) {
      field = value.asBool();
    } else if constexpr (std::is_enum_v<std::decay_t<T>>) {
      field = std::decay_t<T>(value.asInt());
    } else if constexpr (std::is_floating_point_v<std::decay_t<T>>) {
      field = value.asFloat();
    } else if constexpr (std::is_same_v<std::decay_t<T>, int64_t>) {
      field = value.asInt64();
    } else {
      field = value;
    }
  }

  template <class T>
  void static inline constexpr get(const_ref_value_type value,
                                   const std::string& name,
                                   T&& field) noexcept {
    if (value.isNull())
      return;
    get<T>(value[name], std::forward<T>(field));
  }

  template <class Function>
  void static inline constexpr for_each_array(const_ref_value_type value,
                                         const std::string& name,
                                         Function&& fn) {
    if (value.isNull())
      return;
    for_each_array(value[name], std::forward<Function>(fn));
  }

  template <class Function>
  void static inline constexpr for_each_array(const_ref_value_type value,
                                              Function&& fn) {
    if (value.isNull())
      return;
    for (int i = 0; i < value.size(); i++) {
      fn(value[i]);
    }
  }

  template <class U>
  void static inline constexpr set_array_index(ref_value_type value, int index,
                                               U&& obj) {
    value[index] = std::forward<U>(obj);
  }

  static std::string to_string(const_ref_value_type value) noexcept {
    return value.toStyledString();
  }
};
}  // namespace details
