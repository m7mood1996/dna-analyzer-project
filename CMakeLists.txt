cmake_minimum_required(VERSION 3.17)
project(DNA)

set(CMAKE_CXX_STANDARD 98)

add_executable(DNA main.cpp DnaSequence.cpp DnaSequence.h Nucleotide.cpp Nucleotide.h A.cpp A.h C.cpp C.h G.cpp G.h T.cpp T.h)
target_link_libraries(DNA gtest gtest_main pthread)