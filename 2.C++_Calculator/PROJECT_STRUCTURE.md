# **Advanced C++ Calculator - Multi-Platform Architecture**

## **Project Overview**
This project demonstrates professional C++ software architecture by separating business logic from user interface, enabling the same core functionality to work across multiple platforms (Console, Desktop GUI, Web, Mobile).

## **Directory Structure**
```
2.C++_Calculator/
├── README.md                    # Main project documentation
├── PROJECT_STRUCTURE.md         # This file - architecture explanation
├── C++_Calculator.cpp           # Original monolithic version (preserved)
├── calculator.exe              # Original executable
├── console_main.cpp            # New console version using core engine
├── console_calculator.exe      # New console executable
├── core/                       # ✨ REUSABLE BUSINESS LOGIC
│   ├── CalculatorEngine.h      # Master controller class
│   ├── CalculatorEngine.cpp    # Main calculation orchestration
│   ├── Memory.h                # Memory management interface
│   ├── Memory.cpp              # Memory operations implementation
│   ├── TrigCalculator.h        # Trigonometric functions interface
│   └── TrigCalculator.cpp      # Trigonometric implementation
├── gui/                        # 🖥️ DESKTOP GUI VERSION (Qt)
│   ├── main.cpp                # Qt application entry point
│   ├── CalculatorWindow.h      # Main window interface
│   ├── CalculatorWindow.cpp    # GUI logic (to be implemented)
│   ├── Calculator_GUI.pro      # Qt project file
│   └── resources/              # Icons, themes, assets
├── web/                        # 🌐 WEB VERSION (Future)
│   └── (WebAssembly or REST API approach)
└── mobile/                     # 📱 MOBILE VERSION (Future)
    └── (Qt Mobile or React Native)
```

## **Architecture Principles**

### **1. Separation of Concerns**
- **Core Logic**: Pure C++ business logic (no UI dependencies)
- **UI Layer**: Platform-specific interfaces that use core logic
- **Data Layer**: Memory and state management

### **2. Dependency Injection**
- UI classes receive CalculatorEngine instance
- Core classes don't know about UI implementation
- Easy testing and mocking

### **3. Single Responsibility**
- `Memory`: Handles value storage/retrieval only
- `TrigCalculator`: Handles trigonometric operations only  
- `CalculatorEngine`: Orchestrates all calculations
- UI Classes: Handle user interaction only

## **Core Classes Explained**

### **CalculatorEngine** (Master Controller)
```cpp
class CalculatorEngine {
    // Coordinates all calculator operations
    // Manages Memory and TrigCalculator instances
    // Provides clean API for UI layers
    // Maintains calculation history and state
};
```

### **Memory** (Data Management)
```cpp
class Memory {
    // Stores and retrieves calculator values
    // Tracks whether memory contains data
    // Provides status information
};
```

### **TrigCalculator** (Mathematical Operations)
```cpp
class TrigCalculator {
    // Handles sin, cos, tan, and inverse functions
    // Manages degree/radian mode conversion
    // Validates input domains (arcsin/arccos)
};
```

## **Platform Implementation Strategy**

### **Console Version** (`console_main.cpp`)
- Uses CalculatorEngine for all logic
- Text-based menu system
- Command-line input/output
- **Compilation**: `g++ -I./core console_main.cpp core/*.cpp -o console_calculator.exe`

### **Desktop GUI Version** (Qt - In Progress)
- Same CalculatorEngine logic
- Professional button-based interface
- Modern dark theme
- **Compilation**: Use Qt Creator or `qmake && make`

### **Web Version** (Future)
- **Option A**: WebAssembly - compile C++ core to run in browser
- **Option B**: REST API - C++ backend, HTML/JavaScript frontend
- Same mathematical accuracy as desktop versions

### **Mobile Version** (Future)
- **Option A**: Qt Mobile - same codebase, mobile-optimized UI
- **Option B**: React Native with C++ bridge
- Touch-optimized interface

## **Key Benefits of This Architecture**

### **1. Code Reusability**
- Core logic works unchanged across all platforms
- Mathematical functions tested once, work everywhere
- Memory management consistent across platforms

### **2. Maintainability**
- Bug fixes in core affect all platforms
- New mathematical functions added once
- Clear separation makes debugging easier

### **3. Testability**
- Core classes can be unit tested independently
- UI can be tested separately from business logic
- Mock objects can simulate different scenarios

### **4. Scalability**
- Easy to add new mathematical functions
- Simple to support new platforms
- Memory system can be enhanced (history, multiple memories)

### **5. Professional Standards**
- Industry-standard architecture patterns
- Clean, readable, maintainable code
- Follows SOLID principles

## **Development Workflow**

### **Phase 1**: ✅ **COMPLETED**
- [x] Extract business logic to core classes
- [x] Create reusable CalculatorEngine
- [x] Test console version compatibility
- [x] Set up Qt GUI project structure

### **Phase 2**: ✅ **COMPLETED**  
- [x] Implement CalculatorWindow.cpp (Qt GUI)
- [x] Create professional calculator interface
- [x] Add modern dark theme and styling
- [x] Test GUI functionality
- [x] Fix all compilation and runtime issues
- [x] Professional desktop calculator working perfectly

### **Phase 3**: 📋 **PLANNED**
- [ ] Web interface implementation
- [ ] Mobile app development
- [ ] Advanced features (graphing, programming)
- [ ] Cloud synchronization

## **How to Build and Run**

### **Console Version**
```bash
# Compile
g++ -I./core console_main.cpp core/*.cpp -o console_calculator.exe

# Run
./console_calculator.exe
```

### **Qt GUI Version** ✅ **WORKING**
```bash
# Using Qt Creator: Open Calculator_GUI.pro
# Using command line:
cd gui
qmake
make
Calculator_GUI.exe
```

**Status**: ✅ **Option 1 Complete** - Professional desktop calculator working perfectly!

## **Learning Outcomes**

This project demonstrates advanced C++ concepts:

1. **Object-Oriented Design**: Multiple cooperating classes
2. **Architectural Patterns**: MVC, dependency injection, separation of concerns  
3. **Cross-Platform Development**: Same logic, multiple interfaces
4. **Professional Code Organization**: Clean folder structure, documentation
5. **Build Systems**: Makefiles, Qt project files
6. **Header Guards**: Proper C++ project structure
7. **Memory Management**: RAII, proper initialization
8. **API Design**: Clean interfaces between layers

This architecture serves as a foundation for professional software development and demonstrates how proper design enables scalability and maintainability.