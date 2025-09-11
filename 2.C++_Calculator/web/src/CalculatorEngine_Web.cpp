#include "../../../core/CalculatorEngine.h"
#include "../../../core/Memory.h"
#include "../../../core/TrigCalculator.h"

#ifdef EMSCRIPTEN
#include <emscripten/bind.h>
#include <emscripten/val.h>
#endif

// Web-specific wrapper for CalculatorEngine
class WebCalculatorEngine {
private:
    CalculatorEngine* engine;
    
public:
    WebCalculatorEngine() {
        engine = new CalculatorEngine();
    }
    
    ~WebCalculatorEngine() {
        delete engine;
    }
    
    // Basic operations
    double add(double a, double b) {
        return engine->performBasicOperation(a, b, '+');
    }
    
    double subtract(double a, double b) {
        return engine->performBasicOperation(a, b, '-');
    }
    
    double multiply(double a, double b) {
        return engine->performBasicOperation(a, b, '*');
    }
    
    double divide(double a, double b) {
        return engine->performBasicOperation(a, b, '/');
    }
    
    // Trigonometric operations
    double sine(double angle) {
        return engine->performTrigOperation("sin", angle);
    }
    
    double cosine(double angle) {
        return engine->performTrigOperation("cos", angle);
    }
    
    double tangent(double angle) {
        return engine->performTrigOperation("tan", angle);
    }
    
    double arcsine(double value) {
        return engine->performTrigOperation("asin", value);
    }
    
    double arccosine(double value) {
        return engine->performTrigOperation("acos", value);
    }
    
    double arctangent(double value) {
        return engine->performTrigOperation("atan", value);
    }
    
    // Memory operations
    void storeInMemory(double value) {
        engine->storeInMemory(value);
    }
    
    double recallFromMemory() {
        return engine->recallFromMemory();
    }
    
    void clearMemory() {
        engine->clearMemory();
    }
    
    bool hasMemoryValue() {
        return engine->hasMemoryValue();
    }
    
    // Mode operations
    void setAngleMode(bool degrees) {
        engine->setAngleMode(degrees);
    }
    
    bool getAngleMode() {
        return engine->getAngleMode();
    }
    
    double getLastResult() {
        return engine->getLastResult();
    }
};

#ifdef EMSCRIPTEN
// Emscripten bindings for WebAssembly
EMSCRIPTEN_BINDINGS(calculator_module) {
    emscripten::class_<WebCalculatorEngine>("WebCalculatorEngine")
        .constructor()
        
        // Basic operations
        .function("add", &WebCalculatorEngine::add)
        .function("subtract", &WebCalculatorEngine::subtract)
        .function("multiply", &WebCalculatorEngine::multiply)
        .function("divide", &WebCalculatorEngine::divide)
        
        // Trigonometric operations
        .function("sine", &WebCalculatorEngine::sine)
        .function("cosine", &WebCalculatorEngine::cosine)
        .function("tangent", &WebCalculatorEngine::tangent)
        .function("arcsine", &WebCalculatorEngine::arcsine)
        .function("arccosine", &WebCalculatorEngine::arccosine)
        .function("arctangent", &WebCalculatorEngine::arctangent)
        
        // Memory operations
        .function("storeInMemory", &WebCalculatorEngine::storeInMemory)
        .function("recallFromMemory", &WebCalculatorEngine::recallFromMemory)
        .function("clearMemory", &WebCalculatorEngine::clearMemory)
        .function("hasMemoryValue", &WebCalculatorEngine::hasMemoryValue)
        
        // Mode operations
        .function("setAngleMode", &WebCalculatorEngine::setAngleMode)
        .function("getAngleMode", &WebCalculatorEngine::getAngleMode)
        .function("getLastResult", &WebCalculatorEngine::getLastResult);
}
#endif