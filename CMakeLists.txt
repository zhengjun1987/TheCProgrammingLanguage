cmake_minimum_required(VERSION 3.7)
project(TheCProgrammingLanguage)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES chapter01/first.c chapter01/another.c)
add_executable(TheCProgrammingLanguage ${SOURCE_FILES})