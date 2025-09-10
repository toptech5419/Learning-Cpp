#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

class Memory {
private:
    double storedValue;
    bool hasValue;
    
public:
    Memory() {
        storedValue = 0.0;
        hasValue = false;
    }
    
    void store(double value) {
        storedValue = value;
        hasValue = true;
        cout << "Value " << value << " stored in memory." << endl;
    }
    
    double recall() {
        if (hasValue) {
            cout << "Recalled from memory: " << storedValue << endl;
            return storedValue;
        } else {
            cout << "Memory is empty!" << endl;
            return 0.0;
        }
    }
    
    void clear() {
        storedValue = 0.0;
        hasValue = false;
        cout << "Memory cleared." << endl;
    }
    
    bool isEmpty() {
        return !hasValue;
    }
    
    void displayStatus() {
        if (hasValue) {
            cout << "Memory contains: " << storedValue << endl;
        } else {
            cout << "Memory is empty." << endl;
        }
    }
};

class TrigCalculator {
private:
    bool useDegrees;
    
    double degreesToRadians(double degrees) {
        return degrees * M_PI / 180.0;
    }
    
    double radiansToDegrees(double radians) {
        return radians * 180.0 / M_PI;
    }
    
public:
    TrigCalculator() {
        useDegrees = true;
    }
    
    void setAngleMode(bool degrees) {
        useDegrees = degrees;
        cout << "Angle mode set to: " << (degrees ? "Degrees" : "Radians") << endl;
    }
    
    bool getAngleMode() {
        return useDegrees;
    }
    
    double sine(double angle) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return sin(angle);
    }
    
    double cosine(double angle) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return cos(angle);
    }
    
    double tangent(double angle) {
        if (useDegrees) {
            angle = degreesToRadians(angle);
        }
        return tan(angle);
    }
    
    double arcsine(double value) {
        if (value < -1 || value > 1) {
            cout << "Error: Domain error for arcsin! Input must be between -1 and 1." << endl;
            return 0;
        }
        double result = asin(value);
        return useDegrees ? radiansToDegrees(result) : result;
    }
    
    double arccosine(double value) {
        if (value < -1 || value > 1) {
            cout << "Error: Domain error for arccos! Input must be between -1 and 1." << endl;
            return 0;
        }
        double result = acos(value);
        return useDegrees ? radiansToDegrees(result) : result;
    }
    
    double arctangent(double value) {
        double result = atan(value);
        return useDegrees ? radiansToDegrees(result) : result;
    }
    
    void displayAngleMode() {
        cout << "Current angle mode: " << (useDegrees ? "Degrees" : "Radians") << endl;
    }
};

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMenu() {
    cout << "\n=== Calculator Menu ===" << endl;
    cout << "1. Basic calculation (+, -, *, /)" << endl;
    cout << "2. Trigonometric functions" << endl;
    cout << "3. Store result in memory (MS)" << endl;
    cout << "4. Recall from memory (MR)" << endl;
    cout << "5. Clear memory (MC)" << endl;
    cout << "6. Show memory status" << endl;
    cout << "7. Toggle angle mode (Degrees/Radians)" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose an option: ";
}

void showTrigMenu() {
    cout << "\n=== Trigonometric Functions ===" << endl;
    cout << "1. Sine (sin)" << endl;
    cout << "2. Cosine (cos)" << endl;
    cout << "3. Tangent (tan)" << endl;
    cout << "4. Arcsine (asin)" << endl;
    cout << "5. Arccosine (acos)" << endl;
    cout << "6. Arctangent (atan)" << endl;
    cout << "7. Back to main menu" << endl;
    cout << "Choose a function: ";
}

