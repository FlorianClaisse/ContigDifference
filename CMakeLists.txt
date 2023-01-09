cmake_minimum_required(VERSION 3.24)
project(ContigDifference C)

set(CMAKE_C_STANDARD 99)

############################# SOURCE #############################

set(FSOURCE Foundation/directory.c Foundation/Array/String/StringArray.c Foundation/Array/String/StringArray.h)
set(SOURCE decodeCommand.c Foundation/Array/String/StringArray.c Foundation/Array/String/StringArray.h)

############################# LIBRARY #############################

add_library(code ${FSOURCE} ${SOURCE})

############################# EXECUTABLE #############################

add_executable(ContigDifference main.c)

############################# LINK LIBRARY #############################

target_link_libraries(ContigDifference code)