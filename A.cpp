//
// Created by mahmood on 10/21/20.
//

#include "A.h"

A::A():Nucleotide() {

}

A::~A() {

}

std::ostream &A::out(std::ostream &os) const {
    os << "A";
    return os;
}

std::ostream &operator<<(std::ostream &os, const A &a) {
    return a.out(os);
}
