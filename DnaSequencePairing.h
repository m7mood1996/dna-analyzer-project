//
// Created by mahmood on 11/1/20.
//

#ifndef DNA_DNASEQUENCEPAIRING_H
#define DNA_DNASEQUENCEPAIRING_H

class DnaSequence;
class DnaSequencePairing {
    private:
    static void reverseStr(std::string& str);

public:
    static DnaSequence Pairing(DnaSequence& dnaSequence);

};


#endif //DNA_DNASEQUENCEPAIRING_H
