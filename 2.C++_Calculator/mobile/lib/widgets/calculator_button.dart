import 'package:flutter/material.dart';

enum ButtonType { number, operation, equals, clear, memory, trig, mode }

class CalculatorButton extends StatelessWidget {
  final String text;
  final VoidCallback onPressed;
  final ButtonType type;

  const CalculatorButton({
    super.key,
    required this.text,
    required this.onPressed,
    required this.type,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(2),
      child: Material(
        borderRadius: BorderRadius.circular(8),
        color: _getBackgroundColor(),
        elevation: 2,
        shadowColor: Colors.black.withOpacity(0.3),
        child: InkWell(
          borderRadius: BorderRadius.circular(8),
          onTap: onPressed,
          child: Container(
            height: _getHeight(),
            decoration: BoxDecoration(
              borderRadius: BorderRadius.circular(8),
              gradient: _getGradient(),
              border: Border.all(
                color: _getBorderColor(),
                width: 1,
              ),
            ),
            child: Center(
              child: Text(
                text,
                style: TextStyle(
                  color: Colors.white,
                  fontSize: _getFontSize(),
                  fontWeight: FontWeight.w600,
                ),
              ),
            ),
          ),
        ),
      ),
    );
  }

  Color _getBackgroundColor() {
    switch (type) {
      case ButtonType.number:
        return const Color(0xFF2D2D30);
      case ButtonType.operation:
      case ButtonType.equals:
        return const Color(0xFFFF8C00);
      case ButtonType.clear:
        return const Color(0xFFDC3545);
      case ButtonType.memory:
        return const Color(0xFF28A745);
      case ButtonType.trig:
        return const Color(0xFF9C27B0);
      case ButtonType.mode:
        return const Color(0xFF2196F3);
    }
  }

  LinearGradient _getGradient() {
    switch (type) {
      case ButtonType.number:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFF2D2D30), Color(0xFF1F1F22)],
        );
      case ButtonType.operation:
      case ButtonType.equals:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFFFF8C00), Color(0xFFE67E00)],
        );
      case ButtonType.clear:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFFDC3545), Color(0xFFC82333)],
        );
      case ButtonType.memory:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFF28A745), Color(0xFF218838)],
        );
      case ButtonType.trig:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFF9C27B0), Color(0xFF7B1FA2)],
        );
      case ButtonType.mode:
        return const LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [Color(0xFF2196F3), Color(0xFF1976D2)],
        );
    }
  }

  Color _getBorderColor() {
    switch (type) {
      case ButtonType.number:
        return const Color(0xFF3E3E42);
      case ButtonType.operation:
      case ButtonType.equals:
        return const Color(0xFFFFA500);
      case ButtonType.clear:
        return const Color(0xFFDC3545);
      case ButtonType.memory:
        return const Color(0xFF28A745);
      case ButtonType.trig:
        return const Color(0xFF9C27B0);
      case ButtonType.mode:
        return const Color(0xFF2196F3);
    }
  }

  double _getFontSize() {
    switch (type) {
      case ButtonType.number:
        return 20.0;
      case ButtonType.operation:
      case ButtonType.equals:
        return 22.0;
      case ButtonType.clear:
        return 18.0;
      case ButtonType.memory:
      case ButtonType.trig:
        return 14.0;
      case ButtonType.mode:
        return 12.0;
    }
  }

  double _getHeight() {
    switch (type) {
      case ButtonType.memory:
      case ButtonType.trig:
        return 36.0;
      case ButtonType.mode:
        return 32.0;
      default:
        return 60.0;
    }
  }
}