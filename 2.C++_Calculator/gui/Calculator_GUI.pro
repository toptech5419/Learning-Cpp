QT += core widgets

CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = Calculator_GUI
TEMPLATE = app

# Source files
SOURCES += \
    main.cpp \
    CalculatorWindow.cpp \
    ../core/CalculatorEngine.cpp \
    ../core/Memory.cpp \
    ../core/TrigCalculator.cpp

# Header files
HEADERS += \
    CalculatorWindow.h \
    ../core/CalculatorEngine.h \
    ../core/Memory.h \
    ../core/TrigCalculator.h

# Include paths
INCLUDEPATH += ../core

# Output directory
DESTDIR = ../

# Object files directory
OBJECTS_DIR = tmp/
MOC_DIR = tmp/
RCC_DIR = tmp/
UI_DIR = tmp/

# Application icon (Windows) - Disabled for now
# RC_ICONS = resources/calculator.ico

# Application info
VERSION = 1.0.0.0
QMAKE_TARGET_COMPANY = "TOPTECH"
QMAKE_TARGET_PRODUCT = "Advanced C++ Calculator"
QMAKE_TARGET_DESCRIPTION = "Calculator with Memory and Trigonometric Functions"
QMAKE_TARGET_COPYRIGHT = "Copyright (c) 2024 TOPTECH"