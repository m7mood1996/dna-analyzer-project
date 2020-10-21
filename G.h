//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_G_H
#define DNA_G_H

#include "Nucleotide.h"
class G : public Nucleotide{
public:
    G();
    ~G();
    virtual std::ostream& out(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const G& g);

};


#endif //DNA_G_H
