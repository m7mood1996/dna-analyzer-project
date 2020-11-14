//
// Created by mahmood on 11/13/20.
//

#ifndef DNA_NEWDNA_H
#define DNA_NEWDNA_H

#include "DnaFactory.h"

class DnaSequenceDecorator;
class NewDna: public DnaFactory {
public:
    virtual DnaSequenceDecorator* creat(const std::string &dna, std::string &dna_name, size_t id);
};


#endif //DNA_NEWDNA_H
