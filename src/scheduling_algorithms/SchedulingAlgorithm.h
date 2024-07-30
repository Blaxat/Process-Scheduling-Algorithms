#ifndef SCHEDULING_ALGORITHM_H
#define SCHEDULING_ALGORITHM_H

class SchedulingAlgorithm {
public:
    virtual ~SchedulingAlgorithm() = default;
    virtual void run() = 0;
};

#endif // SCHEDULING_ALGORITHM_H
