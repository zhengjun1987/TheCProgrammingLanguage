cmake_minimum_required(VERSION 3.7)
project(TheCProgrammingLanguage)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES chapter01/first.c chapter01/another.c chapter01/fahr2cels.c chapter01/array.c chapter01/power.c chapter01/max_line.c)
add_executable(TheCProgrammingLanguage ${SOURCE_FILES})