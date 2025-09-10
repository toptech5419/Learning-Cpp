#include <iostream>
#include <limits>
#include <string>

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
    cout << "2. Store result in memory (MS)" << endl;
    cout << "3. Recall from memory (MR)" << endl;
    cout << "4. Clear memory (MC)" << endl;
    cout << "5. Show memory status" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    double num1, num2, result;
    char operation;
    int choice;
    Memory memory;
    
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
                cout << "Enter value to store in memory: ";
                double value;
                while (!(cin >> value)) {
                    cout << "Invalid input! Please enter a number: ";
                    clearInput();
                }
                memory.store(value);
                break;
            }
            case 3:
                memory.recall();
                break;
            case 4:
                memory.clear();
                break;
            case 5:
                memory.displayStatus();
                break;
            case 6:
                cout << "Thank you for using the calculator!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select 1-6." << endl;
                break;
        }
        
    } while (choice != 6);
    
    return 0;
}