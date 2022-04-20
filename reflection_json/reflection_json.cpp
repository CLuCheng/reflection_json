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

  auto value = JsonReflection::to_json<Persons>(persons);
  auto ref_b = JsonReflection::from_json<Persons>(value);
  std::cout << JsonReflection::to_string(value) << std::endl;

  return 0;
}
