#ifndef TRIGCALCULATOR_H
#define TRIGCALCULATOR_H

#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class TrigCalculator {
private:
    bool useDegrees;
    
    double degreesToRadians(double degrees);
    double radiansToDegrees(double radians);
    
public:
    TrigCalculator();
    void setAngleMode(bool degrees);
    bool getAngleMode();
    double sine(double angle);
    double cosine(double angle);
    double tangent(double angle);
    double arcsine(double value);
    double arccosine(double value);
    double arctangent(double value);
    void displayAngleMode();
};

#endif // TRIGCALCULATOR_H