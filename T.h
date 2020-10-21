//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_T_H
#define DNA_T_H


#include "Nucleotide.h"

class T: public Nucleotide {
public:
    T();
    ~T();
    virtual std::ostream& out(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const T& t);

};


#endif //DNA_T_H
