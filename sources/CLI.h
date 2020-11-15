//
// Created by mahmood on 11/11/20.
//

#ifndef DNA_CLI_H
#define DNA_CLI_H
#include <vector>
class DnaSequenceDecorator;
class CLI {
public:
    static void CLI_connect_to_system();


private:

    static size_t number_from_string(std::string num);

    static bool newSequnce(std::vector<std::string>& user_input, std::vector<DnaSequenceDecorator *>& dnaSequnces );

    static bool loadSequnce(std::vector<std::string>& user_input, std::vector<DnaSequenceDecorator *>& dnaSequnces);

    static bool dupSequnce(std::vector<std::string>& user_input, std::vector<DnaSequenceDecorator *>& dnaSequnces);

    static void listSequnce( std::vector<DnaSequenceDecorator *> &vector1);

    static bool saveSequnce(std::vector<std::string>& user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool sliceSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool replaceSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool concatSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool pairSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool renameSequnce(std::vector<std::string> user_input, std::vector<DnaSequenceDecorator *> dnaSequences);

    static bool delSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool lenSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool findSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool findAllSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);

    static bool countSequnce(std::vector<std::string> &user_input, std::vector<DnaSequenceDecorator *> &dnaSequences);
};


#endif //DNA_CLI_H
