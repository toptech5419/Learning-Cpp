#include "CalculatorWindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QKeySequence>
#include <QShortcut>
#include <QScreen>

CalculatorWindow::CalculatorWindow(QWidget *parent)
    : QMainWindow(parent)
    , engine(nullptr)
    , currentInput("0")
    , pendingOperator("")
    , operand(0.0)
    , waitingForOperand(true)
{
    // Initialize engine first
    engine = new CalculatorEngine();
    
    setupUI();
    setupButtons();
    setupLayouts();
    setupMenus();
    connectSignals();
    updateDisplay();
    updateStatusLabel();
    
    // Set window properties
    setWindowTitle("Advanced C++ Calculator");
    setFixedSize(400, 600);
    
    // Center the window on screen
    QRect screenGeometry = QApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);
}

CalculatorWindow::~CalculatorWindow() {
    if (engine) {
        delete engine;
        engine = nullptr;
    }
}

void CalculatorWindow::setupUI() {
    // Create central widget and main layout
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    mainLayout = new QVBoxLayout(centralWidget);
    
    // Create display (LCD-style)
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setStyleSheet(
        "QLineEdit {"
        "    background-color: #1e1e1e;"
        "    color: #ffffff;"
        "    font-size: 24px;"
        "    font-weight: bold;"
        "    font-family: 'Courier New', monospace;"
        "    border: 2px solid #3daee9;"
        "    border-radius: 8px;"
        "    padding: 15px;"
        "    min-height: 60px;"
        "}"
    );
    
    // Create status label
    statusLabel = new QLabel("Ready | Memory: Empty | Mode: Degrees");
    statusLabel->setStyleSheet(
        "QLabel {"
        "    color: #888888;"
        "    font-size: 12px;"
        "    padding: 5px;"
        "}"
    );
    
    // Create layouts for buttons
    buttonLayout = new QGridLayout();
    memoryButtonLayout = new QHBoxLayout();
    trigButtonLayout = new QHBoxLayout();
    
    // Add components to main layout
    mainLayout->addWidget(display);
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(memoryButtonLayout);
    mainLayout->addLayout(trigButtonLayout);
    mainLayout->addLayout(buttonLayout);
}

void CalculatorWindow::setupMenus() {
    // View menu
    viewMenu = menuBar()->addMenu("&View");
    showTrigAction = viewMenu->addAction("Show &Trigonometric Functions");
    showTrigAction->setCheckable(true);
    showTrigAction->setChecked(true);
    
    showMemoryAction = viewMenu->addAction("Show &Memory Functions");
    showMemoryAction->setCheckable(true);
    showMemoryAction->setChecked(true);
    
    // Help menu
    helpMenu = menuBar()->addMenu("&Help");
    aboutAction = helpMenu->addAction("&About Calculator");
}

