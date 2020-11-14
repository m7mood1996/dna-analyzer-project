//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCEFILE_H
#define DNA_DNASEQUENCEFILE_H

#include "DnaSequence.h"

class DnaSequenceFile {
public:
    static std::string ReadSequenceFromFile(const char *filePath);
    static bool WriteSequencetoFile(const DnaSequence& dnaSequence,const std::string& file_name);

};


#endif //DNA_DNASEQUENCEFILE_H
