//
// Created by mahmood on 11/1/20.
//
#include <exception>
#include <iostream>
#include "DnaSequenceSlicing.h"
#include "Nucleotide.h"

using namespace std;

DnaSequence DnaSequenceSlicing::Slice(DnaSequence &dnaSequence,size_t from, size_t to) {
    if (from > to || to > dnaSequence.getLength())
        throw runtime_error("unable to open file");

    string newDna;
    for (size_t i= from; i < to ; i++) {
        newDna += dnaSequence[i].getType();
    }

    return DnaSequence(newDna, "");
}
