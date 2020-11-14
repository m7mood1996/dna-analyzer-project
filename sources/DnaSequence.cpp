//
// Created by mahmood on 10/21/20.
//

#include <cstring>
#include <iostream>
#include <typeinfo>


#include "DnaSequence.h"

#include "Nucleotide.h"




DnaSequence::DnaSequence(const char *str) {

    size_t n = std::strlen(str);
    size = n;
    try {
        nucleotides = new Nucleotide[n]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
        return;

    }

    for (size_t i =0; i < n;i++){
        switch (str[i]) {
            case 'A':
                nucleotides[i].setType('A');
                break;
            case 'G':
                nucleotides[i].setType('G');
                break;
            case 'C':
                nucleotides[i] .setType('C');
                break;
            case 'T':
                nucleotides[i].setType('T');
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }


}


DnaSequence::DnaSequence(const std::string& string) {
    size_t n = string.length();
    size = n;
    try {
        nucleotides = new Nucleotide[n]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
        return;

    }

    for (size_t i =0; i < n;i++){
        switch (string[i]) {
            case 'A':
                nucleotides[i].setType('A');
                break;
            case 'G':
                nucleotides[i].setType('G');
                break;
            case 'C':
                nucleotides[i].setType('C');
                break;
            case 'T':
                nucleotides[i].setType('T');
                break;
            default:
                throw std::invalid_argument("invalid DNA Sequence");
        }

    }

}

DnaSequence::DnaSequence(const DnaSequence &dnaSequence) {
    size = dnaSequence.size;
    try {
        nucleotides = new Nucleotide[size]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
        return;

    }
    for (size_t i=0;i<size;i++) {
            nucleotides[i] = dnaSequence.nucleotides[i];
    }
}



DnaSequence::~DnaSequence() {
    delete [] nucleotides;

}

std::ostream& operator<<(std::ostream& os,const DnaSequence &dnaSequence) {
    for (size_t i =0;i<dnaSequence.size;i++)
        os << dnaSequence.nucleotides[i].getType();
    return os;
}

DnaSequence &DnaSequence::operator=(const DnaSequence &dnaSequence) {

    size = dnaSequence.size;
    try {
        nucleotides = new Nucleotide[size]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;
    }

    for (size_t i=0;i<size;i++) {
        nucleotides[i] = dnaSequence.nucleotides[i];
    } // try catch for the exceptions for all the news
    return *this;
}

DnaSequence &DnaSequence::operator=(const char *other) {

    size_t n = std::strlen(other);
    size = n;

    try {
        nucleotides = new Nucleotide[n]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;


    }

    for (size_t i =0; i < n;i++){
        switch (other[i]) {
            case 'A':
                nucleotides[i].setType('A');
                break;
            case 'G':
                nucleotides[i].setType('G');
                break;
            case 'C':
                nucleotides[i].setType('C');
                break;
            case 'T':
                nucleotides[i].setType('T');
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
    try {
        nucleotides = new Nucleotide[n]; // n * size_t
    }
    catch (std::bad_alloc& e) {
        std::cout << e.what() << std::endl;

    }

    for (size_t i =0; i < n;i++){
        switch (other[i]) {
            case 'A':
                nucleotides[i].setType('A');
                break;
            case 'G':
                nucleotides[i].setType('G');
                break;
            case 'C':
                nucleotides[i].setType('C');
                break;
            case 'T':
                nucleotides[i].setType('T');
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
        if (nucleotides[i].getType() != other.nucleotides[i].getType())
            return false;

    }
    return true;
}

bool DnaSequence::operator!=(const DnaSequence &other) {
    return !(*this == other);
}

const Nucleotide &DnaSequence::operator[](size_t i) const{
    if (i > size)
        throw std::out_of_range("invalid index");
    return nucleotides[i];
}

size_t DnaSequence::getLength() const {
    return size;
}

void DnaSequence::at(size_t i, char nuc) {
    switch (nuc) {
        case 'A':
            nucleotides[i].setType('A');
            break;
        case 'G':
            nucleotides[i].setType('G');
            break;
        case 'C':
            nucleotides[i].setType('C');
            break;
        case 'T':
            nucleotides[i].setType('T');
            break;
        default:
            throw std::invalid_argument("invalid DNA Sequence");
    }

}



