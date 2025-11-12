# MyString — Custom C++ String Class

A simple implementation of a **custom string class (`MyString`)** in C++, built completely from scratch using raw pointers and dynamic memory.  
This project demonstrates use of concepts like constructors, destructors, operator overloading, deep copying, and move semantics.

---

## Features

- Default, copy, and move constructors  
- Copy and move assignment operators  
- C-string (const char*) constructor  
- Operator overloads:
  - `+` for concatenation  
  - `+=` for appending  
  - `==` and `!=` for comparison  
  - `[]` for indexing  
  - `>>` and `<<` for input/output  
- Safe memory management with proper `delete[]`
- Demonstrates rule of five and deep copy principles

