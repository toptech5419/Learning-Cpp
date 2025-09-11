#include "../core/CalculatorEngine.h"
#include "../core/Memory.h" 
#include "../core/TrigCalculator.h"

// FFI exports for Flutter integration
// These functions provide a C-style interface to our C++ calculator classes

extern "C" {
    // Engine instance management
    CalculatorEngine* create_calculator_engine() {
        return new CalculatorEngine();
    }
    
    void destroy_calculator_engine(CalculatorEngine* engine) {
        delete engine;
    }
    
    // Basic operations
    double calculator_add(CalculatorEngine* engine, double a, double b) {
        if (engine == nullptr) return 0.0;
        return engine->performBasicOperation(a, b, '+');
    }
    
    double calculator_subtract(CalculatorEngine* engine, double a, double b) {
        if (engine == nullptr) return 0.0;
        return engine->performBasicOperation(a, b, '-');
    }
    
    double calculator_multiply(CalculatorEngine* engine, double a, double b) {
        if (engine == nullptr) return 0.0;
        return engine->performBasicOperation(a, b, '*');
    }
    
    double calculator_divide(CalculatorEngine* engine, double a, double b) {
        if (engine == nullptr) return 0.0;
        return engine->performBasicOperation(a, b, '/');
    }
    
    // Trigonometric operations
    double calculator_sine(CalculatorEngine* engine, double angle) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("sin", angle);
    }
    
    double calculator_cosine(CalculatorEngine* engine, double angle) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("cos", angle);
    }
    
    double calculator_tangent(CalculatorEngine* engine, double angle) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("tan", angle);
    }
    
    double calculator_arcsine(CalculatorEngine* engine, double value) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("asin", value);
    }
    
    double calculator_arccosine(CalculatorEngine* engine, double value) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("acos", value);
    }
    
    double calculator_arctangent(CalculatorEngine* engine, double value) {
        if (engine == nullptr) return 0.0;
        return engine->performTrigOperation("atan", value);
    }
    
    // Memory operations
    void calculator_store_memory(CalculatorEngine* engine, double value) {
        if (engine != nullptr) {
            engine->storeInMemory(value);
        }
    }
    
    double calculator_recall_memory(CalculatorEngine* engine) {
        if (engine == nullptr) return 0.0;
        return engine->recallFromMemory();
    }
    
    void calculator_clear_memory(CalculatorEngine* engine) {
        if (engine != nullptr) {
            engine->clearMemory();
        }
    }
    
    bool calculator_has_memory_value(CalculatorEngine* engine) {
        if (engine == nullptr) return false;
        return engine->hasMemoryValue();
    }
    
    // Mode operations
    void calculator_set_angle_mode(CalculatorEngine* engine, bool degrees) {
        if (engine != nullptr) {
            engine->setAngleMode(degrees);
        }
    }
    
    bool calculator_get_angle_mode(CalculatorEngine* engine) {
        if (engine == nullptr) return true; // Default to degrees
        return engine->getAngleMode();
    }
    
    double calculator_get_last_result(CalculatorEngine* engine) {
        if (engine == nullptr) return 0.0;
        return engine->getLastResult();
    }
}