# Qt GUI Desktop Calculator - Option 1

## Overview
A professional desktop calculator application built with Qt 6.9.2, featuring a modern dark theme interface and comprehensive mathematical functionality. This represents the GUI implementation of our multi-platform calculator architecture.

## Features

### **Core Functionality**
- **Basic Arithmetic**: Addition, subtraction, multiplication, division
- **Memory Operations**: Store (MS), Recall (MR), Clear (MC), Status (M?)
- **Trigonometric Functions**: sin, cos, tan, asin, acos, atan
- **Angle Mode**: Toggle between Degrees and Radians
- **Advanced UI**: Professional calculator layout with color-coded buttons

### **Professional Interface**
- **LCD-Style Display**: Large, clear number display with modern styling
- **Button Groups**: 
  - Number pad (0-9) in standard calculator layout
  - Orange operation buttons (+, -, ×, ÷, =)
  - Green memory function buttons
  - Purple trigonometric function buttons
  - Blue mode toggle button (DEG/RAD)
- **Status Bar**: Real-time display of memory status and angle mode
- **Menu System**: View and Help menus for advanced options

## Installation & Setup

### **Prerequisites**
- **Qt 6.9.2** or later with MinGW compiler
- **Qt Creator** IDE (recommended)
- **Windows 10/11** (primary target, cross-platform compatible)

### **Build Instructions**

#### **Using Qt Creator:**
1. Open Qt Creator
2. File → Open File or Project
3. Select `Calculator_GUI.pro`
4. Configure project with Desktop Qt kit
5. Build → Build Project (Ctrl+B)
6. Run → Run (Ctrl+R)

#### **Command Line:**
```bash
cd gui/
qmake Calculator_GUI.pro
make
Calculator_GUI.exe
```

## Project Structure

```
gui/
├── README.md                   # This file
├── Calculator_GUI.pro          # Qt project file
├── main.cpp                    # Application entry point
├── CalculatorWindow.h          # Main window header
├── CalculatorWindow.cpp        # Main window implementation
├── resources/                  # Assets and icons
└── build/                      # Build output directory
```

## Architecture

### **Design Pattern: MVC (Model-View-Controller)**
- **Model**: `../core/CalculatorEngine` - Business logic and data
- **View**: `CalculatorWindow` - User interface and display
- **Controller**: Qt signal-slot system - User interaction handling

### **Core Dependencies**
```cpp
#include "../core/CalculatorEngine.h"   // Main calculation engine
#include "../core/Memory.h"             // Memory management
#include "../core/TrigCalculator.h"     // Trigonometric functions
```

### **Key Classes**

#### **CalculatorWindow** (Main GUI Class)
```cpp
class CalculatorWindow : public QMainWindow {
    Q_OBJECT
    
private:
    CalculatorEngine* engine;           // Core calculation logic
    QLineEdit* display;                 // LCD-style number display
    QPushButton* numberButtons[10];     // Number pad (0-9)
    QPushButton* operationButtons;      // Math operations
    QLabel* statusLabel;                // Status information
    
private slots:
    void onNumberButtonClicked();       // Handle number input
    void onOperatorButtonClicked();     // Handle operations
    void onMemoryStoreClicked();        // Memory functions
    void onTrigButtonClicked();         // Trigonometric functions
};
```

## User Interface Guide

### **Basic Operations**
1. **Simple Calculation**: Click numbers → operation → numbers → equals
   - Example: `5` → `+` → `3` → `=` → Result: `8`

2. **Memory Functions**:
   - **MS (Memory Store)**: Save current result to memory
   - **MR (Memory Recall)**: Use stored value in calculations
   - **MC (Memory Clear)**: Clear stored memory value
   - **M? (Memory Status)**: Check what's stored in memory

3. **Trigonometric Functions**:
   - Enter angle value → Click trig function (sin, cos, tan)
   - For inverse functions: Enter value → Click inverse function (asin, acos, atan)
   - **DEG/RAD**: Toggle between degree and radian modes

### **Advanced Features**
- **Menu Bar**: Access View and Help options
- **Keyboard Support**: Standard calculator keyboard shortcuts
- **Visual Feedback**: Button hover and press effects
- **Error Handling**: Division by zero protection, domain validation

## Technical Implementation

### **Qt Framework Features Used**
- **QMainWindow**: Professional window with menu bar and status bar
- **QGridLayout**: Calculator-style button arrangement
- **QPushButton**: Custom styled buttons with CSS
- **QLineEdit**: LCD-style display with custom fonts
- **Signal-Slot System**: Event-driven architecture
- **QMenuBar/QMenu**: Professional menu system

### **Styling & Themes**
```css
/* Modern Dark Theme */
QLineEdit {
    background-color: #1e1e1e;
    color: #ffffff;
    font-size: 24px;
    font-family: 'Courier New', monospace;
    border: 2px solid #3daee9;
    border-radius: 8px;
}

QPushButton {
    background-color: #2d2d30;
    color: white;
    border-radius: 6px;
    font-size: 16px;
    min-height: 50px;
}
```

### **Memory Management**
- **Safe Initialization**: Engine created after UI setup
- **Proper Cleanup**: Null-checked deletion in destructor
- **Exception Safety**: Error handling for all operations

## Development Notes

### **Compilation Requirements**
- **C++17** standard
- **Qt Core and Widgets** modules
- **Include paths** to `../core/` directory

### **Build Configuration**
```qmake
QT += core widgets
CONFIG += c++17
INCLUDEPATH += ../core
```

### **Debugging**
- Use Qt Creator's integrated debugger
- Check Application Output for runtime messages
- Debug mode provides detailed error information

## Known Issues & Solutions

### **Common Problems**
1. **Missing DLLs**: Ensure Qt runtime libraries are in PATH
2. **Build Errors**: Verify Qt kit configuration in Qt Creator
3. **Display Issues**: Check graphics drivers for proper rendering

### **Performance Notes**
- **Startup Time**: ~1-2 seconds on modern systems
- **Memory Usage**: ~15-20MB typical usage
- **CPU Usage**: Minimal during normal operation

## Future Enhancements

### **Planned Features**
- **Scientific Functions**: Advanced mathematical operations
- **History**: Calculation history with undo/redo
- **Themes**: Multiple color schemes and layouts
- **Plugins**: Extensible architecture for custom functions

### **Platform Expansion**
- **Web Version**: Same core logic with HTML/JavaScript interface
- **Mobile Apps**: Qt Mobile deployment for iOS/Android
- **API Service**: REST API for calculator functionality

## Contributing

### **Code Standards**
- Follow Qt coding conventions
- Maintain separation between UI and business logic
- Add comprehensive error handling
- Include unit tests for new features

### **Testing**
- Test all button combinations
- Verify memory functions work correctly
- Check trigonometric calculations in both angle modes
- Validate error handling for edge cases

## License & Credits

**Development Framework**: Qt 6.9.2 (Open Source)
**Architecture**: Multi-platform calculator engine
**UI Design**: Modern professional calculator interface
**Target Platform**: Windows Desktop (cross-platform ready)

---

**This Qt GUI calculator demonstrates professional desktop application development using modern C++ and Qt framework, serving as the foundation for multi-platform deployment.**