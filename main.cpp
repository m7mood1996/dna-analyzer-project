#include <iostream>



#include "DnaSequence.h"

using namespace std;

int main() {

    const char * str = "AGCTGGTCA";
    DnaSequence d(str);
    cout << d;
    return 0;
}
