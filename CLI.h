//
// Created by mahmood on 11/11/20.
//

#ifndef DNA_CLI_H
#define DNA_CLI_H
#include <vector>
class DnaSequence;
class CLI {
public:
    static void CLI_connect_to_system();

private:
    static size_t number_from_string(std::string num);
    static bool newSequnce(std::vector<std::string>& user_input, std::vector<DnaSequence *>& dnaSequnces );
    static bool loadSequnce(std::vector<std::string>& user_input, std::vector<DnaSequence *>& dnaSequnces);
    static bool dupSequnce(std::vector<std::string>& user_input, std::vector<DnaSequence *>& dnaSequnces);

    };


#endif //DNA_CLI_H
