import 'dart:math' as math;

/// Calculator Engine - Dart implementation of C++ calculator core
/// This mirrors the functionality of our C++ CalculatorEngine class
class CalculatorEngine {
  double _memoryValue = 0.0;
  bool _hasMemoryValue = false;
  double _lastResult = 0.0;

  // Basic operations - identical to C++ core
  double add(double a, double b) => a + b;
  double subtract(double a, double b) => a - b;
  double multiply(double a, double b) => a * b;
  
  double divide(double a, double b) {
    if (b == 0) throw ArgumentError('Division by zero');
    return a / b;
  }

  // Trigonometric operations with degree/radian conversion
  double sine(double angle, bool isDegreesMode) {
    final radians = isDegreesMode ? _degreesToRadians(angle) : angle;
    return math.sin(radians);
  }

  double cosine(double angle, bool isDegreesMode) {
    final radians = isDegreesMode ? _degreesToRadians(angle) : angle;
    return math.cos(radians);
  }

  double tangent(double angle, bool isDegreesMode) {
    final radians = isDegreesMode ? _degreesToRadians(angle) : angle;
    return math.tan(radians);
  }

  double arcsine(double value, bool isDegreesMode) {
    if (value < -1 || value > 1) {
      throw ArgumentError('Domain error: Input must be between -1 and 1');
    }
    final result = math.asin(value);
    return isDegreesMode ? _radiansToDegrees(result) : result;
  }

  double arccosine(double value, bool isDegreesMode) {
    if (value < -1 || value > 1) {
      throw ArgumentError('Domain error: Input must be between -1 and 1');
    }
    final result = math.acos(value);
    return isDegreesMode ? _radiansToDegrees(result) : result;
  }

  double arctangent(double value, bool isDegreesMode) {
    final result = math.atan(value);
    return isDegreesMode ? _radiansToDegrees(result) : result;
  }

  // Memory operations - identical to C++ implementation
  void storeInMemory(double value) {
    _memoryValue = value;
    _hasMemoryValue = true;
  }

  double recallFromMemory() {
    return _memoryValue;
  }

  void clearMemory() {
    _memoryValue = 0.0;
    _hasMemoryValue = false;
  }

  bool hasMemoryValue() {
    return _hasMemoryValue;
  }

  // Utility methods
  double getLastResult() => _lastResult;

  void setLastResult(double result) {
    _lastResult = result;
  }

  // Private helper methods for angle conversion
  double _degreesToRadians(double degrees) => degrees * math.pi / 180;
  double _radiansToDegrees(double radians) => radians * 180 / math.pi;
}