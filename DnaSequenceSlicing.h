//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCESLICING_H
#define DNA_DNASEQUENCESLICING_H

#include "DnaSequence.h"

class DnaSequenceSlicing {
public:
    static DnaSequence Slice(DnaSequence &dnaSequence, size_t from, size_t to);

};


#endif //DNA_DNASEQUENCESLICING_H
