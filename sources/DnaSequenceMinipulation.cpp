//
// Created by mahmood on 11/1/20.
//
#include <exception>
#include <iostream>
#include "DnaSequenceMinipulation.h"
#include "DnaSequenceDecorator.h"
#include "Nucleotide.h"

using namespace std;

const string DnaSequenceMinipulation::Slice(DnaSequence &dnaSequence, size_t from, size_t to) {
    if (from > to || to > dnaSequence.getLength())
        throw runtime_error("error while slicing");

    string newDna;

    if (to > dnaSequence.getLength())
        to = dnaSequence.getLength();

    for (size_t i= from; i < to ; i++) {
        newDna += dnaSequence[i].getType();
    }

    return newDna;
}

DnaSequenceDecorator *DnaSequenceMinipulation::Concat(std::vector<DnaSequenceDecorator *> &dnaSequenceDecorators, string &newName, size_t id) {

    DnaSequenceDecorator * newDnaSequence = new DnaSequenceDecorator("",newName,id);
    size_t i = 0, j = 0, k;
    for (;i<dnaSequenceDecorators.size();i++){
        newDnaSequence->size += dnaSequenceDecorators[i]->getLength();
    }
    delete [] newDnaSequence->nucleotides;
    newDnaSequence->nucleotides = new Nucleotide[newDnaSequence->getLength()];
    i = 0;
    for (i = dnaSequenceDecorators.size() -1  ;i >= 0 ;i--) {
        for (k = 0;k < dnaSequenceDecorators[i]->getLength();k++) {
            newDnaSequence->nucleotides[j] = dnaSequenceDecorators[i]->nucleotides[k];
            j++;
        }
        if (i == 0)
            break;
    }

    return newDnaSequence;
}
