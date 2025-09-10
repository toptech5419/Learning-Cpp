#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QButtonGroup>
#include "../core/CalculatorEngine.h"

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

private:
    // Core calculator engine
    CalculatorEngine* engine;
    
    // UI Components
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QLineEdit* display;
    QLabel* statusLabel;
    
    // Button layouts
    QGridLayout* buttonLayout;
    QHBoxLayout* memoryButtonLayout;
    QHBoxLayout* trigButtonLayout;
    
    // Number buttons (0-9)
    QPushButton* numberButtons[10];
    
    // Operation buttons
    QPushButton* addButton;
    QPushButton* subtractButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;
    QPushButton* equalsButton;
    QPushButton* clearButton;
    QPushButton* clearEntryButton;
    QPushButton* decimalButton;
    
    // Memory buttons
    QPushButton* memoryStoreButton;
    QPushButton* memoryRecallButton;
    QPushButton* memoryClearButton;
    QPushButton* memoryStatusButton;
    
    // Trigonometric buttons
    QPushButton* sinButton;
    QPushButton* cosButton;
    QPushButton* tanButton;
    QPushButton* asinButton;
    QPushButton* acosButton;
    QPushButton* atanButton;
    
    // Mode buttons
    QPushButton* degreeRadianToggle;
    
    // Menu system
    QMenu* viewMenu;
    QMenu* helpMenu;
    QAction* showTrigAction;
    QAction* showMemoryAction;
    QAction* aboutAction;
    
    // Calculator state
    QString currentInput;
    QString pendingOperator;
    double operand;
    bool waitingForOperand;
    
    void setupUI();
    void setupMenus();
    void setupButtons();
    void setupLayouts();
    void connectSignals();
    void updateDisplay();
    void updateStatusLabel();
    
public:
    explicit CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void onNumberButtonClicked();
    void onOperatorButtonClicked();
    void onEqualsButtonClicked();
    void onClearButtonClicked();
    void onClearEntryButtonClicked();
    void onDecimalButtonClicked();
    
    void onMemoryStoreClicked();
    void onMemoryRecallClicked();
    void onMemoryClearClicked();
    void onMemoryStatusClicked();
    
    void onTrigButtonClicked();
    void onDegreeRadianToggleClicked();
    
    void onShowTrigToggled(bool show);
    void onShowMemoryToggled(bool show);
    void onAboutClicked();
};

#endif // CALCULATORWINDOW_H