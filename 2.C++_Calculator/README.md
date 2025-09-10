# Advanced C++ Calculator with Memory and Trigonometric Functions

## Overview
A comprehensive C++ calculator demonstrating object-oriented programming concepts through multiple classes. Features basic arithmetic, memory management, and trigonometric calculations with automatic angle conversion.

## Features
- **Basic Arithmetic**: Addition, subtraction, multiplication, division
- **Memory Functions**: Store, recall, clear memory with status checking
- **Trigonometric Functions**: sin, cos, tan, asin, acos, atan
- **Angle Mode Support**: Automatic conversion between degrees and radians
- **Input Validation**: Robust error handling and domain checking
- **Menu-driven Interface**: Hierarchical menu system with submenus

## How to Compile and Run
```bash
g++ C++_Calculator.cpp -o calculator.exe
calculator.exe
```

## Usage Examples
1. **Basic Calculation**: Choose option 1, enter numbers and operation
2. **Trigonometric Functions**: Choose option 2, select trig function from submenu
3. **Store/Recall Memory**: Options 3-4 for storing and recalling values
4. **Use Memory in Calculations**: Type 'M' instead of a number to use stored value
5. **Toggle Angle Mode**: Option 7 switches between degrees and radians
6. **Memory Management**: Options 5-6 for clearing and checking memory status

### Trigonometric Examples
- **Degrees Mode**: sin(30) = 0.5, cos(60) = 0.5, tan(45) = 1
- **Radians Mode**: sin(π/6) = 0.5, cos(π/3) = 0.5, tan(π/4) = 1
- **Inverse Functions**: asin(0.5) = 30° (degrees) or 0.5236 (radians)

## Code Structure Explained

### Class Architecture

#### Memory Class
```cpp
class Memory {
private:                    // Data hiding - encapsulation
    double storedValue;     // The stored number
    bool hasValue;          // Tracks if memory has a value
    
public:                     // Public interface
    Memory() { ... }        // Constructor - initializes object
    void store(double value) { ... }     // Store a value
    double recall() { ... }              // Retrieve stored value
    void clear() { ... }                 // Clear memory
    bool isEmpty() { ... }               // Check if empty
    void displayStatus() { ... }         // Show memory status
};
```

#### TrigCalculator Class
```cpp
class TrigCalculator {
private:
    bool useDegrees;                      // Angle mode state
    double degreesToRadians(double deg);  // Conversion utility
    double radiansToDegrees(double rad);  // Conversion utility
    
public:
    TrigCalculator() { ... }              // Constructor - defaults to degrees
    void setAngleMode(bool degrees);      // Toggle degrees/radians
    double sine(double angle);            // Trigonometric functions
    double cosine(double angle);
    double tangent(double angle);
    double arcsine(double value);         // Inverse functions with domain checking
    double arccosine(double value);
    double arctangent(double value);
};
```

### Key C++ Concepts Demonstrated

1. **Multiple Class Design**: Two specialized classes (Memory, TrigCalculator) with distinct responsibilities
2. **Encapsulation**: Private data members and utility functions hidden from outside access
3. **Constructors**: Initialize objects with default states (Memory empty, TrigCalculator in degrees)
4. **State Management**: Classes maintain internal state (memory contents, angle mode)
5. **Method Overloading**: Different methods for related operations (sine, cosine, tangent)
6. **Domain Validation**: Mathematical constraint checking for inverse functions
7. **Automatic Conversion**: Transparent degree/radian conversion based on current mode

### Program Architecture
- **Class-based Organization**: Functionality separated into logical classes
- **Hierarchical Menus**: Main menu with trigonometric submenu
- **Function Categories**: 
  - Basic arithmetic functions: `add()`, `subtract()`, `multiply()`, `divide()`
  - Utility functions: `clearInput()`, `showMenu()`, `showTrigMenu()`
  - Class methods: Memory and trigonometric operations
- **Error Handling**: Multiple layers of input validation and mathematical error prevention

### Advanced Features
- **Angle Mode Toggle**: Runtime switching between degrees and radians
- **Memory Integration**: Store and recall trigonometric results
- **Domain Checking**: Prevents mathematical errors (division by zero, inverse trig domains)
- **User-friendly Interface**: Clear prompts and error messages

## Learning Objectives
- **Object-Oriented Design**: Multiple class architecture with specialized responsibilities
- **State Management**: Classes that maintain and modify internal state
- **Mathematical Programming**: Integration of C++ math library (`<cmath>`)
- **Input Validation**: Robust handling of user input errors
- **Menu Systems**: Hierarchical navigation and user interface design
- **Error Handling**: Mathematical and input validation error prevention
- **Code Organization**: Separation of concerns and modular design principles