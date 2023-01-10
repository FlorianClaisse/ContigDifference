cmake_minimum_required(VERSION 3.24)
project(ContigDifference C)

set(CMAKE_C_STANDARD 99)

############################# SOURCE #############################

set(UTILS_SRC Utils/Array/String/StringArray.c Utils/Array/String/StringArray.h Utils/directory.c Utils/directory.h Utils/String/String.c Utils/String/String.h)
set(CONTIG_SRC Contig/contig.c Contig/contig.h)
set(SRC decodeCommand.c decodeCommand.h)

############################# LIBRARY #############################

add_library(code ${UTILS_SRC} ${CONTIG_SRC} ${SRC})

############################# EXECUTABLE #############################

add_executable(ContigDifference main.c)

############################# LINK LIBRARY #############################

target_link_libraries(ContigDifference code)