//
// Created by mahmood on 11/1/20.
//


#include <string>
#include <iostream>
#include <fstream>
#include <exception>

#include "DnaSequenceFile.h"
#include "Nucleotide.h"

using namespace std;

DnaSequence DnaSequenceFile::ReadSequenceFromFile(char* filePath) {

    ifstream myfile;
    myfile.open(filePath);
    if (myfile.fail())
        throw runtime_error("unable to open file");
    string dna;
    getline(myfile, dna);

    return DnaSequence(dna);
}

bool DnaSequenceFile::WriteSequencetoFile(const DnaSequence& dnaSequence) {

    ofstream MyFile("../filename.txt");
    if (MyFile.fail())
        throw runtime_error("unable to open file");
    for (size_t i=0;i<dnaSequence.getLength();i++)
        MyFile << dnaSequence[i];
    MyFile.close();
    return true;
}