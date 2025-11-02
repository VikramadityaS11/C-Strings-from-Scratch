//
//  MyString.cpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//

#include "MyString.hpp"
MyString::MyString(){
    data = nullptr;
}

std::ostream& operator<<(std::ostream& os,const MyString&){
    os<<"<empty>";
    return os;
}

