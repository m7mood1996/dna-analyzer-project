//
// Created by mahmood on 11/11/20.
//

#include "DnaSequenceDecorator.h"
#include "DnaSequence.h"

std::string DnaSequenceDecorator::getName() {
    return name;
}

void DnaSequenceDecorator::setName(std::string &newName) {
    name = newName;

}

DnaSequenceDecorator::DnaSequenceDecorator(std::string newDnaSequence, std::string newName , size_t id):DnaSequence(newDnaSequence)
,name(newName),m_id(id) {}

DnaSequenceDecorator::DnaSequenceDecorator(DnaSequenceDecorator &dnaSequenceDecorator,std::string newName , size_t id):
DnaSequence(dnaSequenceDecorator),name(newName),m_id(id) {}

void DnaSequenceDecorator::setid(size_t id) {
    m_id = id;

}

size_t DnaSequenceDecorator::getId() {
    return m_id;
}
