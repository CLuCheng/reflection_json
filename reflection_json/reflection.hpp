#pragma once
#include <string>
#include <vector>

#include "macro_gen.h"
#include "reflection.h"

DEF_STRUCT(Person, std::string, name, int, age, bool, is_male);
DEF_STRUCT(Persons, std::vector<Person>, arr);

DEFINE_STRUCT_SCHEMA(Person, DEFINE_STRUCT_FIELD(name, "name"),
                     DEFINE_STRUCT_FIELD(is_male, "is_male"),
                     DEFINE_STRUCT_FIELD(age, "age"));

DEFINE_STRUCT_SCHEMA(Persons, DEFINE_STRUCT_FIELD(arr, "arr"));