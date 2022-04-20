cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(JSON_CPP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jsoncpp)

set(JSON_CPP_INCLUDE_DIR ${JSON_CPP_DIR}/include)
set(JSON_CPP_SRC_DIR ${JSON_CPP_DIR}/src/lib_json)
set(JSON_CPP_SRC ${JSON_CPP_SRC_DIR}/json_reader.cpp ${JSON_CPP_SRC_DIR}/json_value.cpp ${JSON_CPP_SRC_DIR}/json_writer.cpp )

set(SRC_FILES  ${JSON_CPP_SRC})

add_executable (reflection_json ${SRC_FILES} "reflection_json.cpp" "reflection_json.h")
target_include_directories(reflection_json PUBLIC
  ${JSON_CPP_INCLUDE_DIR}
)
