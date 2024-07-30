#include "Parser.h"
#include <cstring>

Parser::Parser(int argc, char* argv[]) {
    if (argc > 1) {
        algorithm = argv[1];
    } else {
        algorithm = "";
    }
}

std::string Parser::getAlgorithm() {
    return algorithm;
}
