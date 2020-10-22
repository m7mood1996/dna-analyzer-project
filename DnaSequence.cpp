//
// Created by mahmood on 10/21/20.
//

#include <cstring>
#include <iostream>
#include <typeinfo>


#include "DnaSequence.h"

#include "Nucleotide.h"
#include "A.h"
#include "C.h"
#include "G.h"
#include "T.h"



DnaSequence::DnaSequence(const char *str) {

    size_t n = std::strlen(str);
    size = n;
    nucleotides = new Nucleotide*[n];

    for (size_t i =0; i < n;i++){
        switch (str[i]) {
            case 'A':
                nucleotides[i] = new A();
                break;
            case 'G':
                nucleotides[i] = new G();
                break;
            case 'C':
                nucleotides[i] = new C();
                break;
            case 'T':
                nucleotides[i] = new T();
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }


}


DnaSequence::DnaSequence(const std::string& string) {
    size_t n = string.length();
    size = n;
    nucleotides = new Nucleotide*[n];

    for (size_t i =0; i < n;i++){
        switch (string[i]) {
            case 'A':
                nucleotides[i] = new A();
                break;
            case 'G':
                nucleotides[i] = new G();
                break;
            case 'C':
                nucleotides[i] = new C();
                break;
            case 'T':
                nucleotides[i] = new T();
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }

}

DnaSequence::DnaSequence(const DnaSequence &dnaSequence) {
    size = dnaSequence.size;
    nucleotides = new Nucleotide*[size];
    for (size_t i=0;i<size;i++) {
        if (typeid(*dnaSequence.nucleotides[i])== typeid(A) )
            nucleotides[i] = new A();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(C) )
            nucleotides[i] = new C();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(G) )
            nucleotides[i] = new G();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(T) )
            nucleotides[i] = new T();
        else
            throw std::exception();
    }
}



DnaSequence::~DnaSequence() {
    for (size_t i =0;i<size;i++)
        delete nucleotides[i];
    delete [] nucleotides;

}

std::ostream& operator<<(std::ostream& os,const DnaSequence &dnaSequence) {
    for (size_t i =0;i<dnaSequence.size;i++)
        os << *dnaSequence.nucleotides[i];
    return os;
}

DnaSequence &DnaSequence::operator=(const DnaSequence &dnaSequence) {

    size = dnaSequence.size;
    nucleotides = new Nucleotide*[size];
    for (size_t i=0;i<size;i++) {
        if (typeid(*dnaSequence.nucleotides[i])== typeid(A) )
            nucleotides[i] = new A();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(C) )
            nucleotides[i] = new C();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(G) )
            nucleotides[i] = new G();
        else if (typeid(*dnaSequence.nucleotides[i])== typeid(T) )
            nucleotides[i] = new T();
        else
            throw std::exception();
    }
    return *this;
}

DnaSequence &DnaSequence::operator=(const char *other) {

    size_t n = std::strlen(other);
    size = n;
    nucleotides = new Nucleotide*[n];

    for (size_t i =0; i < n;i++){
        switch (other[i]) {
            case 'A':
                nucleotides[i] = new A();
                break;
            case 'G':
                nucleotides[i] = new G();
                break;
            case 'C':
                nucleotides[i] = new C();
                break;
            case 'T':
                nucleotides[i] = new T();
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }

    return *this;
}

DnaSequence &DnaSequence::operator=(const std::string &other) {
    size_t n = other.length();
    size = n;
    nucleotides = new Nucleotide*[n];

    for (size_t i =0; i < n;i++){
        switch (other[i]) {
            case 'A':
                nucleotides[i] = new A();
                break;
            case 'G':
                nucleotides[i] = new G();
                break;
            case 'C':
                nucleotides[i] = new C();
                break;
            case 'T':
                nucleotides[i] = new T();
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }

    return *this;

}

bool DnaSequence::operator==(const DnaSequence &other) {
    if (size != other.size)
        return false;
    for (size_t i = 0; i < size ; ++i) {
        if (typeid(*nucleotides[i]) != typeid(*other.nucleotides[i]))
            return false;

    }
    return true;
}

bool DnaSequence::operator!=(const DnaSequence &other) {
    return !(*this == other);
}

Nucleotide &DnaSequence::operator[](size_t i) {
    if (i > size)
        throw std::out_of_range("invalid index");
    return *nucleotides[i];
}

size_t DnaSequence::getLength() {
    return size;
}


