//
// Created by mahmood on 11/1/20.
//

#include "DnaSequenceMinipulation.h"
#include "Nucleotide.h"

#include "DnaSequencePairing.h"

using namespace std;

std::string DnaSequencePairing::Pairing(DnaSequence &dnaSequence) {
    string newDna;
    char temp;
    for (size_t i= 0; i < dnaSequence.getLength() ; i++) {
        temp = dnaSequence[i].getType();
        if (temp == 'G')
            newDna += 'C';
        else if (temp == 'T')
            newDna += 'A';
        else if (temp == 'C')
            newDna += 'G';
        else
            newDna += 'T';

    }
    reverseStr(newDna);

    return newDna;
}


void DnaSequencePairing::reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}