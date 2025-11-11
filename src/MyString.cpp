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

MyString::MyString(MyString&& other) noexcept :
    data(other.data){ // member initializer list to avoid unnecesary default initialization
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


MyString MyString::operator+(const MyString& other) const{
    size_t len1 = std::strlen(data);
    size_t len2 = std::strlen(other.data);
    
    char* newData = new char[len1+len2+1];
    std::strcpy(newData,data);
    std::strcat(newData,other.data);
    
    MyString result;
    result.data = newData;
    return result; // return a copy
}


bool MyString::operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

char& MyString::operator[](size_t index){
    return data[index];
}

bool MyString::operator!=(const MyString& other) const {
    return std::strcmp(data,other.data) == 1;
}

size_t MyString::length() const{
    return data ? std::strlen(data) : 0;
}


void MyString::printAddress(){
    std::cout<<*this<<std::endl;
}

std::istream& operator>>(std::istream& cin, MyString& str){
    
    char buffer[1024];
    cin>>buffer;
    
    delete[] str.data;
    
    str.data = new char[std::strlen(buffer) + 1];
    
    std::strcpy(str.data, buffer);
    
    return cin;
    
}


std::ostream& operator<<(std::ostream& os,const MyString& s){ //overriding <<
    if(s.data){
        os<<s.data;
    }else{
        os<<"<empty>";
    }
    return os;
}



