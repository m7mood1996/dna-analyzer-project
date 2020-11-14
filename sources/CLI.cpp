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
#include "DnaFactory.h"
#include "NewDna.h"
#include "loadDna.h"
#include "DnaSequenceMinipulation.h"
#include "DnaSequencePairing.h"
#include "DnaSequenceSearch.h"
#include "CLI.h"

using namespace std;


size_t CLI::number_from_string(string num){
    size_t my_number = 0;
    size_t index =0;
    while (index <num.length()){
        my_number += num[index] -48;
        if (index != num.length() -1)
            my_number *= 10;
        index +=1;
    }
    return my_number;
}

bool CLI::newSequnce(vector<string>& user_input, vector<DnaSequenceDecorator *>& dnaSequnces ){
    string newName;
    DnaFactory *dnaFactory = new NewDna();
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
    d = dnaFactory->creat(user_input.back(),newName,dnaSequnces.size());
    dnaSequnces.push_back(d);
    cout << "[" << dnaSequnces.size()-1 << "] " << *(dnaSequnces.back()) <<" " << dnaSequnces.back()->getName();
    delete dnaFactory;
    return true;

}
bool CLI::loadSequnce(vector<string>& user_input, vector<DnaSequenceDecorator *>& dnaSequnces){
    DnaFactory * dnaFactory = new loadDna();
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
    d = dnaFactory->creat(user_input.back(), newName,dnaSequnces.size());
    dnaSequnces.push_back(d);
    cout << "[" << dnaSequnces.size()-1 << "] " << *dnaSequnces.back() << " " << dnaSequnces.back()->getName();
    delete dnaFactory;
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
        if (tokens.at(0) == "list")
            listSequnce(dnaSequnces);
        if (tokens.at(0) == "save")
            saveSequnce(tokens,dnaSequnces);
        if (tokens.at(0) == "slice")
            sliceSequnce(tokens,dnaSequnces);
        if (tokens.at(0) == "replace")
            replaceSequnce(tokens,dnaSequnces);
        if (tokens.at(0) == "concat")
            concatSequnce(tokens,dnaSequnces);
        cout << endl;

        line = "";
        tokens.clear();
    }
    for (std::size_t k=0; k < dnaSequnces.size();k++)
        delete dnaSequnces[k];

}

void CLI::listSequnce( std::vector<DnaSequenceDecorator *> &dnaSequences) {
    for (std::size_t index = 0; index < dnaSequences.size();index++){
        std::cout <<"["<<dnaSequences[index]->getId() << "] "<< *dnaSequences[index] <<" " << dnaSequences[index]->getName() << std::endl;
    }

}

bool CLI::saveSequnce(vector<string>& user_input, std::vector<DnaSequenceDecorator *> &dnaSequences) {

    string str_id = user_input.back().substr(1);
    size_t id = number_from_string(str_id);
    std::size_t i = 0;
    DnaSequenceDecorator *d = NULL;
    for (; i < dnaSequences.size(); i++) {
        if (id == dnaSequences[i]->getId())
            d = dnaSequences[i];
    }
    if (d == NULL) {
        cout << "this id not available chick list command " << endl;
        return false;
    }

    DnaSequenceFile::WriteSequencetoFile(*d,d->getName());
    return true;

}


