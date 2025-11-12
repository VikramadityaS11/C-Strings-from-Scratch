//
//  main.cpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//

#include <iostream>
#include "MyString.hpp"

int main(){
    std::cout << "---- Basic constructors ----\n";
    MyString a; // Default ctor
    MyString b("Hello");  // C-string ctor
    MyString c = b; // Copy ctor
    
    
    std::cout << "\n---- Copy assignment ----\n";
    a = b;                         // Copy assignment
    
    std::cout << "\n---- Move constructor ----\n";
    MyString d = MyString("Temp"); // Move ctor (temporary rvalue)
    
    std::cout << "\n---- Move assignment ----\n";
    a = MyString("World");         // Move assignment (rvalue)
    
    std::cout << "\n---- Operator+ ----\n";
    MyString e = b + a;            // Concatenation, returns new MyString
    std::cout << "Concatenated: " << e << "\n";
    
    std::cout << "\n---- Operator+= ----\n";
    e += MyString("!!!");
    std::cout << "After += : " << e << "\n";
    
    std::cout << "\n---- Comparison ----\n";
    std::cout << std::boolalpha;
    std::cout << "b == c? " << (b == c) << "\n";
    std::cout << "b != a? " << (b != a) << "\n";
    
    std::cout << "\n---- Indexing ----\n";
    std::cout << "First char of e: " << e[0] << "\n";
    
    std::cout << "\n---- Input (operator>>) ----\n";
    MyString input;
    std::cout << "Enter a word: ";
    std::cin >> input;
    std::cout << "You entered: " << input << "\n";
    return 0;
}
