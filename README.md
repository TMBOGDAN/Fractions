# Generic Fraction with Gaussian Numbers (C++)

## Overview

This project implements a *generic Fraction class* using C++ templates, allowing fractions to be created with any numeric type that supports basic arithmetic operations.

In addition to standard numeric types (e.g. `int`), the project includes a custom implementation of **Gaussian integers** (`a + bi`) and demonstrates how they can be seamlessly used as a template parameter.

---

## Features

- Generic `Fraction<T>` class implemented using templates
- Support for:
  - Addition
  - Subtraction
  - Multiplication
  - Division
  - Equality comparison
  - Unary negation
- Explicit conversion from `Fraction<T>` to `T`
- Custom `Gauss` class (Gaussian integers)
- Operator overloading for both `Fraction` and `Gauss`
- Stream output support (`operator<<`)

---

## Gaussian Integer Class (`Gauss`)

The `Gauss` class represents numbers of the form:

