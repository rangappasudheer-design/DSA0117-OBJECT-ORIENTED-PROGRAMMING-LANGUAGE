
# TASK 2 – Use Tokens, Keywords, Identifiers and Constants Correctly

## 1. Introduction

The purpose of this task is to define metro fares, peak surcharge and minimum balance using appropriate C++ constants.

The program uses constexpr constants and enum class to improve safety, readability and maintainability.

## 2. Five Types of Tokens

Tokens are the smallest individual elements of a C++ program.

### A. Keywords
Keywords are reserved words in C++.

Examples:
- int
- return
- if
- switch
- enum
- constexpr

### B. Identifiers
Identifiers are names given to variables, functions and constants.

Examples:
- INNER_FARE
- MIDDLE_FARE
- OUTER_FARE
- baseFare
- finalFare
- getBaseFare()

### C. Constants
Constants are fixed values that cannot be changed during program execution.

Examples:
- 1000
- 2000
- 3000
- 20
- 5000

### D. Operators
Operators perform operations on values.

Examples:
- + Addition
- = Assignment
- * Multiplication
- / Division
- == Equal to
- ? Conditional operator

### E. Punctuators
Punctuators are symbols used to organize C++ statements.

Examples:
- { } Curly braces
- ( ) Parentheses
- ; Semicolon
- , Comma

## 3. Difference Between #define, const and constexpr

### #define
#define is a preprocessor directive used to define macros.

Example:
#define INNER_FARE 1000

It does not provide normal C++ type checking.

### const
const declares a variable whose value cannot be modified after initialization.

Example:
const int fare = 1000;

### constexpr
constexpr declares a value that can be evaluated at compile time when possible.

Example:
constexpr int INNER_FARE = 1000;

### Why constexpr is preferred

constexpr provides:
1. Type checking.
2. Compile-time evaluation.
3. Better readability.
4. Better safety.
5. Easy maintenance.

Therefore, constexpr is preferred for the metro fare table.

## 4. enum and enum class

### enum

enum is used to define named integer constants.

Example:

enum Zone
{
    Inner,
    Middle,
    Outer
};

### enum class

enum class provides stronger type safety and scoped names.

Example:

enum class Zone
{
    Inner,
    Middle,
    Outer
};

Zone z = Zone::Inner;

### Why enum class is safer

1. It avoids accidental conversion to integers.
2. It provides scoped enumerators.
3. It avoids many naming conflicts.
4. It improves program readability.

Therefore, enum class is selected for the metro zone system.

## 5. Identifier Naming Rules

1. An identifier must start with a letter or underscore.
2. It cannot contain spaces.
3. Keywords cannot be used as identifiers.
4. Identifiers are case-sensitive.
5. Meaningful names should be used.
6. Constants are written using uppercase letters by convention.

Examples:

Valid:
INNER_FARE
baseFare
finalFare

Invalid:
2fare
base fare
int

## 6. Alternative Concept and Complexity Analysis

If #define macros were used instead of constexpr, the program could be written as:

#define INNER_FARE 1000
#define MIDDLE_FARE 2000
#define OUTER_FARE 3000
#define PEAK_SURCHARGE 20

### Comparison

| Feature | #define | constexpr |
|---|---|---|
| Type checking | No normal type checking | Yes |
| Scope | Preprocessor-based | C++ scope |
| Memory | Usually no storage | Usually no storage |
| Runtime | No runtime cost | No runtime cost |
| Safety | Less safe | More safe |

### Time Complexity

The fare selection using switch takes O(1) time because the number of zones is fixed.

### Space Complexity

The program uses O(1) additional space because it stores a fixed number of constants and variables.

### Conclusion

I recommend constexpr and enum class instead of #define and ordinary enum.

They provide better type safety, readability and maintainability.

If metro fares change, the constants can be modified in one place without changing the entire program.
