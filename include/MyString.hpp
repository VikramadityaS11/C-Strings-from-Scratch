//
//  MyString.hpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//
#pragma once
#include <iostream>

class MyString {
public:
    MyString();
    friend std::ostream& operator<<(std::ostream&,const MyString&);
private:
    char * data = nullptr;
};
