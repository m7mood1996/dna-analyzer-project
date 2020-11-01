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
    void setType(char type);

    char getType()const;

    friend std::ostream& operator<<(std::ostream& os, const Nucleotide& nucleotide);

private:
    char m_type;
};


#endif //DNA_NUCLEOTIDE_H
