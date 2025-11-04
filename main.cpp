//
//  main.cpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//

#include <iostream>
#include "MyString.hpp"

int main(int argc, const char * argv[]) {
    
    //copy constructor test
    MyString a("Hello");
    MyString b = a;
    std::cout<<&b<<std::endl;
    std::cout<<&a<<std::endl;
    
    
    //Copy assignment test
    MyString c("World");
    c.printAddress();
}
