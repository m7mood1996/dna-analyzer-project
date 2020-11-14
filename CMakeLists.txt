cmake_minimum_required(VERSION 3.17)
project(DNA)

set(CMAKE_CXX_STANDARD 98)


add_executable(DNA sources/main.cpp sources/DnaSequence.cpp sources/DnaSequence.h sources/Nucleotide.cpp sources/Nucleotide.h sources/DnaSequenceFile.cpp sources/DnaSequenceFile.h sources/DnaSequenceMinipulation.cpp sources/DnaSequenceMinipulation.h sources/DnaSequencePairing.cpp sources/DnaSequencePairing.h sources/DnaSequenceSearch.cpp sources/DnaSequenceSearch.h sources/CLI.cpp sources/CLI.h sources/DnaSequenceDecorator.cpp sources/DnaSequenceDecorator.h sources/DnaFactory.h sources/NewDna.cpp sources/NewDna.h sources/loadDna.cpp sources/loadDna.h sources/DnaFactory.cpp)

target_link_libraries(DNA gtest gtest_main pthread)