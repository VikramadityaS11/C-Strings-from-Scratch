//
//  MyString.hpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//
#pragma once
#include <iostream>
#include <cstring>


class MyString {
public:
    MyString();
    MyString(const char* str);
    ~MyString();
    MyString(const MyString& other);  // copy constructor
    MyString& operator=(const MyString& other); // copy assignment
    MyString(MyString&& other) noexcept;
    MyString& operator=(MyString&& other) noexcept;
    void printAddress();
    friend std::ostream& operator<<(std::ostream&,const MyString&);
private:
    char * data = nullptr;
};
