//
// Created by mahmood on 11/11/20.
//
#include <iostream>
#include <cmath>

#include <string>
#include <cstdio>
#include "DnaSequence.h"
#include "DnaSequenceDecorator.h"
#include "DnaSequenceFile.h"
#include "DnaSequenceSlicing.h"
#include "DnaSequencePairing.h"
#include "DnaSequenceSearch.h"
#include "CLI.h"

using namespace std;


size_t CLI::number_from_string(string num){
    size_t my_number = 0;
    size_t index =0;
    while (index <num.length()){
        my_number = num[index] -48;
        if (index != num.length() -1)
            my_number *= 10;
        index +=1;
    }
    return my_number;
}


bool CLI::newSequnce(vector<string>& user_input, vector<DnaSequenceDecorator *>& dnaSequnces ){
    string newName;
    if ( user_input.back()[0] == '@') {

        newName = user_input.back().substr(1);
        user_input.pop_back();
    }
    else{
        char length[50];
        try {
            sprintf(length, "%lu", dnaSequnces.size());
        }
        catch (exception  &ex) {
            return false;
        }
        newName = "seq" + string(length);
    }

    DnaSequenceDecorator *d;
    d = new DnaSequenceDecorator(user_input.back(),newName,dnaSequnces.size());
    dnaSequnces.push_back(d);
    cout << "[" << dnaSequnces.size()-1 << "] " << *(dnaSequnces.back()) <<" " << dnaSequnces.back()->getName();
    return true;

}
bool CLI::loadSequnce(vector<string>& user_input, vector<DnaSequenceDecorator *>& dnaSequnces){
    string newName;
    if ( user_input.back()[0] == '@') {

        newName = user_input.back().substr(1);
        user_input.pop_back();
    }
    else{
        char length[50];
        try {
            sprintf(length, "%lu", dnaSequnces.size());
        }
        catch (exception  &ex) {
            return false;
        }
        newName = "seq" + string(length);
    }

    DnaSequenceDecorator *d;
    d = (DnaSequenceDecorator *)DnaSequenceFile::ReadSequenceFromFile(user_input.back().c_str());
    d->setName( newName);
    d->setid( dnaSequnces.size());
    dnaSequnces.push_back(d);
    cout << "[" << dnaSequnces.size()-1 << "] " << *dnaSequnces.back() << " " << dnaSequnces.back()->getName();
    return true;

}

bool CLI::dupSequnce(vector<string>& user_input, vector<DnaSequenceDecorator *>& dnaSequnces){
    string newName;
    std::size_t id = 0;
    if ( user_input.back()[0] == '@') {

        newName = user_input.back().substr(1);
        user_input.pop_back();


    }

    else{
        string str_id = user_input.back().substr(1);
        id = number_from_string(str_id);
        if (id >= dnaSequnces.size())
            return false;

        newName = dnaSequnces[id]->getName() + "_1";
        for(size_t k = id; k < dnaSequnces.size();k++){
            if (dnaSequnces[k]->getName() == newName)
                newName = dnaSequnces[k]->getName() + "_1";
        }

    }

    DnaSequenceDecorator *d;
    d = new DnaSequenceDecorator(*dnaSequnces[id],newName,dnaSequnces.size());
    dnaSequnces.push_back(d);
    cout << "[" << dnaSequnces.size()-1 << "] " << *dnaSequnces.back() << " " << dnaSequnces.back()->getName();
    return true;
}


void CLI::CLI_connect_to_system() {
    vector<DnaSequenceDecorator *> dnaSequnces;
    string delimiter = " ";
    std::size_t i = 0;
    size_t pos = 0;
    string token;
    string command;
    vector<string> tokens;
    while (true) {
        cout << "> cmd >> ";
        string line;

        getline(cin, line);


        while ((pos = line.find(delimiter)) != string::npos) {
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
            i++;
        }
        tokens.push_back(line);

        if (tokens.at(0) == "new")
            newSequnce(tokens, dnaSequnces);

        if (tokens.at(0) == "load")
            loadSequnce(tokens, dnaSequnces);

        if (tokens.at(0) == "dup")
            dupSequnce(tokens, dnaSequnces);
        if (tokens.at(0) == "end")
            break;
        cout << endl;

        line = "";
        tokens.clear();
    }

}


