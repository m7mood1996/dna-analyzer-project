//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_C_H
#define DNA_C_H

#include "Nucleotide.h"
class C : public Nucleotide{
public:
    C();
    ~C();
    virtual std::ostream& out(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const C& c);

};


#endif //DNA_C_H
