#include "Memory.h"

using namespace std;

Memory::Memory() {
    storedValue = 0.0;
    hasValue = false;
}

void Memory::store(double value) {
    storedValue = value;
    hasValue = true;
    cout << "Value " << value << " stored in memory." << endl;
}

double Memory::recall() {
    if (hasValue) {
        cout << "Recalled from memory: " << storedValue << endl;
        return storedValue;
    } else {
        cout << "Memory is empty!" << endl;
        return 0.0;
    }
}

void Memory::clear() {
    storedValue = 0.0;
    hasValue = false;
    cout << "Memory cleared." << endl;
}

bool Memory::isEmpty() {
    return !hasValue;
}

void Memory::displayStatus() {
    if (hasValue) {
        cout << "Memory contains: " << storedValue << endl;
    } else {
        cout << "Memory is empty." << endl;
    }
}