//
// Created by mahmood on 10/21/20.
//

#include "T.h"

T::T():Nucleotide() {

}

T::~T() {

}

std::ostream &T::out(std::ostream &os) const {
    os << 'T';
    return os;
}

std::ostream &operator<<(std::ostream &os, const T &t) {
    return t.out(os);
}
