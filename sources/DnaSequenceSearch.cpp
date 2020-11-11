//
// Created by mahmood on 11/1/20.
//

#include <exception>
#include <list>
#include "DnaSequenceSearch.h"
#include "DnaSequence.h"
#include "Nucleotide.h"


std::size_t DnaSequenceSearch::Find(DnaSequence &dnaSequence, DnaSequence &sub_dnaSequence) {
    if (sub_dnaSequence.getLength() > dnaSequence.getLength() || sub_dnaSequence.getLength()==0 )
        throw std::runtime_error("sub dna sequence can not be bigger then the orignal dna sequence");

    size_t sL = sub_dnaSequence.getLength();
    size_t l = dnaSequence.getLength() - sub_dnaSequence.getLength();
    size_t k = 0;
    for (size_t i = 0; i < l; i++) {
        if (dnaSequence[i].getType() == sub_dnaSequence[k].getType()) {
            for (int j = 0; j < sub_dnaSequence.getLength(); j++) {
                if (dnaSequence[i + j].getType() == sub_dnaSequence[j].getType()) {
                    sL--;
                    if (sL == 0)
                        return i;


                }

            }
        }

    }
    return -1;

}

std::size_t DnaSequenceSearch::Count(DnaSequence &dnaSequence, DnaSequence &sub_dnaSequence) {
    if (sub_dnaSequence.getLength() > dnaSequence.getLength() || sub_dnaSequence.getLength()==0 )
        throw std::runtime_error("sub dna sequence can not be bigger then the orignal dna sequence");
    size_t count =0;
    size_t sL = sub_dnaSequence.getLength();
    size_t l = dnaSequence.getLength() - sub_dnaSequence.getLength();
    size_t k = 0;
    for (size_t i = 0; i < l; i++) {
        if (dnaSequence[i].getType() == sub_dnaSequence[k].getType()) {
            for (int j = 0; j < sub_dnaSequence.getLength(); j++) {
                if (dnaSequence[i + j].getType() == sub_dnaSequence[j].getType()) {
                    sL--;
                    if (sL == 0) {
                        count++;
                        sL = sub_dnaSequence.getLength();
                        break;
                    }


                }

            }
        }

    }
    return count;
}

std::list<size_t> DnaSequenceSearch::FindAll(DnaSequence &dnaSequence, DnaSequence &sub_dnaSequence) {
    if (sub_dnaSequence.getLength() > dnaSequence.getLength() || sub_dnaSequence.getLength()==0 )
        throw std::runtime_error("sub dna sequence can not be bigger then the orignal dna sequence");
    std::list<size_t> indexes;
    size_t sL = sub_dnaSequence.getLength();
    size_t l = dnaSequence.getLength() - sub_dnaSequence.getLength();
    size_t k = 0;
    for (size_t i = 0; i < l; i++) {
        if (dnaSequence[i].getType() == sub_dnaSequence[k].getType()) {
            for (int j = 0; j < sub_dnaSequence.getLength(); j++) {
                if (dnaSequence[i + j].getType() == sub_dnaSequence[j].getType()) {
                    sL--;
                    if (sL == 0) {
                        indexes.push_back(i);
                        sL = sub_dnaSequence.getLength();
                        break;
                    }


                }

            }
        }

    }
    return indexes;
}

std::list<size_t> DnaSequenceSearch::FindConsensusSequences(DnaSequence &dnaSequence) {
    static const DnaSequence startCodon("ATG");
    static const DnaSequence EndCodons[] = {DnaSequence("TAG"),DnaSequence("TAA"),DnaSequence("TGA")};
    if (dnaSequence.getLength() <=3)
        throw std::runtime_error("cant finding codons in dna with less than 3 Nucleotides");

    size_t startCodonIndex = Find(dnaSequence, const_cast<DnaSequence &>(startCodon));

    std::list<size_t> endCodonsIndex1 = FindAll(dnaSequence, const_cast<DnaSequence &>(EndCodons[0]));
    std::list<size_t> endCodonsIndex2 = FindAll(dnaSequence, const_cast<DnaSequence &>(EndCodons[1]));
    std::list<size_t> endCodonsIndex3 = FindAll(dnaSequence, const_cast<DnaSequence &>(EndCodons[2]));
    std::list<size_t> endCodonsFINAL;

    for (size_t i = 0; i < endCodonsIndex1.size();i++){
        if (endCodonsIndex1.front() >startCodonIndex) {
            endCodonsFINAL.push_back(endCodonsIndex1.front());
            endCodonsIndex1.pop_front();
        }
    }
    for (size_t i = 0; i < endCodonsIndex2.size();i++){
        if (endCodonsIndex2.front() >startCodonIndex) {
            endCodonsFINAL.push_back(endCodonsIndex2.front());
            endCodonsIndex2.pop_front();
        }
    }
    for (size_t i = 0; i < endCodonsIndex3.size();i++){
        if (endCodonsIndex3.front() >startCodonIndex) {
            endCodonsFINAL.push_back(endCodonsIndex3.front());
            endCodonsIndex3.pop_front();
        }
    }

    endCodonsFINAL.push_front(startCodonIndex);


    return endCodonsFINAL;
}
