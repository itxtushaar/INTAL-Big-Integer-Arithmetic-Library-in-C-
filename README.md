# INTAL (Big Integer Arithmetic Library in C)

INTAL (Integer Array Library) is a custom C library designed to support operations on arbitrarily large integers (up to 1000 digits), which are much larger than the typical integer types provided in C (such as `int`, `long`, etc.). INTAL provides a set of basic arithmetic operations like addition, subtraction, multiplication, and more advanced functions such as calculating the factorial of large numbers and Fibonacci numbers.

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [Usage](#usage)
  - [Functions Implemented](#functions-implemented)
  - [Examples](#examples)
- [Implementation Details](#implementation-details)
  - [1. INTAL Initialization](#1-intal-initialization)
  - [2. INTAL Comparison](#2-intal-comparison)
  - [3. INTAL Addition](#3-intal-addition)
  - [4. INTAL Subtraction](#4-intal-subtraction)
  - [5. INTAL Multiplication](#5-intal-multiplication)
  - [6. INTAL Fibonacci](#6-intal-fibonacci)
  - [7. INTAL Factorial](#7-intal-factorial)
- [Compiling and Testing](#compiling-and-testing)
- [References](#references)

---

## Project Overview

In many cases, modern programming languages like C++ and Java provide support for BigIntegers, allowing developers to work with numbers far larger than those supported by primitive data types. However, the C language lacks native support for such large numbers. INTAL (Integer Array Library) fills this gap by providing a set of functions that allow operations on numbers up to 1000 digits long.

This project implements basic arithmetic operations (addition, subtraction, multiplication) as well as more advanced mathematical functions like calculating the Fibonacci series and factorial for these large numbers.

---

## Features

- Support for numbers up to 1000 digits.
- Basic arithmetic operations: 
  - **Addition**
  - **Subtraction**
  - **Multiplication**
- Advanced mathematical functions:
  - **Fibonacci number calculation**
  - **Factorial calculation**
  - **Binomial Coefficient**
  - **Binary Exponentiation**
  - **Greatest Common Divisor (GCD)**

---

## Usage

### Functions Implemented

Below is a list of functions implemented in this library:

1. **Initialize INTAL**
   - `char* initializeINTAL();`
   - Initializes a 1001 element character array to hold a 1000-digit number with the last element as `\0`.

2. **Compare INTALs**
   - `int compareINTAL(char* intal_a, char* intal_b);`
   - Compares two INTAL numbers and returns:
     - `0` if both numbers are equal.
     - `1` if the first number is greater.
     - `-1` if the second number is greater.

3. **Add INTALs**
   - `char* addINTAL(char* intal_a, char* intal_b);`
   - Adds two INTAL numbers and returns the sum.

4. **Subtract INTALs**
   - `char* subtractINTAL(char* intal_a, char* intal_b);`
   - Subtracts the smaller number from the larger one and returns the difference.

5. **Multiply INTALs**
   - `char* multiplyINTAL(char* intal_a, char* intal_b);`
   - Multiplies two INTAL numbers and returns the product.

6. **Fibonacci**
   - `char* FibonacciINTAL(unsigned int n);`
   - Returns the nth Fibonacci number in INTAL format.

7. **Factorial**
   - `char* factorialINTAL(unsigned int n);`
   - Returns the factorial of a number as an INTAL.

---

### Examples

1. **Initializing an INTAL**:
   ```c
   char* bigNumber = initializeINTAL();
   ```

2. **Adding two INTALs**:
   ```c
   char* result = addINTAL("123", "456");
   printf("Sum: %s\n", result);  // Output: Sum: 579
   ```

3. **Fibonacci of a large number**:
   ```c
   char* fibonacci_100 = FibonacciINTAL(100);
   printf("100th Fibonacci: %s\n", fibonacci_100);
   ```

4. **Factorial of a large number**:
   ```c
   char* fact_50 = factorialINTAL(50);
   printf("50! = %s\n", fact_50);
   ```

---

## Implementation Details

### 1. INTAL Initialization

The function `initializeINTAL` initializes a 1001-element array with zeros. This array represents an INTAL number with up to 1000 digits. The final element is reserved for the null terminator (`\0`), which marks the end of the string.

```c
char* initializeINTAL() {
    char* intal = (char*)malloc(1001 * sizeof(char));
    for (int i = 0; i < 1000; i++) {
        intal[i] = '0';
    }
    intal[1000] = '\0';
    return intal;
}
```

### 2. INTAL Comparison

The `compareINTAL` function compares two INTALs by first checking their lengths and then comparing their digits one by one.

```c
int compareINTAL(char* intal_a, char* intal_b) {
    int len_a = strlen(intal_a), len_b = strlen(intal_b);
    if (len_a > len_b) return 1;
    if (len_a < len_b) return -1;
    for (int i = 0; i < len_a; i++) {
        if (intal_a[i] > intal_b[i]) return 1;
        if (intal_a[i] < intal_b[i]) return -1;
    }
    return 0;
}
```

### 3. INTAL Addition

The `addINTAL` function adds two large numbers, digit by digit, from right to left. It handles carries just like elementary addition.

```c
char* addINTAL(char* intal_a, char* intal_b) {
    // Implementation details with carry handling
}
```

### 4. INTAL Subtraction

The `subtractINTAL` function subtracts two INTALs by first comparing them and then borrowing as necessary, similar to elementary subtraction.

```c
char* subtractINTAL(char* intal_a, char* intal_b) {
    // Implementation details with borrowing logic
}
```

### 5. INTAL Multiplication

The `multiplyINTAL` function multiplies two large numbers using a straightforward approach of multiplying each digit and summing partial results.

```c
char* multiplyINTAL(char* intal_a, char* intal_b) {
    // Implementation details for multiplication
}
```

### 6. INTAL Fibonacci

This function calculates the nth Fibonacci number by iterating and summing the previous two Fibonacci numbers.

```c
char* FibonacciINTAL(unsigned int n) {
    // Fibonacci calculation logic
}
```

### 7. INTAL Factorial

This function calculates the factorial of a number by multiplying successive integers.

```c
char* factorialINTAL(unsigned int n) {
    // Factorial calculation logic
}
```

---

## Compiling and Testing

To compile the project, use a C compiler like `gcc`:

```bash
gcc -o intal_library intal.c
```

To test the implementation, a sample test file `intal_sampletest.c` is provided, which includes multiple test cases to verify the correctness of the library. You can modify this file to add more tests or input data.

Run the compiled code using:

```bash
./intal_library
```

---

## References

- [Addition and Subtraction of Big Integers](https://www.geeksforgeeks.org/addition-large-numbers-represented-strings/)
- [Multiplication of Big Integers](https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/)
- [Fibonacci Series](https://en.wikipedia.org/wiki/Fibonacci_number)
- [Factorial](https://en.wikipedia.org/wiki/Factorial)

---

By using INTAL, you can work with large integers that are not natively supported in C, enabling a range of advanced mathematical computations for high-precision needs. Feel free to explore the code and extend the library for additional functionalities like division or modular arithmetic.
