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

string DnaSequenceFile::ReadSequenceFromFile(const char* filePath) {

    ifstream myfile;
    myfile.open(filePath);
    if (myfile.fail())
        throw runtime_error("unable to open file");
    string dna;
    getline(myfile, dna);
    myfile.close();
    return dna;
}

bool DnaSequenceFile::WriteSequencetoFile(const DnaSequence& dnaSequence, const string &file_name) {
    string the_file = "/home/mahmood/Desktop/dna-analyzer-project-m7mood1996/dnaSaveFile/" + file_name +  ".rawdna";
    ofstream MyFile(the_file.c_str());
    if (MyFile.fail())
        throw runtime_error("unable to open file");
    for (size_t i=0;i<dnaSequence.getLength();i++)
        MyFile << dnaSequence[i];
    MyFile.close();
    return true;
}
