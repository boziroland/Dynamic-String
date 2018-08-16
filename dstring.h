#ifndef DSTRING_H
#define DSTRING_H

#include <iostream>
#include <cstdio>

namespace MyStr
{
struct Serialize
{
    Serialize() {}
    virtual ~Serialize() {}
    virtual void read(std::istream& is)=0;
    virtual void write(std::ostream& os)=0;
};

class MyString : public Serialize
{
public:
    class Cell
    {
    public:
        char tomb[20];
        Cell* elo;
        Cell* kov;
        inline Cell(){for(int i=0; i<20; i++) tomb[i]=0;}
        ~Cell() {}
    };

    class Iterator
    {
        const MyString* parent;
        Cell* currentCell;
        unsigned int hely;
    public:
        Iterator(const MyString *s, Cell *c, size_t where);
        char operator[](unsigned int);
        Iterator& operator+=(unsigned int);
        Iterator& operator-=(unsigned int);
        Iterator operator+(unsigned int);
        Iterator operator-(unsigned int);
        Iterator operator=(Iterator &i);
        Iterator operator++();
        Iterator operator++(int);
        Iterator operator--(int);
        Iterator operator--();
        char& operator*();
        char value();
        bool operator>(const Iterator&);
        bool operator<(const Iterator&);
        bool operator<=(const Iterator&);
        bool operator>=(const Iterator&);
        bool operator==(const Iterator&);
        bool operator!=(const Iterator&);
        inline bool lastInCell() {return (hely==20);}
        inline Cell* getCell(){return currentCell;}
    };

    Cell* elso;
    MyString();
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& rhs);
    virtual ~MyString();
    virtual void read(std::istream&);
    virtual void write(std::ostream&);
    const char* c_str();
    size_t size();
    void clear();
    size_t capacity();
    bool empty();
    Iterator begin() const;
    Iterator end() const;
    MyString& operator=(const MyString& rhs);
    MyString& operator=(const char*);
    MyString& operator=(char);
    MyString operator+(MyString&);
    MyString operator+(char);
    MyString& operator+=(const MyString&);
    MyString& operator+=(char);
    bool operator==(MyString&);
    bool operator!=(MyString&);
    char operator[](unsigned int a);
    char operator[](unsigned int a) const;
    char at(unsigned int a);
};
std::ostream& operator<<(std::ostream& os,MyString& str);
std::istream& operator>>(std::istream& is, MyString& str);
}//namespace mystr

#endif
