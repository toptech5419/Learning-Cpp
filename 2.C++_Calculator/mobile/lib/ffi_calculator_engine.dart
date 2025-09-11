import 'dart:ffi';
import 'dart:io';

// FFI integration with C++ calculator engine
// This provides the bridge between Dart and our C++ calculator classes

// Define the C function signatures
typedef CreateCalculatorEngineC = Pointer Function();
typedef CreateCalculatorEngine = Pointer Function();

typedef DestroyCalculatorEngineC = Void Function(Pointer);
typedef DestroyCalculatorEngine = void Function(Pointer);

typedef CalculatorOperationC = Double Function(Pointer, Double, Double);
typedef CalculatorOperation = double Function(Pointer, double, double);

typedef CalculatorUnaryOperationC = Double Function(Pointer, Double);
typedef CalculatorUnaryOperation = double Function(Pointer, double);

typedef CalculatorMemorySetC = Void Function(Pointer, Double);
typedef CalculatorMemorySet = void Function(Pointer, double);

typedef CalculatorMemoryGetC = Double Function(Pointer);
typedef CalculatorMemoryGet = double Function(Pointer);

typedef CalculatorBoolSetC = Void Function(Pointer, Bool);
typedef CalculatorBoolSet = void Function(Pointer, bool);

typedef CalculatorBoolGetC = Bool Function(Pointer);
typedef CalculatorBoolGet = bool Function(Pointer);

typedef CalculatorMemoryClearC = Void Function(Pointer);
typedef CalculatorMemoryClear = void Function(Pointer);

class FFICalculatorEngine {
  static DynamicLibrary? _library;
  Pointer? _engine;

  // C++ function bindings
  late final CreateCalculatorEngine _createEngine;
  late final DestroyCalculatorEngine _destroyEngine;
  late final CalculatorOperation _add;
  late final CalculatorOperation _subtract;
  late final CalculatorOperation _multiply;
  late final CalculatorOperation _divide;
  late final CalculatorUnaryOperation _sine;
  late final CalculatorUnaryOperation _cosine;
  late final CalculatorUnaryOperation _tangent;
  late final CalculatorUnaryOperation _arcsine;
  late final CalculatorUnaryOperation _arccosine;
  late final CalculatorUnaryOperation _arctangent;
  late final CalculatorMemorySet _storeMemory;
  late final CalculatorMemoryGet _recallMemory;
  late final CalculatorMemoryClear _clearMemory;
  late final CalculatorBoolGet _hasMemoryValue;
  late final CalculatorBoolSet _setAngleMode;
  late final CalculatorBoolGet _getAngleMode;
  late final CalculatorMemoryGet _getLastResult;

  FFICalculatorEngine() {
    _loadLibrary();
    if (_library != null) {
      _bindFunctions();
      _engine = _createEngine();
    }
  }

  void _loadLibrary() {
    try {
      if (Platform.isAndroid) {
        _library = DynamicLibrary.open('libcalculator_ffi.so');
      } else if (Platform.isIOS) {
        _library = DynamicLibrary.process();
      } else if (Platform.isWindows) {
        _library = DynamicLibrary.open('calculator_ffi.dll');
      } else if (Platform.isLinux) {
        _library = DynamicLibrary.open('libcalculator_ffi.so');
      } else if (Platform.isMacOS) {
        _library = DynamicLibrary.open('libcalculator_ffi.dylib');
      }
    } catch (e) {
      print('Failed to load native library: $e');
      _library = null;
    }
  }

  void _bindFunctions() {
    if (_library == null) return;

    _createEngine = _library!
        .lookup<NativeFunction<CreateCalculatorEngineC>>('create_calculator_engine')
        .asFunction();

    _destroyEngine = _library!
        .lookup<NativeFunction<DestroyCalculatorEngineC>>('destroy_calculator_engine')
        .asFunction();

    _add = _library!
        .lookup<NativeFunction<CalculatorOperationC>>('calculator_add')
        .asFunction();

    _subtract = _library!
        .lookup<NativeFunction<CalculatorOperationC>>('calculator_subtract')
        .asFunction();

    _multiply = _library!
        .lookup<NativeFunction<CalculatorOperationC>>('calculator_multiply')
        .asFunction();

    _divide = _library!
        .lookup<NativeFunction<CalculatorOperationC>>('calculator_divide')
        .asFunction();

    _sine = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_sine')
        .asFunction();

    _cosine = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_cosine')
        .asFunction();

    _tangent = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_tangent')
        .asFunction();

    _arcsine = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_arcsine')
        .asFunction();

    _arccosine = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_arccosine')
        .asFunction();

    _arctangent = _library!
        .lookup<NativeFunction<CalculatorUnaryOperationC>>('calculator_arctangent')
        .asFunction();

    _storeMemory = _library!
        .lookup<NativeFunction<CalculatorMemorySetC>>('calculator_store_memory')
        .asFunction();

    _recallMemory = _library!
        .lookup<NativeFunction<CalculatorMemoryGetC>>('calculator_recall_memory')
        .asFunction();

    _clearMemory = _library!
        .lookup<NativeFunction<CalculatorMemoryClearC>>('calculator_clear_memory')
        .asFunction();

    _hasMemoryValue = _library!
        .lookup<NativeFunction<CalculatorBoolGetC>>('calculator_has_memory_value')
        .asFunction();

    _setAngleMode = _library!
        .lookup<NativeFunction<CalculatorBoolSetC>>('calculator_set_angle_mode')
        .asFunction();

    _getAngleMode = _library!
        .lookup<NativeFunction<CalculatorBoolGetC>>('calculator_get_angle_mode')
        .asFunction();

    _getLastResult = _library!
        .lookup<NativeFunction<CalculatorMemoryGetC>>('calculator_get_last_result')
        .asFunction();
  }

