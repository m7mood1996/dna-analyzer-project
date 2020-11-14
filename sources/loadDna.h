//
// Created by mahmood on 11/13/20.
//

#ifndef DNA_LOADDNA_H
#define DNA_LOADDNA_H

#include "DnaFactory.h"

class DnaSequenceDecorator;
class loadDna :public DnaFactory{
public:
    virtual DnaSequenceDecorator* creat(const std::string &dna, std::string &dna_name, size_t id);

};


#endif //DNA_LOADDNA_H
