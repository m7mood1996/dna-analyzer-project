//
// Created by mahmood on 11/11/20.
//

#ifndef DNA_DNASEQUENCEDECORATOR_H
#define DNA_DNASEQUENCEDECORATOR_H

#include <cstddef>
#include <string>
#include "DnaSequence.h"

class DnaSequence;
class DnaSequenceDecorator: public DnaSequence {
public:
    std::string getName();
    void setName(std::string& name);
    void setid(size_t id);
    size_t getId();
    DnaSequenceDecorator(std::string newDnaSequence, std::string newName , size_t id);
    DnaSequenceDecorator(DnaSequenceDecorator& dnaSequenceDecorator,std::string newName , size_t id);

private:
    DnaSequenceDecorator();
    std::string name;
    size_t m_id;

};


#endif //DNA_DNASEQUENCEDECORATOR_H
