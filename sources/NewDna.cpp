//
// Created by mahmood on 11/13/20.
//

#include "NewDna.h"
#include "DnaSequenceDecorator.h"


DnaSequenceDecorator *NewDna::creat(const std::string &dna, std::string &dna_name, size_t id) {
    return new DnaSequenceDecorator(dna, dna_name,id);
}
