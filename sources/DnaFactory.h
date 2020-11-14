//
// Created by mahmood on 11/13/20.
//

#ifndef DNA_DNAFACTORY_H
#define DNA_DNAFACTORY_H

#include "DnaSequenceDecorator.h"

class DnaFactory {
public:
    virtual DnaSequenceDecorator* creat(const std::string &dna, std::string &dna_name, size_t id) = 0;
    virtual ~DnaFactory();
};



#endif //DNA_DNAFACTORY_H
