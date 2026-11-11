
# TASK 3 – Choose Data Types and Check Type Compatibility

## 1. Introduction

The objective of this task is to select appropriate C++ data types for the Namma Metro Smart-Card Fare System.

Different data types are used to store fare, balance, time, zone number and journey count accurately.

## 2. Selection of Data Types

| Data | Data Type | Reason |
|---|---|---|
| Peak hour | bool | Stores true or false |
| Zone code | char | Stores a single character |
| Time | int | Stores hour values |
| Fare | long long | Stores fare in paise |
| Balance | long long | Stores card balance in paise |
| Zone number | unsigned int | Stores non-negative zone number |
| Temperature | float | Stores approximate decimal values |
| Fare in rupees | double | Stores approximate decimal values |
| Journey count | long long | Supports large journey counts |
| Automatic type | auto | Automatically deduces the type |

## 3. Why Money Should Be Stored in Integer Paise

Money should be stored in integer paise instead of double rupees.

For example:

Rs 10 = 1000 paise

Rs 20 = 2000 paise

Rs 30 = 3000 paise

Integer paise avoids binary floating-point rounding errors in fare calculations.

Therefore, long long is selected for fare and balance values.

## 4. Type Compatibility

Type compatibility means how different data types work together in an expression.

Example:

int a = 7;
double b = 2.5;
double result = a + b;

Output:

9.5

Here, the integer value is converted into double before addition.

### Integer to Boolean Conversion

Example:

bool flag = 5;

Output:

true

Any non-zero value converts to true, while zero converts to false.

## 5. sizeof Operator

The sizeof operator is used to find the memory size of a data type or variable.

Examples:

sizeof(int)
sizeof(char)
sizeof(double)
sizeof(long long)

The actual sizes are displayed by executing the program on the selected compiler.

## 6. Integer Ranges Using climits

The climits header provides integer limits.

Examples:

INT_MAX = 2147483647
INT_MIN = -2147483648

LLONG_MAX = 9223372036854775807

An int is not sufficient for storing the worst-case total collection in paise for 3,000,000 journeys.

Therefore, long long is preferred.

## 7. Network Collection Calculation

Assumption: Every journey pays the maximum fare of Rs 36.

20,000 journeys:

20,000 × 3600 = 72,000,000 paise
Total = Rs 720,000

500,000 journeys:

500,000 × 3600 = 1,800,000,000 paise
Total = Rs 18,000,000

3,000,000 journeys:

3,000,000 × 3600 = 10,800,000,000 paise
Total = Rs 108,000,000

The final amount exceeds the maximum signed int value.

Hence, long long is required for network collection in paise.

## 8. Alternative Concept – Double Rupees

If double rupees were used instead of long long paise:

double fare = 10.50;
double balance = 100.00;

This method supports decimal values but can introduce floating-point rounding errors.

Example:

double sum = 0.0;

for (int i = 0; i < 10; i++)
{
    sum += 0.1;
}

The result may not be exactly 1.0 because 0.1 cannot be represented exactly in binary floating-point.

## 9. Complexity Analysis

| Operation | Integer Paise | Double Rupees |
|---|---|---|
| Addition | O(1) | O(1) |
| Storage | Usually 8 bytes | Usually 8 bytes |
| Precision | Exact for whole paise within range | Approximate |
| Rounding error | No floating-point rounding | Possible |

Both methods take O(1) time for one addition.

Both generally require O(1) space per value.

## 10. Conclusion

I recommend using long long integer paise for all metro fare and balance calculations.

It provides exact whole-paise calculations and supports large network collections.

Double can be used for approximate scientific or measurement calculations, but it is not recommended for exact money calculations.
