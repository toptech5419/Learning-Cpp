#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class SimpleCalculator : public QMainWindow {
public:
    SimpleCalculator() {
        setWindowTitle("Simple Calculator Test");
        setFixedSize(300, 200);
        
        QWidget* central = new QWidget(this);
        setCentralWidget(central);
        
        QVBoxLayout* layout = new QVBoxLayout(central);
        
        QLabel* label = new QLabel("Calculator is working!");
        QPushButton* button = new QPushButton("Click me");
        
        layout->addWidget(label);
        layout->addWidget(button);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    SimpleCalculator calc;
    calc.show();
    
    return app.exec();
}