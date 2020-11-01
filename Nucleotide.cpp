//
// Created by mahmood on 10/21/20.
//

#include "Nucleotide.h"

std::ostream &operator<<(std::ostream &os, const Nucleotide &nucleotide) {
    os << nucleotide.m_type;

    return os;
}

Nucleotide::Nucleotide() {

}

Nucleotide::~Nucleotide() {

}

void Nucleotide::setType(char type) {
    m_type = type;

}

char Nucleotide::getType() const{
    return m_type;
}
