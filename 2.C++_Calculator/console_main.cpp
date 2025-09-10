#include <iostream>
#include <limits>
#include <string>
#include "core/CalculatorEngine.h"

using namespace std;

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
    CalculatorEngine engine;
    double num1, num2, result;
    char operation;
    int choice;
    
    cout << "=== C++ Calculator with Memory (Using Core Engine) ===" << endl;
    
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
                    if (engine.hasMemoryValue()) {
                        num1 = engine.recallFromMemory();
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
                    if (engine.hasMemoryValue()) {
                        num2 = engine.recallFromMemory();
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
                
                result = engine.performBasicOperation(num1, num2, operation);
                cout << num1 << " " << operation << " " << num2 << " = " << result << endl;
                break;
            }
            case 2: {
                int trigChoice;
                double angle, value, trigResult;
                
                do {
                    showTrigMenu();
                    cout << "Current angle mode: " << engine.getAngleModeString() << endl;
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
                            trigResult = engine.performTrigOperation("sin", angle);
                            cout << "sin(" << angle << ") = " << trigResult << endl;
                            break;
                        case 2:
                            cout << "Enter angle: ";
                            while (!(cin >> angle)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = engine.performTrigOperation("cos", angle);
                            cout << "cos(" << angle << ") = " << trigResult << endl;
                            break;
                        case 3:
                            cout << "Enter angle: ";
                            while (!(cin >> angle)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = engine.performTrigOperation("tan", angle);
                            cout << "tan(" << angle << ") = " << trigResult << endl;
                            break;
                        case 4:
                            cout << "Enter value (-1 to 1): ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = engine.performTrigOperation("asin", value);
                            cout << "asin(" << value << ") = " << trigResult << endl;
                            break;
                        case 5:
                            cout << "Enter value (-1 to 1): ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = engine.performTrigOperation("acos", value);
                            cout << "acos(" << value << ") = " << trigResult << endl;
                            break;
                        case 6:
                            cout << "Enter value: ";
                            while (!(cin >> value)) {
                                cout << "Invalid input! Please enter a number: ";
                                clearInput();
                            }
                            trigResult = engine.performTrigOperation("atan", value);
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
                engine.storeInMemory(value);
                break;
            }
            case 4:
                engine.recallFromMemory();
                break;
            case 5:
                engine.clearMemory();
                break;
            case 6:
                engine.showMemoryStatus();
                break;
            case 7:
                engine.setAngleMode(!engine.getAngleMode());
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