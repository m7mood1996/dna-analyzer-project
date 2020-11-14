//
// Created by mahmood on 11/13/20.
//

#include "loadDna.h"
#include "DnaSequenceDecorator.h"
#include "DnaSequenceFile.h"

DnaSequenceDecorator *loadDna::creat(const std::string &dna, std::string &dna_name, size_t id) {
    return new DnaSequenceDecorator(DnaSequenceFile::ReadSequenceFromFile(dna.c_str()),dna_name,id);
}
