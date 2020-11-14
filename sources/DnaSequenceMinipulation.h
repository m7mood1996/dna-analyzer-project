//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCEMINIPULATION_H
#define DNA_DNASEQUENCEMINIPULATION_H
#include <vector>
#include "DnaSequenceDecorator.h"

class DnaSequenceMinipulation {
public:
    static const std::string Slice(DnaSequence &dnaSequence, size_t from, size_t to);
    static DnaSequenceDecorator* Concat( std::vector<DnaSequenceDecorator*> &dnaSequenceDecorators, std::string &newName, size_t id);
};


#endif //DNA_DNASEQUENCEMINIPULATION_H
