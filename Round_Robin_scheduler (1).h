#ifndef ROUND_ROBIN_SCHEDULER_H
#define ROUND_ROBIN_SCHEDULER_H

#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int processTime;
    Node* next;
};

// Class for Round-Robin Scheduler
class RoundRobinScheduler {
private:
    Node* tail;  // Tail pointer for circular linked list
    int timeSlice;  // Fixed time slice

public:
    RoundRobinScheduler(int slice);
    void insertProcess(int time);
    void execute();
    void displayProcesses();
    ~RoundRobinScheduler(); // Destructor to free memory
};

#endif // ROUND_ROBIN_SCHEDULER_H
