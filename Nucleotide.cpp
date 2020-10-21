//
// Created by mahmood on 10/21/20.
//

#include "Nucleotide.h"

std::ostream &operator<<(std::ostream &os, const Nucleotide &nucleotide) {

    return nucleotide.out(os);
}

Nucleotide::Nucleotide() {

}

Nucleotide::~Nucleotide() {

}
