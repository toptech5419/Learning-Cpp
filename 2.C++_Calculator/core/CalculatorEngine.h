#ifndef CALCULATORENGINE_H
#define CALCULATORENGINE_H

#include "Memory.h"
#include "TrigCalculator.h"
#include <string>

class CalculatorEngine {
private:
    Memory memory;
    TrigCalculator trigCalc;
    double lastResult;
    
public:
    CalculatorEngine();
    
    // Basic arithmetic operations
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double performBasicOperation(double a, double b, char operation);
    
    // Trigonometric operations
    double performTrigOperation(const std::string& function, double value);
    void setAngleMode(bool degrees);
    bool getAngleMode();
    std::string getAngleModeString();
    
    // Memory operations
    void storeInMemory(double value);
    double recallFromMemory();
    void clearMemory();
    bool hasMemoryValue();
    void showMemoryStatus();
    
    // Result management
    double getLastResult();
    void setLastResult(double result);
    
    // Validation
    bool isValidOperation(char operation);
    bool isValidTrigFunction(const std::string& function);
};

#endif // CALCULATORENGINE_H