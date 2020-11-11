cmake_minimum_required(VERSION 3.17)
project(DNA)

set(CMAKE_CXX_STANDARD 98)


add_executable(DNA main.cpp sources/DnaSequence.cpp sources/DnaSequence.h sources/Nucleotide.cpp sources/Nucleotide.h sources/DnaSequenceFile.cpp sources/DnaSequenceFile.h sources/DnaSequenceSlicing.cpp sources/DnaSequenceSlicing.h sources/DnaSequencePairing.cpp sources/DnaSequencePairing.h sources/DnaSequenceSearch.cpp sources/DnaSequenceSearch.h sources/CLI.cpp sources/CLI.h sources/DnaSequenceDecorator.cpp sources/DnaSequenceDecorator.h)

target_link_libraries(DNA gtest gtest_main pthread)