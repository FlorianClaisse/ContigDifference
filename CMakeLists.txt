cmake_minimum_required(VERSION 3.24)
project(ContigDifference C)

set(CMAKE_C_STANDARD 99)

############################# SOURCE #############################

set(FDIR Foundation)

set(FSOURCE ${FDIR}/Directory.c)
set(SOURCE decodeCommand.c)

############################# LIBRARY #############################

add_library(code ${FSOURCE} ${SOURCE})

############################# EXECUTABLE #############################

add_executable(ContigDifference main.c)

############################# LINK LIBRARY #############################

link_libraries(ContigDifference ${code})