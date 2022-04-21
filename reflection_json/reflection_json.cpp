#include "reflection_json.h"

#include "json_cpp_reflection.hpp"
#include "json_parser.hpp"
#include "reflection.hpp"
using JsonReflection =
    details::JsonReflection<details::JsonBase<details::JsonCPP>>;

int main() {
  Persons persons;
  persons.arr.push_back(Person{"Rose", 24, false});
  persons.arr.push_back(Person{"Jack", 25, true});

  auto json_value = JsonReflection::to_json<Persons>(persons);
  auto value = JsonReflection::from_json<Persons>(json_value);
  std::cout << JsonReflection::to_string(json_value) << std::endl;

  return 0;
}
