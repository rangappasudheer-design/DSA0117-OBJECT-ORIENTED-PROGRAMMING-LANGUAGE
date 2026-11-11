
# TASK 4 – Control Implicit Conversions

## 1. Introduction

Implicit conversion occurs when C++ automatically converts one data type into another without an explicit instruction from the programmer.

This task demonstrates integer division, integer-to-double conversion, signed and unsigned conversion, narrowing conversion and static_cast.

## 2. Integer Division

When two integer values are divided, the fractional part is removed.

Example:

int a = 7;
int b = 2;
double c = a / b;

Result: 3

The integer result is then converted into double.

## 3. Integer-to-Double Conversion

Example:

double d = static_cast<double>(a) / b;

The integer a is explicitly converted into double.

Result: 3.5

This provides the correct fractional division.

## 4. Character-to-Integer Promotion

Example:

char ch = 'A' + 2;

The character is promoted to an integer during arithmetic.

ASCII-compatible character codes:
A = 65
C = 67

Therefore, ch prints C.

When ch + 1 is calculated, the result is an integer.

Output: C 68

## 5. Integer-to-Boolean Conversion

Example:

bool flag = 5;

A non-zero integer converts to true.

A zero integer converts to false.

Default Boolean output:
1

Using std::boolalpha:
true

## 6. Signed-to-Unsigned Conversion

Example:

unsigned int u = 1;
int s = -1;

When signed and unsigned integers of the same rank are compared, the signed value is converted to unsigned.

The value -1 becomes UINT_MAX.

Therefore, the expression s < u evaluates to false.

Output: s >= u

The compiler may produce a signed/unsigned comparison warning.

## 7. Narrowing Conversion

Narrowing occurs when converting a value into a type that cannot represent it exactly.

Example:

int x{3.7};

This produces a compilation error because brace initialization prevents narrowing.

Explicit conversion:

int x = static_cast<int>(3.7);

Result: 3

The fractional part is discarded.

## 8. static_cast

static_cast is used to perform explicit type conversion.

Example:

double value = static_cast<double>(7);

This converts integer 7 into double 7.0.

It makes conversions more visible and understandable.

## 9. Predicted and Actual Output

Predicted output:

3 3.5
C 68
1 true
s >= u

Actual output:

3 3.5
C 68
1 true
s >= u

Both outputs are the same.

## 10. Alternative Concept and Complexity Analysis

If every conversion were written explicitly using static_cast and brace initialization, the program would become easier to understand and maintain.

Examples:

double result = static_cast<double>(7) / 2;

bool flag{5 != 0};

int number{3};

### Advantages

1. Makes conversions visible.
2. Helps prevent accidental narrowing.
3. Improves readability.
4. Makes type-related errors easier to identify.

### Complexity Analysis

Time Complexity: O(1)

Space Complexity: O(1)

Explicit conversions do not significantly change the running time or memory usage for these simple operations.

### Conclusion

Explicit conversions using static_cast and brace initialization improve program safety and readability.

They help programmers control data-type conversions and prevent unexpected results.