void CalculatorWindow::setupButtons() {
    // Button style
    QString buttonStyle = 
        "QPushButton {"
        "    background-color: #2d2d30;"
        "    color: white;"
        "    border: 1px solid #3e3e42;"
        "    border-radius: 6px;"
        "    font-size: 16px;"
        "    font-weight: bold;"
        "    min-width: 60px;"
        "    min-height: 50px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #3e3e42;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #007acc;"
        "}";
    
    QString operatorStyle = 
        "QPushButton {"
        "    background-color: #ff8c00;"
        "    color: white;"
        "    border: 1px solid #ffa500;"
        "    border-radius: 6px;"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "    min-width: 60px;"
        "    min-height: 50px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #ffa500;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #ff6347;"
        "}";
    
    // Create number buttons (0-9)
    for (int i = 0; i <= 9; ++i) {
        numberButtons[i] = new QPushButton(QString::number(i));
        numberButtons[i]->setStyleSheet(buttonStyle);
    }
    
    // Create operation buttons
    addButton = new QPushButton("+");
    subtractButton = new QPushButton("-");
    multiplyButton = new QPushButton("×");
    divideButton = new QPushButton("÷");
    equalsButton = new QPushButton("=");
    clearButton = new QPushButton("C");
    clearEntryButton = new QPushButton("CE");
    decimalButton = new QPushButton(".");
    
    // Apply operator style
    addButton->setStyleSheet(operatorStyle);
    subtractButton->setStyleSheet(operatorStyle);
    multiplyButton->setStyleSheet(operatorStyle);
    divideButton->setStyleSheet(operatorStyle);
    equalsButton->setStyleSheet(operatorStyle);
    
    // Apply button style to others
    clearButton->setStyleSheet(buttonStyle);
    clearEntryButton->setStyleSheet(buttonStyle);
    decimalButton->setStyleSheet(buttonStyle);
    
    // Create memory buttons
    memoryStoreButton = new QPushButton("MS");
    memoryRecallButton = new QPushButton("MR");
    memoryClearButton = new QPushButton("MC");
    memoryStatusButton = new QPushButton("M?");
    
    QString memoryStyle = 
        "QPushButton {"
        "    background-color: #4CAF50;"
        "    color: white;"
        "    border: 1px solid #45a049;"
        "    border-radius: 4px;"
        "    font-size: 12px;"
        "    min-width: 40px;"
        "    min-height: 30px;"
        "}";
    
    memoryStoreButton->setStyleSheet(memoryStyle);
    memoryRecallButton->setStyleSheet(memoryStyle);
    memoryClearButton->setStyleSheet(memoryStyle);
    memoryStatusButton->setStyleSheet(memoryStyle);
    
    // Create trigonometric buttons
    sinButton = new QPushButton("sin");
    cosButton = new QPushButton("cos");
    tanButton = new QPushButton("tan");
    asinButton = new QPushButton("asin");
    acosButton = new QPushButton("acos");
    atanButton = new QPushButton("atan");
    
    QString trigStyle = 
        "QPushButton {"
        "    background-color: #9C27B0;"
        "    color: white;"
        "    border: 1px solid #7B1FA2;"
        "    border-radius: 4px;"
        "    font-size: 11px;"
        "    min-width: 45px;"
        "    min-height: 30px;"
        "}";
    
    sinButton->setStyleSheet(trigStyle);
    cosButton->setStyleSheet(trigStyle);
    tanButton->setStyleSheet(trigStyle);
    asinButton->setStyleSheet(trigStyle);
    acosButton->setStyleSheet(trigStyle);
    atanButton->setStyleSheet(trigStyle);
    
    // Create mode toggle button
    degreeRadianToggle = new QPushButton("DEG");
    degreeRadianToggle->setStyleSheet(
        "QPushButton {"
        "    background-color: #2196F3;"
        "    color: white;"
        "    border: 1px solid #1976D2;"
        "    border-radius: 4px;"
        "    font-size: 11px;"
        "    min-width: 50px;"
        "    min-height: 30px;"
        "}"
    );
}

void CalculatorWindow::setupLayouts() {
    // Memory buttons layout
    memoryButtonLayout->addWidget(memoryStoreButton);
    memoryButtonLayout->addWidget(memoryRecallButton);
    memoryButtonLayout->addWidget(memoryClearButton);
    memoryButtonLayout->addWidget(memoryStatusButton);
    memoryButtonLayout->addStretch();
    
    // Trigonometric buttons layout
    trigButtonLayout->addWidget(sinButton);
    trigButtonLayout->addWidget(cosButton);
    trigButtonLayout->addWidget(tanButton);
    trigButtonLayout->addWidget(asinButton);
    trigButtonLayout->addWidget(acosButton);
    trigButtonLayout->addWidget(atanButton);
    trigButtonLayout->addWidget(degreeRadianToggle);
    trigButtonLayout->addStretch();
    
    // Main calculator grid
    // Row 0: Clear buttons
    buttonLayout->addWidget(clearEntryButton, 0, 0);
    buttonLayout->addWidget(clearButton, 0, 1);
    buttonLayout->addWidget(divideButton, 0, 3);
    
    // Row 1: 7, 8, 9, ×
    buttonLayout->addWidget(numberButtons[7], 1, 0);
    buttonLayout->addWidget(numberButtons[8], 1, 1);
    buttonLayout->addWidget(numberButtons[9], 1, 2);
    buttonLayout->addWidget(multiplyButton, 1, 3);
    
    // Row 2: 4, 5, 6, -
    buttonLayout->addWidget(numberButtons[4], 2, 0);
    buttonLayout->addWidget(numberButtons[5], 2, 1);
    buttonLayout->addWidget(numberButtons[6], 2, 2);
    buttonLayout->addWidget(subtractButton, 2, 3);
    
    // Row 3: 1, 2, 3, +
    buttonLayout->addWidget(numberButtons[1], 3, 0);
    buttonLayout->addWidget(numberButtons[2], 3, 1);
    buttonLayout->addWidget(numberButtons[3], 3, 2);
    buttonLayout->addWidget(addButton, 3, 3);
    
    // Row 4: 0, ., =
    buttonLayout->addWidget(numberButtons[0], 4, 0, 1, 2); // Spans 2 columns
    buttonLayout->addWidget(decimalButton, 4, 2);
    buttonLayout->addWidget(equalsButton, 4, 3);
}

