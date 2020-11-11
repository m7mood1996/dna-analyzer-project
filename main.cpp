#include <iostream>



#include "DnaSequence.h"
#include "DnaSequenceFile.h"
#include "DnaSequenceSlicing.h"
#include "DnaSequencePairing.h"
#include "DnaSequenceSearch.h"
using namespace std;

int main() {

    const char * str = "AGCTGGTCA";
    DnaSequence d(str);
    DnaSequence d2("G");
    //DnaSequenceFile::WriteSequencetoFile(d);
    cout << d<<endl;

    cout << DnaSequenceSearch::Count(d,d2)<<endl;
    return 0;
}
