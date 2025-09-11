import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'calculator_engine.dart';
import 'widgets/calculator_button.dart';
import 'widgets/calculator_display.dart';

class CalculatorScreen extends StatefulWidget {
  const CalculatorScreen({super.key});

  @override
  State<CalculatorScreen> createState() => _CalculatorScreenState();
}

class _CalculatorScreenState extends State<CalculatorScreen> {
  final CalculatorEngine _engine = CalculatorEngine();
  
  String _currentInput = '0';
  String? _previousInput;
  String? _operation;
  bool _waitingForOperand = false;
  bool _isDegreesMode = true;
  bool _hasMemory = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('C++ Calculator'),
        centerTitle: true,
        elevation: 0,
      ),
      body: SafeArea(
        child: Column(
          children: [
            // Display Section
            Expanded(
              flex: 2,
              child: CalculatorDisplay(
                currentValue: _currentInput,
                isDegreesMode: _isDegreesMode,
                hasMemory: _hasMemory,
              ),
            ),
            
            // Memory Functions
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(
                    'Memory Functions',
                    style: Theme.of(context).textTheme.titleSmall?.copyWith(
                      color: const Color(0xFF3DAEE9),
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 8),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: [
                      _buildMemoryButton('MS', _onMemoryStore),
                      _buildMemoryButton('MR', _onMemoryRecall),
                      _buildMemoryButton('MC', _onMemoryClear),
                      _buildMemoryButton('M?', _onMemoryStatus),
                    ],
                  ),
                ],
              ),
            ),
            
            // Trigonometric Functions
            Container(
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      Text(
                        'Trigonometric Functions',
                        style: Theme.of(context).textTheme.titleSmall?.copyWith(
                          color: const Color(0xFF3DAEE9),
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      _buildModeButton(),
                    ],
                  ),
                  const SizedBox(height: 8),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: [
                      _buildTrigButton('sin', () => _onTrigFunction('sin')),
                      _buildTrigButton('cos', () => _onTrigFunction('cos')),
                      _buildTrigButton('tan', () => _onTrigFunction('tan')),
                    ],
                  ),
                  const SizedBox(height: 8),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: [
                      _buildTrigButton('asin', () => _onTrigFunction('asin')),
                      _buildTrigButton('acos', () => _onTrigFunction('acos')),
                      _buildTrigButton('atan', () => _onTrigFunction('atan')),
                    ],
                  ),
                ],
              ),
            ),
            
            // Main Calculator Grid
            Expanded(
              flex: 4,
              child: Container(
                padding: const EdgeInsets.all(16),
                child: Column(
                  children: [
                    // Row 1: Clear buttons and divide
                    Expanded(
                      child: Row(
                        children: [
                          _buildButton('CE', _onClearEntry, ButtonType.clear),
                          _buildButton('C', _onClear, ButtonType.clear),
                          _buildButton('÷', () => _onOperation('/'), ButtonType.operation),
                        ],
                      ),
                    ),
                    
                    // Row 2: 7, 8, 9, multiply
                    Expanded(
                      child: Row(
                        children: [
                          _buildButton('7', () => _onNumber('7'), ButtonType.number),
                          _buildButton('8', () => _onNumber('8'), ButtonType.number),
                          _buildButton('9', () => _onNumber('9'), ButtonType.number),
                          _buildButton('×', () => _onOperation('*'), ButtonType.operation),
                        ],
                      ),
                    ),
                    
                    // Row 3: 4, 5, 6, subtract
                    Expanded(
                      child: Row(
                        children: [
                          _buildButton('4', () => _onNumber('4'), ButtonType.number),
                          _buildButton('5', () => _onNumber('5'), ButtonType.number),
                          _buildButton('6', () => _onNumber('6'), ButtonType.number),
                          _buildButton('-', () => _onOperation('-'), ButtonType.operation),
                        ],
                      ),
                    ),
                    
                    // Row 4: 1, 2, 3, add
                    Expanded(
                      child: Row(
                        children: [
                          _buildButton('1', () => _onNumber('1'), ButtonType.number),
                          _buildButton('2', () => _onNumber('2'), ButtonType.number),
                          _buildButton('3', () => _onNumber('3'), ButtonType.number),
                          _buildButton('+', () => _onOperation('+'), ButtonType.operation),
                        ],
                      ),
                    ),
                    
                    // Row 5: 0, decimal, equals
                    Expanded(
                      child: Row(
                        children: [
                          _buildButton('0', () => _onNumber('0'), ButtonType.number, flex: 2),
                          _buildButton('.', _onDecimal, ButtonType.number),
                          _buildButton('=', _onEquals, ButtonType.equals),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  Widget _buildButton(String text, VoidCallback onPressed, ButtonType type, {int flex = 1}) {
    return Expanded(
      flex: flex,
      child: Padding(
        padding: const EdgeInsets.all(4.0),
        child: CalculatorButton(
          text: text,
          onPressed: onPressed,
          type: type,
        ),
      ),
    );
  }

  Widget _buildMemoryButton(String text, VoidCallback onPressed) {
    return Expanded(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 4.0),
        child: CalculatorButton(
          text: text,
          onPressed: onPressed,
          type: ButtonType.memory,
        ),
      ),
    );
  }

  Widget _buildTrigButton(String text, VoidCallback onPressed) {
    return Expanded(
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 4.0),
        child: CalculatorButton(
          text: text,
          onPressed: onPressed,
          type: ButtonType.trig,
        ),
      ),
    );
  }

  Widget _buildModeButton() {
    return CalculatorButton(
      text: _isDegreesMode ? 'DEG' : 'RAD',
      onPressed: _onModeToggle,
      type: ButtonType.mode,
    );
  }

  // Calculator Operations
  void _onNumber(String number) {
    HapticFeedback.lightImpact();
    setState(() {
      if (_waitingForOperand) {
        _currentInput = number;
        _waitingForOperand = false;
      } else {
        _currentInput = _currentInput == '0' ? number : _currentInput + number;
      }
    });
  }

  void _onDecimal() {
    HapticFeedback.lightImpact();
    setState(() {
      if (_waitingForOperand) {
        _currentInput = '0.';
        _waitingForOperand = false;
      } else if (!_currentInput.contains('.')) {
        _currentInput += '.';
      }
    });
  }

  void _onOperation(String nextOperation) {
    HapticFeedback.mediumImpact();
    final inputValue = double.tryParse(_currentInput) ?? 0.0;

    setState(() {
      if (_previousInput == null) {
        _previousInput = _currentInput;
      } else if (_operation != null) {
        final currentValue = double.tryParse(_previousInput!) ?? 0.0;
        final newValue = _performCalculation(_operation!, currentValue, inputValue);
        _currentInput = _formatNumber(newValue);
        _previousInput = _currentInput;
      }

      _waitingForOperand = true;
      _operation = nextOperation;
    });
  }

  void _onEquals() {
    HapticFeedback.mediumImpact();
    final inputValue = double.tryParse(_currentInput) ?? 0.0;

    setState(() {
      if (_previousInput != null && _operation != null) {
        final previousValue = double.tryParse(_previousInput!) ?? 0.0;
        final newValue = _performCalculation(_operation!, previousValue, inputValue);
        _currentInput = _formatNumber(newValue);
        _previousInput = null;
        _operation = null;
        _waitingForOperand = true;
      }
    });
  }

  void _onClear() {
    HapticFeedback.heavyImpact();
    setState(() {
      _currentInput = '0';
      _previousInput = null;
      _operation = null;
      _waitingForOperand = false;
    });
  }

  void _onClearEntry() {
    HapticFeedback.mediumImpact();
    setState(() {
      _currentInput = '0';
    });
  }

  // Memory Operations
  void _onMemoryStore() {
    HapticFeedback.lightImpact();
    final value = double.tryParse(_currentInput) ?? 0.0;
    _engine.storeInMemory(value);
    setState(() {
      _hasMemory = true;
    });
    _showToast('Stored ${_formatNumber(value)} in memory');
  }

  void _onMemoryRecall() {
    HapticFeedback.lightImpact();
    final value = _engine.recallFromMemory();
    setState(() {
      _currentInput = _formatNumber(value);
      _waitingForOperand = true;
    });
    _showToast('Recalled ${_formatNumber(value)} from memory');
  }

  void _onMemoryClear() {
    HapticFeedback.mediumImpact();
    _engine.clearMemory();
    setState(() {
      _hasMemory = false;
    });
    _showToast('Memory cleared');
  }

  void _onMemoryStatus() {
    HapticFeedback.lightImpact();
    final hasValue = _engine.hasMemoryValue();
    _showToast(hasValue ? 'Memory contains a value' : 'Memory is empty');
  }

  // Trigonometric Operations
  void _onTrigFunction(String functionName) {
    HapticFeedback.mediumImpact();
    final inputValue = double.tryParse(_currentInput) ?? 0.0;
    
    try {
      double result;
      switch (functionName) {
        case 'sin':
          result = _engine.sine(inputValue, _isDegreesMode);
          break;
        case 'cos':
          result = _engine.cosine(inputValue, _isDegreesMode);
          break;
        case 'tan':
          result = _engine.tangent(inputValue, _isDegreesMode);
          break;
        case 'asin':
          if (inputValue < -1 || inputValue > 1) {
            _showToast('Domain error: Input must be between -1 and 1');
            return;
          }
          result = _engine.arcsine(inputValue, _isDegreesMode);
          break;
        case 'acos':
          if (inputValue < -1 || inputValue > 1) {
            _showToast('Domain error: Input must be between -1 and 1');
            return;
          }
          result = _engine.arccosine(inputValue, _isDegreesMode);
          break;
        case 'atan':
          result = _engine.arctangent(inputValue, _isDegreesMode);
          break;
        default:
          throw Exception('Unknown trigonometric function');
      }

      setState(() {
        _currentInput = _formatNumber(result);
        _waitingForOperand = true;
      });
    } catch (error) {
      _showToast('Calculation error');
    }
  }

  void _onModeToggle() {
    HapticFeedback.lightImpact();
    setState(() {
      _isDegreesMode = !_isDegreesMode;
    });
    _showToast('Switched to ${_isDegreesMode ? 'Degrees' : 'Radians'} mode');
  }

  // Core calculation method
  double _performCalculation(String operation, double firstValue, double secondValue) {
    switch (operation) {
      case '+':
        return _engine.add(firstValue, secondValue);
      case '-':
        return _engine.subtract(firstValue, secondValue);
      case '*':
        return _engine.multiply(firstValue, secondValue);
      case '/':
        if (secondValue == 0) {
          _showToast('Cannot divide by zero');
          return firstValue;
        }
        return _engine.divide(firstValue, secondValue);
      default:
        return secondValue;
    }
  }

  String _formatNumber(double number) {
    if (number == number.toInt()) {
      return number.toInt().toString();
    }
    return number.toString();
  }

  void _showToast(String message) {
    ScaffoldMessenger.of(context).showSnackBar(
      SnackBar(
        content: Text(message),
        duration: const Duration(seconds: 2),
        behavior: SnackBarBehavior.floating,
        margin: const EdgeInsets.all(16),
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(8),
        ),
      ),
    );
  }
}