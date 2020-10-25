//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_A_H
#define DNA_A_H

#include "Nucleotide.h"

class A: public Nucleotide {
public:
    A();
    ~A();
    virtual std::ostream& out(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const A& a);

};


#endif //DNA_A_H
