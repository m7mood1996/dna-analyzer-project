//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCEFILE_H
#define DNA_DNASEQUENCEFILE_H

#include "DnaSequence.h"

class DnaSequenceFile {
public:
    static DnaSequence *ReadSequenceFromFile(const char *filePath, std::string name);
    static bool WriteSequencetoFile(const DnaSequence& dnaSequence, const char * filePath);

};


#endif //DNA_DNASEQUENCEFILE_H
