//
// Created by mahmood on 10/21/20.
//

#include "C.h"

C::C():Nucleotide() {

}

C::~C() {

}

std::ostream &C::out(std::ostream &os) const {
    os << 'C';
    return os;
}

std::ostream &operator<<(std::ostream &os, const C &c) {
    return c.out(os);
}
