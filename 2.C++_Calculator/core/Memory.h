#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>

class Memory {
private:
    double storedValue;
    bool hasValue;
    
public:
    Memory();
    void store(double value);
    double recall();
    void clear();
    bool isEmpty();
    void displayStatus();
};

#endif // MEMORY_H