void CalculatorWindow::connectSignals() {
    // Number buttons
    for (int i = 0; i <= 9; ++i) {
        connect(numberButtons[i], &QPushButton::clicked, this, &CalculatorWindow::onNumberButtonClicked);
    }
    
    // Operation buttons
    connect(addButton, &QPushButton::clicked, this, &CalculatorWindow::onOperatorButtonClicked);
    connect(subtractButton, &QPushButton::clicked, this, &CalculatorWindow::onOperatorButtonClicked);
    connect(multiplyButton, &QPushButton::clicked, this, &CalculatorWindow::onOperatorButtonClicked);
    connect(divideButton, &QPushButton::clicked, this, &CalculatorWindow::onOperatorButtonClicked);
    connect(equalsButton, &QPushButton::clicked, this, &CalculatorWindow::onEqualsButtonClicked);
    connect(clearButton, &QPushButton::clicked, this, &CalculatorWindow::onClearButtonClicked);
    connect(clearEntryButton, &QPushButton::clicked, this, &CalculatorWindow::onClearEntryButtonClicked);
    connect(decimalButton, &QPushButton::clicked, this, &CalculatorWindow::onDecimalButtonClicked);
    
    // Memory buttons
    connect(memoryStoreButton, &QPushButton::clicked, this, &CalculatorWindow::onMemoryStoreClicked);
    connect(memoryRecallButton, &QPushButton::clicked, this, &CalculatorWindow::onMemoryRecallClicked);
    connect(memoryClearButton, &QPushButton::clicked, this, &CalculatorWindow::onMemoryClearClicked);
    connect(memoryStatusButton, &QPushButton::clicked, this, &CalculatorWindow::onMemoryStatusClicked);
    
    // Trigonometric buttons
    connect(sinButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    connect(cosButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    connect(tanButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    connect(asinButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    connect(acosButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    connect(atanButton, &QPushButton::clicked, this, &CalculatorWindow::onTrigButtonClicked);
    
    // Mode toggle
    connect(degreeRadianToggle, &QPushButton::clicked, this, &CalculatorWindow::onDegreeRadianToggleClicked);
    
    // Menu actions
    connect(showTrigAction, &QAction::toggled, this, &CalculatorWindow::onShowTrigToggled);
    connect(showMemoryAction, &QAction::toggled, this, &CalculatorWindow::onShowMemoryToggled);
    connect(aboutAction, &QAction::triggered, this, &CalculatorWindow::onAboutClicked);
}

void CalculatorWindow::updateDisplay() {
    display->setText(currentInput);
}

void CalculatorWindow::updateStatusLabel() {
    QString memStatus = engine->hasMemoryValue() ? "Has Value" : "Empty";
    QString angleMode = QString::fromStdString(engine->getAngleModeString());
    statusLabel->setText(QString("Ready | Memory: %1 | Mode: %2").arg(memStatus, angleMode));
}

// Slot implementations
void CalculatorWindow::onNumberButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString digit = button->text();
    
    if (waitingForOperand) {
        currentInput = digit;
        waitingForOperand = false;
    } else {
        if (currentInput == "0") {
            currentInput = digit;
        } else {
            currentInput += digit;
        }
    }
    updateDisplay();
}

void CalculatorWindow::onOperatorButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString op = button->text();
    
    // Convert display symbols to internal operators
    if (op == "×") op = "*";
    if (op == "÷") op = "/";
    
    double inputValue = currentInput.toDouble();
    
    if (!pendingOperator.isEmpty()) {
        double result = engine->performBasicOperation(operand, inputValue, pendingOperator.at(0).toLatin1());
        currentInput = QString::number(result);
        updateDisplay();
        operand = result;
    } else {
        operand = inputValue;
    }
    
    pendingOperator = op;
    waitingForOperand = true;
}

void CalculatorWindow::onEqualsButtonClicked() {
    if (!pendingOperator.isEmpty()) {
        double inputValue = currentInput.toDouble();
        double result = engine->performBasicOperation(operand, inputValue, pendingOperator.at(0).toLatin1());
        currentInput = QString::number(result);
        updateDisplay();
        pendingOperator.clear();
        waitingForOperand = true;
    }
}

void CalculatorWindow::onClearButtonClicked() {
    currentInput = "0";
    pendingOperator.clear();
    operand = 0.0;
    waitingForOperand = true;
    updateDisplay();
}

void CalculatorWindow::onClearEntryButtonClicked() {
    currentInput = "0";
    waitingForOperand = true;
    updateDisplay();
}

void CalculatorWindow::onDecimalButtonClicked() {
    if (waitingForOperand) {
        currentInput = "0.";
        waitingForOperand = false;
    } else if (!currentInput.contains('.')) {
        currentInput += ".";
    }
    updateDisplay();
}

void CalculatorWindow::onMemoryStoreClicked() {
    double value = currentInput.toDouble();
    engine->storeInMemory(value);
    updateStatusLabel();
}

void CalculatorWindow::onMemoryRecallClicked() {
    if (engine->hasMemoryValue()) {
        double value = engine->recallFromMemory();
        currentInput = QString::number(value);
        waitingForOperand = true;
        updateDisplay();
    }
}

void CalculatorWindow::onMemoryClearClicked() {
    engine->clearMemory();
    updateStatusLabel();
}

void CalculatorWindow::onMemoryStatusClicked() {
    engine->showMemoryStatus();
}

void CalculatorWindow::onTrigButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString function = button->text();
    
    double inputValue = currentInput.toDouble();
    double result = engine->performTrigOperation(function.toStdString(), inputValue);
    currentInput = QString::number(result);
    waitingForOperand = true;
    updateDisplay();
}

void CalculatorWindow::onDegreeRadianToggleClicked() {
    bool currentMode = engine->getAngleMode();
    engine->setAngleMode(!currentMode);
    degreeRadianToggle->setText(engine->getAngleMode() ? "DEG" : "RAD");
    updateStatusLabel();
}

void CalculatorWindow::onShowTrigToggled(bool show) {
    // Show/hide trigonometric buttons
    sinButton->setVisible(show);
    cosButton->setVisible(show);
    tanButton->setVisible(show);
    asinButton->setVisible(show);
    acosButton->setVisible(show);
    atanButton->setVisible(show);
    degreeRadianToggle->setVisible(show);
}

void CalculatorWindow::onShowMemoryToggled(bool show) {
    // Show/hide memory buttons
    memoryStoreButton->setVisible(show);
    memoryRecallButton->setVisible(show);
    memoryClearButton->setVisible(show);
    memoryStatusButton->setVisible(show);
}

void CalculatorWindow::onAboutClicked() {
    QMessageBox::about(this, "About Calculator", 
        "Advanced C++ Calculator v1.0\n\n"
        "Features:\n"
        "• Basic arithmetic operations\n"
        "• Memory functions (Store, Recall, Clear)\n"
        "• Trigonometric functions\n"
        "• Degree/Radian mode switching\n\n"
        "Built with Qt and C++\n"
        "Architecture: Multi-platform core engine\n\n"
        "🚀 Generated with professional coding practices");
}