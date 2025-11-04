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

MyString::~MyString(){ // called automatically after main()
    delete[] data;
}



MyString::MyString(const char* str){
    if(str){
        size_t len = std::strlen(str);
        data = new char[len + 1];
        std::strcpy(data, str);
    } else {
        data = nullptr;
    }
}


//copy contructor
MyString::MyString(const MyString& other){
    if(other.data){
        size_t len = std::strlen(other.data);
        data = new char[len+1];
        std::strcpy(data, other.data);
    } else data=nullptr;
}

//copy assmt
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {               // protect against self-assignment
        delete[] data;                  // free old memory
        if (other.data) {
            size_t len = std::strlen(other.data);
            data = new char[len + 1];
            std::strcpy(data, other.data);
        } else data = nullptr;
    }
    return *this; // to allow chaining a=b=c, returning reference
}

MyString::MyString(MyString&& other) noexcept : data(other.data){
    other.data = nullptr;
}


MyString& MyString::operator=(MyString&& other) noexcept{
    if (this != &other){
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

void MyString::printAddress(){
    std::cout<<*this<<std::endl;
}


std::ostream& operator<<(std::ostream& os,const MyString& s){ //overriding <<
    if(s.data){
        os<<s.data;
    }else{
        os<<"<empty>";
    }
    return os;
}



