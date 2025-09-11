import 'package:flutter/material.dart';

class CalculatorDisplay extends StatelessWidget {
  final String currentValue;
  final bool isDegreesMode;
  final bool hasMemory;

  const CalculatorDisplay({
    super.key,
    required this.currentValue,
    required this.isDegreesMode,
    required this.hasMemory,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(16),
      child: Column(
        children: [
          // Main Display
          Expanded(
            child: Container(
              width: double.infinity,
              padding: const EdgeInsets.all(20),
              decoration: BoxDecoration(
                gradient: const LinearGradient(
                  begin: Alignment.topLeft,
                  end: Alignment.bottomRight,
                  colors: [Color(0xFF1A1A1A), Color(0xFF0F0F0F)],
                ),
                borderRadius: BorderRadius.circular(12),
                border: Border.all(
                  color: const Color(0xFF3DAEE9),
                  width: 2,
                ),
              ),
              child: Align(
                alignment: Alignment.centerRight,
                child: Text(
                  _formatDisplayValue(currentValue),
                  style: const TextStyle(
                    color: Colors.white,
                    fontSize: 32,
                    fontWeight: FontWeight.w600,
                    fontFamily: 'monospace',
                    letterSpacing: 1.0,
                  ),
                  textAlign: TextAlign.right,
                  maxLines: 2,
                  overflow: TextOverflow.ellipsis,
                ),
              ),
            ),
          ),
          
          // Status Bar
          const SizedBox(height: 8),
          Container(
            width: double.infinity,
            padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
            decoration: BoxDecoration(
              color: Colors.black.withOpacity(0.3),
              borderRadius: BorderRadius.circular(8),
            ),
            child: Text(
              'Ready | Memory: ${hasMemory ? 'Has Value' : 'Empty'} | Mode: ${isDegreesMode ? 'Degrees' : 'Radians'}',
              style: TextStyle(
                color: Colors.grey.shade400,
                fontSize: 14,
                fontWeight: FontWeight.w500,
              ),
              textAlign: TextAlign.center,
            ),
          ),
        ],
      ),
    );
  }

  String _formatDisplayValue(String value) {
    // Handle very long numbers by using scientific notation
    if (value.length > 12) {
      final num = double.tryParse(value);
      if (num != null) {
        return num.toStringAsExponential(6);
      }
    }
    return value;
  }
}