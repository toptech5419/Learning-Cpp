# CLAUDE.md - C++ Learning Project

## Project Overview
This is a C++ learning repository focused on building fundamental programming skills through practical exercises, projects, and systematic study. The project serves as a comprehensive learning journey for mastering C++ concepts and preparing for advanced computer science studies.

## Development Environment
- **Language**: C++ (C++11/14/17/20 standards)
- **Compiler**: g++ (GCC) or clang
- **Platform**: Cross-platform (Windows/Linux/macOS)
- **Build System**: Manual compilation via command line

## Project Structure
```
Learning-Cpp/
├── basics/           # Core C++ concepts and syntax
├── exercises/        # Programming challenges and practice problems
├── projects/         # Hands-on mini projects
├── notes/           # Learning notes and reference materials
└── *.cpp           # Individual practice files
```

## Compilation Instructions
```bash
# Compile individual files
g++ -std=c++17 -Wall -Wextra -g filename.cpp -o output

# For debugging
g++ -std=c++17 -Wall -Wextra -g -DDEBUG filename.cpp -o debug_output

# For release builds
g++ -std=c++17 -O2 -DNDEBUG filename.cpp -o release_output
```

## Common Commands
```bash
# Compile and run
g++ filename.cpp -o program && ./program

# Check for memory leaks (if valgrind available)
valgrind --leak-check=full ./program

# Static analysis (if cppcheck available)
cppcheck --enable=all filename.cpp
```

## Code Style Guidelines
- Follow modern C++ best practices
- Use meaningful variable and function names
- Include proper header guards
- Add comments for complex logic
- Prefer RAII and smart pointers
- Use const correctness
- Follow camelCase for variables, PascalCase for classes

## Learning Focus Areas
1. **Fundamentals**: Variables, data types, operators, control flow
2. **Functions**: Parameters, return types, overloading, recursion
3. **Object-Oriented Programming**: Classes, inheritance, polymorphism, encapsulation
4. **Memory Management**: Pointers, references, dynamic allocation
5. **STL**: Containers, algorithms, iterators
6. **Advanced Topics**: Templates, exception handling, file I/O

## Testing Approach
- Manual testing through console output
- Unit testing for larger functions
- Input validation and edge case handling
- Performance testing for algorithmic solutions

## Build and Run Examples
```bash
# Calculator program
g++ C++_Calculator.cpp -o calculator
./calculator

# Dice rolling program
g++ dice_roll.cpp -o dice
./dice
```

## Dependencies
- Standard C++ Library (no external dependencies)
- C++ compiler supporting C++11 or later

## Learning Resources Integration
This project incorporates concepts from:
- C++ official documentation
- LearnCpp.com tutorials
- Programming with Mosh C++ course
- GeeksforGeeks C++ references

## Progress Tracking
- Each completed exercise is committed with descriptive messages
- Code is organized by complexity and topic
- Regular refactoring to apply newly learned concepts

## Best Practices for This Project
1. Write clean, readable code
2. Test thoroughly before committing
3. Document complex algorithms
4. Practice defensive programming
5. Experiment with different approaches
6. Focus on understanding over memorization

## Notes for Claude Code Assistant
- This is a learning project focused on C++ fundamentals
- Prioritize educational value and best practices
- Encourage experimentation with different C++ features
- Provide explanations for complex concepts when implementing
- Suggest improvements for code quality and efficiency
- Help with debugging and understanding compiler errors
- Guide towards modern C++ standards and practices