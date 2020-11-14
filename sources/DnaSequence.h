//
// Created by mahmood on 10/21/20.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H


#include <string>
class Nucleotide;

class DnaSequence {
    friend class DnaSequenceMinipulation;
public:
    DnaSequence(const char *str);
    DnaSequence(const std::string& string );
    DnaSequence(const DnaSequence& dnaSequence);
    virtual ~DnaSequence();
    void at(size_t, char nuc);
    friend std::ostream& operator<<(std::ostream& os, const DnaSequence& dnaSequence);
    DnaSequence& operator=(const DnaSequence& other);
    DnaSequence& operator=(const char* other);
    DnaSequence& operator=(const std::string& other);
    bool operator==(const DnaSequence& other);
    bool operator!=(const DnaSequence& other);
    const Nucleotide& operator[](size_t i) const;
    size_t getLength() const;

private:
    Nucleotide* nucleotides;
    size_t size;

};
#endif //DNA_DNASEQUENCE_H
