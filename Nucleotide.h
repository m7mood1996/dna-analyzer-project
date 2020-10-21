//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_NUCLEOTIDE_H
#define DNA_NUCLEOTIDE_H

#include <iostream>
class Nucleotide {
public:
    Nucleotide();

    virtual ~Nucleotide();

    virtual std::ostream& out(std::ostream& os) const =0;
    friend std::ostream& operator<<(std::ostream& os, const Nucleotide& nucleotide);


};


#endif //DNA_NUCLEOTIDE_H
