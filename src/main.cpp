#include <iostream>
#include "scheduling_algorithms/RoundRobin.h"
#include "utils/Parser.h"

int main(int argc, char* argv[]) {
    Parser parser(argc, argv);
    std::string algorithm = parser.getAlgorithm();
    
    SchedulingAlgorithm* scheduler = nullptr;
    if (algorithm == "roundrobin") {
        scheduler = new RoundRobin();
    } 
    else {
        std::cerr << "Unknown algorithm: " << algorithm << std::endl;
        return 1;
    }

    scheduler->run();
    delete scheduler;

    return 0;
}
