//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCESEARCH_H
#define DNA_DNASEQUENCESEARCH_H

#include <iostream>
#include <list>

class DnaSequence;
class DnaSequenceSearch {
public:
    static std::size_t Find(DnaSequence& dnaSequence, DnaSequence& sub_dnaSequence);
    static std::size_t Count(DnaSequence& dnaSequence, DnaSequence& sub_dnaSequence);
    static std::list<size_t> FindAll(DnaSequence& dnaSequence, DnaSequence& sub_dnaSequence);
    static std::list<size_t> FindConsensusSequences(DnaSequence& dnaSequence);


};


#endif //DNA_DNASEQUENCESEARCH_H
