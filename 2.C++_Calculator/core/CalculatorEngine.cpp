#include "CalculatorEngine.h"
#include <iostream>

using namespace std;

CalculatorEngine::CalculatorEngine() {
    lastResult = 0.0;
}

// Basic arithmetic operations
double CalculatorEngine::add(double a, double b) {
    return a + b;
}

double CalculatorEngine::subtract(double a, double b) {
    return a - b;
}

double CalculatorEngine::multiply(double a, double b) {
    return a * b;
}

double CalculatorEngine::divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

double CalculatorEngine::performBasicOperation(double a, double b, char operation) {
    double result = 0.0;
    
    switch (operation) {
        case '+':
            result = add(a, b);
            break;
        case '-':
            result = subtract(a, b);
            break;
        case '*':
            result = multiply(a, b);
            break;
        case '/':
            result = divide(a, b);
            break;
        default:
            cout << "Invalid operation!" << endl;
            return 0;
    }
    
    lastResult = result;
    return result;
}

// Trigonometric operations
double CalculatorEngine::performTrigOperation(const string& function, double value) {
    double result = 0.0;
    
    if (function == "sin" || function == "sine") {
        result = trigCalc.sine(value);
    } else if (function == "cos" || function == "cosine") {
        result = trigCalc.cosine(value);
    } else if (function == "tan" || function == "tangent") {
        result = trigCalc.tangent(value);
    } else if (function == "asin" || function == "arcsine") {
        result = trigCalc.arcsine(value);
    } else if (function == "acos" || function == "arccosine") {
        result = trigCalc.arccosine(value);
    } else if (function == "atan" || function == "arctangent") {
        result = trigCalc.arctangent(value);
    } else {
        cout << "Invalid trigonometric function!" << endl;
        return 0;
    }
    
    lastResult = result;
    return result;
}

void CalculatorEngine::setAngleMode(bool degrees) {
    trigCalc.setAngleMode(degrees);
}

bool CalculatorEngine::getAngleMode() {
    return trigCalc.getAngleMode();
}

string CalculatorEngine::getAngleModeString() {
    return trigCalc.getAngleMode() ? "Degrees" : "Radians";
}

// Memory operations
void CalculatorEngine::storeInMemory(double value) {
    memory.store(value);
}

double CalculatorEngine::recallFromMemory() {
    return memory.recall();
}

void CalculatorEngine::clearMemory() {
    memory.clear();
}

bool CalculatorEngine::hasMemoryValue() {
    return !memory.isEmpty();
}

void CalculatorEngine::showMemoryStatus() {
    memory.displayStatus();
}

// Result management
double CalculatorEngine::getLastResult() {
    return lastResult;
}

void CalculatorEngine::setLastResult(double result) {
    lastResult = result;
}

// Validation
bool CalculatorEngine::isValidOperation(char operation) {
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/');
}

bool CalculatorEngine::isValidTrigFunction(const string& function) {
    return (function == "sin" || function == "cos" || function == "tan" ||
            function == "asin" || function == "acos" || function == "atan" ||
            function == "sine" || function == "cosine" || function == "tangent" ||
            function == "arcsine" || function == "arccosine" || function == "arctangent");
}