int main() {
    double num1, num2, result;
    char operation;
    int choice;
    Memory memory;
    TrigCalculator trigCalc;
    
    cout << "=== C++ Calculator with Memory ===" << endl;
    
    do {
        showMenu();
        while (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number: ";
            clearInput();
        }
        
        switch (choice) {
            case 1: {
                cout << "\nEnter first number (or 'M' to use memory): ";
                string input;
                cin >> input;
                
                if (input == "M" || input == "m") {
                    if (!memory.isEmpty()) {
                        num1 = memory.recall();
                    } else {
                        cout << "Memory is empty! Enter a number: ";
                        while (!(cin >> num1)) {
                            cout << "Invalid input! Please enter a number: ";
                            clearInput();
                        }
                    }
                } else {
                    num1 = stod(input);
                }
                
                cout << "Enter operation (+, -, *, /): ";
                cin >> operation;
                
                cout << "Enter second number (or 'M' to use memory): ";
                cin >> input;
                
                if (input == "M" || input == "m") {
                    if (!memory.isEmpty()) {
                        num2 = memory.recall();
                    } else {
                        cout << "Memory is empty! Enter a number: ";
                        while (!(cin >> num2)) {
                            cout << "Invalid input! Please enter a number: ";
                            clearInput();
                        }
                    }
                } else {
                    num2 = stod(input);
                }
                
                switch (operation) {
                    case '+':
                        result = add(num1, num2);
                        cout << num1 << " + " << num2 << " = " << result << endl;
                        break;
                    case '-':
                        result = subtract(num1, num2);
                        cout << num1 << " - " << num2 << " = " << result << endl;
                        break;
                    case '*':
                        result = multiply(num1, num2);
                        cout << num1 << " * " << num2 << " = " << result << endl;
                        break;
                    case '/':
                        result = divide(num1, num2);
                        if (num2 != 0) {
                            cout << num1 << " / " << num2 << " = " << result << endl;
                        }
                        break;
                    default:
                        cout << "Invalid operation! Please use +, -, *, or /" << endl;
                        break;
                }
                break;
            }
            case 2: {
                int trigChoice;
                double angle, value, trigResult;
                
                do {
                    showTrigMenu();
                    trigCalc.displayAngleMode();
                    while (!(cin >> trigChoice)) {
                        cout << "Invalid input! Please enter a number: ";
                        clearInput();
                    }
                    
                    switch (trigChoice) {
                        case 1:
                            cout << "Enter angle: ";
                            while (!(cin >> angle)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.sine(angle);
                            cout << "sin(" << angle << ") = " << trigResult << endl;
                            break;
                        case 2:
                            cout << "Enter angle: ";
                            while (!(cin >> angle)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.cosine(angle);
                            cout << "cos(" << angle << ") = " << trigResult << endl;
                            break;
                        case 3:
                            cout << "Enter angle: ";
                            while (!(cin >> angle)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.tangent(angle);
                            cout << "tan(" << angle << ") = " << trigResult << endl;
                            break;
                        case 4:
                            cout << "Enter value (-1 to 1): ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.arcsine(value);
                            if (value >= -1 && value <= 1) {
                                cout << "asin(" << value << ") = " << trigResult << endl;
                            }
                            break;
                        case 5:
                            cout << "Enter value (-1 to 1): ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.arccosine(value);
                            if (value >= -1 && value <= 1) {
                                cout << "acos(" << value << ") = " << trigResult << endl;
                            }
                            break;
                        case 6:
                            cout << "Enter value: ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = trigCalc.arctangent(value);
                            cout << "atan(" << value << ") = " << trigResult << endl;
                            break;
                        case 7:
                            cout << "Returning to main menu..." << endl;
                            break;
                        default:
                            cout << "Invalid choice! Please select 1-7." << endl;
                            break;
                    }
                } while (trigChoice != 7);
                break;
            }
            case 3: {
                cout << "Enter value to store in memory: ";
                double value;
                while (!(cin >> value)) {
                    cout << "Invalid input! Please enter a number: ";
                    clearInput();
                }
                memory.store(value);
                break;
            }
            case 4:
                memory.recall();
                break;
            case 5:
                memory.clear();
                break;
            case 6:
                memory.displayStatus();
                break;
            case 7:
                trigCalc.setAngleMode(!trigCalc.getAngleMode());
                break;
            case 8:
                cout << "Thank you for using the calculator!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-8." << endl;
                break;
        }
        
    } while (choice != 8);
    
    return 0;
}