bool CLI::sliceSequnce(vector<string>& user_input, std::vector<DnaSequenceDecorator *> &dnaSequences){
    string newName;
    char s_num[20];
    int the_s_number = 0;
    size_t start_ind;
    size_t end_ind;
    size_t id;
    std::size_t i=0;
    DnaSequenceDecorator *d = NULL;


    if ( user_input.size() == 6 && user_input.back() == "@@") {
        user_input.pop_back();
        if(user_input.back()[0] != ':') {
            cout << "syntax error" << endl;
            return false;
        }
        user_input.pop_back();
        try {
            end_ind = number_from_string(user_input.back());
            user_input.pop_back();
            start_ind = number_from_string(user_input.back());
            user_input.pop_back();
            id = number_from_string(user_input.back().substr(1));
        }
        catch (exception &ex) {
            cout << "syntax error" << endl;
            return false;
        }

        for (;i<dnaSequences.size();i++){
            if (id == dnaSequences[i]->getId())
                d = dnaSequences[i];
        }
        if (d == NULL) {
            cout << "this id not available chick list command " << endl;
            return false;
        }
        newName = d->getName() + "_s1";
        the_s_number = 1;
        for (;i<dnaSequences.size();i++){
            if (newName == dnaSequences[i]->getName())
                the_s_number += 1;

            sprintf(s_num,"%d",the_s_number);
            newName = newName.substr(0,newName.length()-1)+ string(s_num);
        }
        DnaFactory *factory = new NewDna();
        DnaSequenceDecorator *newDna = factory->creat(DnaSequenceMinipulation::Slice(*d, start_ind, end_ind), newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        delete  factory;
        std::cout <<"["<<newDna->getId() << "] "<< *newDna <<" " << newDna->getName() << std::endl;
        return true;
    }
    else if(user_input.back()[0] == '@') {
        newName = user_input.back().substr(1);
        user_input.pop_back();
        if(user_input.back()[0] != ':') {
            cout << "syntax error" << endl;
            return false;
        }
        user_input.pop_back();
        try {
            end_ind = number_from_string(user_input.back());
            user_input.pop_back();
            start_ind = number_from_string(user_input.back());
            user_input.pop_back();
            id = number_from_string(user_input.back().substr(1));
        }
        catch (exception &ex) {
            cout << "syntax error" << endl;
            return false;
        }

        for (;i<dnaSequences.size();i++){
            if (id == dnaSequences[i]->getId())
                d = dnaSequences[i];
        }
        if (d == NULL) {
            cout << "this id not available chick list command " << endl;
            return false;
        }
        DnaFactory *factory = new NewDna();
        DnaSequenceDecorator *newDna = factory->creat(DnaSequenceMinipulation::Slice(*d, start_ind, end_ind), newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        delete  factory;
        std::cout <<"["<<newDna->getId() << "] "<< *newDna <<" " << newDna->getName() << std::endl;
        return true;
    }

    else if(user_input.back()[0] == ':') {
        cout << "syntax error" << endl;
        return false;
    }

    if (user_input.size() != 4){
        cout << "syntax error" << endl;
        return false;
    }
    else{
        newName = "short_seq";
        try {
            end_ind = number_from_string(user_input.back());
            user_input.pop_back();
            start_ind = number_from_string(user_input.back());
            user_input.pop_back();
            id = number_from_string(user_input.back().substr(1));
        }
        catch (exception &ex) {
            cout << "syntax error" << endl;
            return false;
        }

        for (;i<dnaSequences.size();i++){
            if (id == dnaSequences[i]->getId())
                d = dnaSequences[i];
        }
        if (d == NULL) {
            cout << "this id not available chick list command " << endl;
            return false;
        }
        DnaFactory *factory = new NewDna();
        DnaSequenceDecorator *newDna = factory->creat(DnaSequenceMinipulation::Slice(*d, start_ind, end_ind), newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        delete  factory;
        std::cout <<"["<<newDna->getId() << "] "<< *newDna <<" " << newDna->getName() << std::endl;
        return true;
    }

}

bool CLI::replaceSequnce(std::vector<string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences) {
    string newName;
    char s_num[20];

    int the_s_number = 0;
    size_t index;
    char newNuc;
    size_t id = number_from_string(user_input.at(1).substr(1));
    std::size_t i=0;
    DnaSequenceDecorator *d = NULL;

    for (;i<dnaSequences.size();i++){
        if (id == dnaSequences[i]->getId())
            d = dnaSequences[i];
    }
    if (d == NULL){
        cout << "we cant find this id try use list command" << endl;
        return false;
    }
    DnaSequenceDecorator *newD = new DnaSequenceDecorator(*d);
    i = 2;
    while (i < user_input.size() and user_input.at(i) != ":" ){
        index = number_from_string(user_input.at(i));
        newNuc = user_input.at(i+1)[0];
        newD->at(index,newNuc);
        i+=2;
    }
    if(user_input.back() == "@@"){
        newName = d->getName() + "_r1";
        the_s_number = 1;
        for (;i<dnaSequences.size();i++){
            if (newName == dnaSequences[i]->getName())
                the_s_number += 1;

            sprintf(s_num,"%d",the_s_number);
            newName = newName.substr(0,newName.length()-1)+ string(s_num);
        }

    }
    else if (user_input.back()[0] == '@')
        newName = user_input.back().substr(1);

    else
        newName = "replaced_seq";

    newD->setid(dnaSequences.size());
    newD->setName(newName);
    dnaSequences.push_back(newD);
    std::cout <<"["<<newD->getId() << "] "<< *newD <<" " << newD->getName() << std::endl;

    return true;
}

bool CLI::concatSequnce(vector<std::string> &user_input, vector<DnaSequenceDecorator *> &dnaSequences) {
    string newName;
    char s_num[20];
    int the_s_number = 0;
    size_t start_ind;
    size_t end_ind;
    size_t id;
    std::size_t i=0;
    std::vector<std::size_t> ids_of_seq_to_concat;
    std::vector<DnaSequenceDecorator *> dnas_to_concat;
    size_t j,k;

    if ( user_input.back() == "@@") {
        user_input.pop_back();
        if (user_input.back()[0] != ':') {
            cout << "syntax error" << endl;
            return false;
        }
        user_input.pop_back();
        size_t index = user_input.size() - 1;
        for (; index >= 1; index--) {
            if (user_input.at(index)[0] != '#') {
                cout << "syntax error" << endl;
                return false;
            }
            try {
                ids_of_seq_to_concat.push_back(number_from_string(user_input.at(index).substr(1)));
            }
            catch (exception &ex) {
                cout << "syntax error" << endl;
            }
        }

        for (j = 0; j < ids_of_seq_to_concat.size(); ++j) {
            for (k = 0; k < dnaSequences.size(); ++k) {
                if (ids_of_seq_to_concat[j] == dnaSequences[k]->getId()) {
                    dnas_to_concat.push_back(dnaSequences[k]);
                    newName = ""+ dnaSequences[k]->getName() + "_" + newName;
                }
            }

        }
        newName += "c1";
        the_s_number = 1;
        for (; i < dnaSequences.size(); i++) {
            if (newName == dnaSequences[i]->getName())
                the_s_number += 1;
            sprintf(s_num, "%d", the_s_number);
            newName = newName.substr(0, newName.length() - 1) + string(s_num);
        }

        DnaSequenceDecorator *newDna = DnaSequenceMinipulation::Concat(dnas_to_concat, newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        std::cout << "[" << newDna->getId() << "] " << *newDna << " " << newDna->getName() << std::endl;
        return true;
    }
    else if(user_input.back()[0] == '@') {
        newName = user_input.back().substr(1);
        user_input.pop_back();
        if(user_input.back()[0] != ':') {
            cout << "syntax error" << endl;
            return false;
        }
        user_input.pop_back();
        size_t index = user_input.size() - 1;
        for (; index >= 1; index--) {
            if (user_input.at(index)[0] != '#') {
                cout << "syntax error" << endl;
                return false;
            }
            try {
                ids_of_seq_to_concat.push_back(number_from_string(user_input.at(index).substr(1)));
            }
            catch (exception &ex) {
                cout << "syntax error" << endl;
            }
        }

        for (j = 0; j < ids_of_seq_to_concat.size(); ++j) {
            for (k = 0; k < dnaSequences.size(); ++k) {
                if (ids_of_seq_to_concat[j] == dnaSequences[k]->getId()) {
                    dnas_to_concat.push_back(dnaSequences[k]);
                }
            }

        }

        DnaSequenceDecorator *newDna = DnaSequenceMinipulation::Concat(dnas_to_concat, newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        std::cout << "[" << newDna->getId() << "] " << *newDna << " " << newDna->getName() << std::endl;
        return true;
    }

    else if(user_input.back()[0] == ':') {
        cout << "syntax error" << endl;
        return false;
    }

    else{
        newName = "concat_seq";
        size_t index = user_input.size() - 1;
        for (; index >= 1; index--) {
            if (user_input.at(index)[0] != '#') {
                cout << "syntax error" << endl;
                return false;
            }
            try {
                ids_of_seq_to_concat.push_back(number_from_string(user_input.at(index).substr(1)));
            }
            catch (exception &ex) {
                cout << "syntax error" << endl;
            }
        }

        for (j = 0; j < ids_of_seq_to_concat.size(); ++j) {
            for (k = 0; k < dnaSequences.size(); ++k) {
                if (ids_of_seq_to_concat[j] == dnaSequences[k]->getId()) {
                    dnas_to_concat.push_back(dnaSequences[k]);
                }
            }

        }

        DnaSequenceDecorator *newDna = DnaSequenceMinipulation::Concat(dnas_to_concat, newName, dnaSequences.size());
        dnaSequences.push_back(newDna);
        std::cout << "[" << newDna->getId() << "] " << *newDna << " " << newDna->getName() << std::endl;
        return true;
    }

}





