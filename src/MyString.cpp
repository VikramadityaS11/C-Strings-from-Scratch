//
//  MyString.cpp
//  MyString
//
//  Created by Vikramaditya Sharma on 02/11/25.
//

#include "MyString.hpp"

MyString::MyString(){
    std::cout << "Default ctor\n";
    data = nullptr;
}

MyString::~MyString(){ // called automatically after main()
    std::cout << "Destructor\n";
    delete[] data;
}



MyString::MyString(const char* str){
    std::cout << "C-string ctor\n";
    if(str){
        size_t len = std::strlen(str);
        data = new char[len + 1];
        std::strcpy(data, str);
    } else {
        data = nullptr;
    }
}


//copy contructor, purpose -> to create a new copy of b when MyString b = a
MyString::MyString(const MyString& other){
    std::cout << "Copy ctor\n";
    if(other.data){
        size_t len = std::strlen(other.data);
        data = new char[len+1];
        std::strcpy(data, other.data);
    } else data=nullptr;
}

//copy assmt, purpose -> to create copy when we do b = a
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

// purpose -> called when handling temporary rvalues
MyString::MyString(MyString&& other) noexcept : data(other.data){
    std::cout << "Move ctor\n";;
    other.data = nullptr;
}

// purpose -> calledh when when you assign to an existing object from something that’s temporary or being moved from
MyString& MyString::operator=(MyString&& other) noexcept{
    std::cout << "Move assignment\n";
    if (this != &other){
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

//Concat
MyString MyString::operator+(const MyString& other) const{
    size_t len1 = data ? std::strlen(data) : 0;
    size_t len2 = other.data ? std::strlen(other.data) : 0;

    
    char* newData = new char[len1+len2+1];
    if (data) std::strcpy(newData, data);
    else newData[0] = '\0';
    
    if (other.data) std::strcat(newData, other.data);

    MyString result;
    result.data = newData;
    return result;
}

//+=
MyString& MyString::operator+=(const MyString& other){
    if(!other.data) return *this;
    size_t len1 = data ? std::strlen(data) : 0;
    size_t len2 = std::strlen(other.data);
    char* newData = new char[len1 + len2 + 1];
    if (data){
        std::strcpy(newData,data);
    } else{
        newData[0] = '\0';
    }
    std::strcat(newData, other.data);
    delete[] data;
    data = newData;
    return *this;
}

//==
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(data, other.data) == 0;
}

//purpose -> indexing
char& MyString::operator[](size_t index){
    return data[index];
}
//purpose -> indexing const
const char& MyString::operator[](size_t index) const {
    return data[index];
}


//Not equal to
bool MyString::operator!=(const MyString& other) const {
    return std::strcmp(data,other.data) != 0;
}


//Length
size_t MyString::length() const{
    return data ? std::strlen(data) : 0;
}


//CIN
std::istream& operator>>(std::istream& cin, MyString& str){
    char buffer[1024];
    cin>>buffer;
    delete[] str.data;
    str.data = new char[std::strlen(buffer) + 1];
    std::strcpy(str.data, buffer);
    return cin;
}

//COUT
std::ostream& operator<<(std::ostream& os,const MyString& s){ //overriding <<
    if(s.data){
        os<<s.data;
    }else{
        os<<"<empty>";
    }
    return os;
}