  bool get isAvailable => _library != null && _engine != null;

  // Basic operations
  double add(double a, double b) {
    if (!isAvailable) return a + b; // Fallback
    return _add(_engine!, a, b);
  }

  double subtract(double a, double b) {
    if (!isAvailable) return a - b; // Fallback
    return _subtract(_engine!, a, b);
  }

  double multiply(double a, double b) {
    if (!isAvailable) return a * b; // Fallback
    return _multiply(_engine!, a, b);
  }

  double divide(double a, double b) {
    if (!isAvailable) {
      if (b == 0) throw ArgumentError('Division by zero');
      return a / b; // Fallback
    }
    return _divide(_engine!, a, b);
  }

  // Trigonometric operations
  double sine(double angle) {
    if (!isAvailable) {
      // Fallback implementation
      final radians = getAngleMode() ? angle * 3.14159265359 / 180 : angle;
      return math.sin(radians);
    }
    return _sine(_engine!, angle);
  }

  double cosine(double angle) {
    if (!isAvailable) {
      // Fallback implementation  
      final radians = getAngleMode() ? angle * 3.14159265359 / 180 : angle;
      return math.cos(radians);
    }
    return _cosine(_engine!, angle);
  }

  double tangent(double angle) {
    if (!isAvailable) {
      // Fallback implementation
      final radians = getAngleMode() ? angle * 3.14159265359 / 180 : angle;
      return math.tan(radians);
    }
    return _tangent(_engine!, angle);
  }

  double arcsine(double value) {
    if (!isAvailable) {
      // Fallback implementation
      if (value < -1 || value > 1) {
        throw ArgumentError('Domain error: Input must be between -1 and 1');
      }
      final result = math.asin(value);
      return getAngleMode() ? result * 180 / 3.14159265359 : result;
    }
    return _arcsine(_engine!, value);
  }

  double arccosine(double value) {
    if (!isAvailable) {
      // Fallback implementation
      if (value < -1 || value > 1) {
        throw ArgumentError('Domain error: Input must be between -1 and 1');
      }
      final result = math.acos(value);
      return getAngleMode() ? result * 180 / 3.14159265359 : result;
    }
    return _arccosine(_engine!, value);
  }

  double arctangent(double value) {
    if (!isAvailable) {
      // Fallback implementation
      final result = math.atan(value);
      return getAngleMode() ? result * 180 / 3.14159265359 : result;
    }
    return _arctangent(_engine!, value);
  }

  // Memory operations
  void storeInMemory(double value) {
    if (!isAvailable) return;
    _storeMemory(_engine!, value);
  }

  double recallFromMemory() {
    if (!isAvailable) return 0.0;
    return _recallMemory(_engine!);
  }

  void clearMemory() {
    if (!isAvailable) return;
    _clearMemory(_engine!);
  }

  bool hasMemoryValue() {
    if (!isAvailable) return false;
    return _hasMemoryValue(_engine!);
  }

  // Mode operations
  void setAngleMode(bool degrees) {
    if (!isAvailable) return;
    _setAngleMode(_engine!, degrees);
  }

  bool getAngleMode() {
    if (!isAvailable) return true; // Default to degrees
    return _getAngleMode(_engine!);
  }

  double getLastResult() {
    if (!isAvailable) return 0.0;
    return _getLastResult(_engine!);
  }

  void dispose() {
    if (_engine != null) {
      _destroyEngine(_engine!);
      _engine = null;
    }
  }
}

// Add missing import for fallback math operations
import 'dart:math' as math;