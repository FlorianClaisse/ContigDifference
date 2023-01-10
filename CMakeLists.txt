cmake_minimum_required(VERSION 3.24)
project(ContigDifference C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-std=c99 -Wall -pthread -Wextra -Wunused-parameter")

############################# SOURCE #############################

set(FSOURCE Foundation/directory.c Foundation/directory.h Foundation/typedef.h Foundation/Array/String/StringArray.c Foundation/Array/String/StringArray.h)
set(CSOURCE Contig/contig.c Contig/contig.h)
set(SOURCE decodeCommand.c Foundation/Array/String/StringArray.c Foundation/Array/String/StringArray.h)

############################# LIBRARY #############################

add_library(code ${FSOURCE} ${CSOURCE} ${SOURCE})

############################# EXECUTABLE #############################

add_executable(ContigDifference main.c)

############################# LINK LIBRARY #############################

target_link_libraries(ContigDifference code)