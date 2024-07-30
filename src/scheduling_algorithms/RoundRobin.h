#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "SchedulingAlgorithm.h"
#include <iostream>

class RoundRobin : public SchedulingAlgorithm {
public:
    RoundRobin();
    void run() override;
};

#endif // ROUND_ROBIN_H
