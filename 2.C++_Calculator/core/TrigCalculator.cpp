#include "TrigCalculator.h"

using namespace std;

TrigCalculator::TrigCalculator() {
    useDegrees = true;
}

double TrigCalculator::degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double TrigCalculator::radiansToDegrees(double radians) {
    return radians * 180.0 / M_PI;
}

void TrigCalculator::setAngleMode(bool degrees) {
    useDegrees = degrees;
    cout << "Angle mode set to: " << (degrees ? "Degrees" : "Radians") << endl;
}

bool TrigCalculator::getAngleMode() {
    return useDegrees;
}

double TrigCalculator::sine(double angle) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return sin(angle);
}

double TrigCalculator::cosine(double angle) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return cos(angle);
}

double TrigCalculator::tangent(double angle) {
    if (useDegrees) {
        angle = degreesToRadians(angle);
    }
    return tan(angle);
}

double TrigCalculator::arcsine(double value) {
    if (value < -1 || value > 1) {
        cout << "Error: Domain error for arcsin! Input must be between -1 and 1." << endl;
        return 0;
    }
    double result = asin(value);
    return useDegrees ? radiansToDegrees(result) : result;
}

double TrigCalculator::arccosine(double value) {
    if (value < -1 || value > 1) {
        cout << "Error: Domain error for arccos! Input must be between -1 and 1." << endl;
        return 0;
    }
    double result = acos(value);
    return useDegrees ? radiansToDegrees(result) : result;
}

double TrigCalculator::arctangent(double value) {
    double result = atan(value);
    return useDegrees ? radiansToDegrees(result) : result;
}

void TrigCalculator::displayAngleMode() {
    cout << "Current angle mode: " << (useDegrees ? "Degrees" : "Radians") << endl;
}