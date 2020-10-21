//
// Created by mahmood on 10/21/20.
//

#include "G.h"


G::G():Nucleotide() {

}

G::~G() {

}

std::ostream &G::out(std::ostream &os) const {
    os << 'G';
    return os;
}

std::ostream &operator<<(std::ostream &os, const G &g) {
    return g.out(os);
}
