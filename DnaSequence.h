//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H


#include <string>
class Nucleotide;

class DnaSequence {
public:
    DnaSequence(const char *str);
    DnaSequence(const std::string& string);
    DnaSequence(const DnaSequence& dnaSequence);
    virtual ~DnaSequence();

    friend std::ostream& operator<<(std::ostream& os, const DnaSequence& dnaSequence);
    DnaSequence& operator=(const DnaSequence& other);
    DnaSequence& operator=(const char* other);
    DnaSequence& operator=(const std::string& other);
    bool operator==(const DnaSequence& other);
    bool operator!=(const DnaSequence& other);
    Nucleotide& operator[](size_t i);
    size_t getLength();


private:
    Nucleotide** nucleotides;
    size_t size;

};
#endif //DNA_DNASEQUENCE_H
