#ifndef PARSER_H
#define PARSER_H

#include <string>

class Parser {
public:
    Parser(int argc, char* argv[]);
    std::string getAlgorithm();

private:
    std::string algorithm;
};

#endif // PARSER_H
