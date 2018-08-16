#include "dstring.h"
#include <cstring>
#include <cctype>

namespace MyStr
{

static void Mystrcopy(char *to, const char *from)
{
    for (int i = 0; i < 20; i++)
        to[i] = from[i];
       // strcpy(to,from);
}

void MyString::read(std::istream& is)
{   
    size_t len;
    std::cout << "Milyen hosszu lesz a sztring? ";
    is >> len;
    char* str=new char[len+1];
    std::cout << "Sztring tartalma: ";
    is >> str;
    str[len]=0;
    *this=MyString(str);
    delete[] str;
}

void MyString::write(std::ostream& os)
{
    size_t len = size();
    os << len << ',';
    const char* str= c_str();
    os << str << std::endl;
    delete[] str;
}

/////////////////////////////// MyString

MyString::MyString()
{
    elso = NULL;
}

MyString::MyString(char c)
{
    elso = new Cell;
    elso->tomb[0]=c;
    elso->kov=NULL;
}
MyString::MyString(const char* str)
{
    Cell *tmp = elso, *elo = NULL;
    int i = 0;
    while (str[i])
    {
        if (i % 20 == 0)
        {
            if (i==0)
            {
                elso = new Cell();
                tmp = elso;
                tmp->elo=NULL;
            }
            else
            {
                elo = tmp;
                tmp->kov = new Cell();
                tmp = tmp->kov;
                tmp->elo = elo;
            }
            tmp->kov = NULL;
        }
        tmp->tomb[i%20]=str[i];
        i++;
    }
}

MyString::MyString(const MyString& rhs){
    Cell* tmp, *tmprhs, *tmpelo=NULL;
    elso=new Cell();
    tmp=elso;
    tmprhs=rhs.elso;
    if(rhs.elso==NULL) elso=NULL;
    else{
        while(tmprhs->kov!=NULL){
         //   Mystrcopy(tmp->tomb,tmprhs->tomb);
            for(int i=0;i<20;i++) tmp->tomb[i]=tmprhs->tomb[i];
            tmprhs=tmprhs->kov;
            tmpelo=tmp;
            tmp->kov=new Cell;
            tmp=tmp->kov;
            tmp->elo=tmpelo;
        }
    }
   // Mystrcopy(tmp->tomb,tmprhs->tomb);
    for(int i=0;tmprhs->tomb[i]!='\0';i++) tmp->tomb[i]=tmprhs->tomb[i];
    tmp->kov=NULL;
}

MyString::~MyString(){
    Cell* tmp=elso;
    while(elso!=NULL){
        tmp=elso->kov;
        delete elso;
        elso=tmp;
    }
}

size_t MyString::size()
{
    if(elso==0) return 0;
    size_t ossz=0;
    Cell* tmp=elso;
    for(; tmp->kov!=NULL; tmp=tmp->kov)
        ossz+=20;
    for(int i=0; tmp->tomb[i]!='\0'&&i<20; i++)
        ossz++;
    return ossz;
}

void MyString::clear()
{
    Cell *tmp;
    while (elso != NULL)
    {
        tmp = elso->kov;
        delete elso;
        elso = tmp;
    }
    elso = NULL;
}

size_t MyString::capacity()
{
    size_t ossz = 0;
    for (Cell *tmp = elso; tmp != NULL; tmp = tmp->kov)
        ossz++;
    return ossz*20;
}

bool MyString::empty()
{
    return size()==0;
}

MyString::Iterator MyString::begin() const
{
    return MyString::Iterator(this, elso, 0);
}

MyString::Iterator MyString::end() const
{
    MyString::Iterator a(this, elso, 0);
    while (a.value() != 0)
        a++;
    return a;
}


////////////////////////////
//MyString op =
MyString& MyString::operator=(const MyString &rhs)
{
    clear();
    Cell* tmp, *tmprhs, *tmpelo=NULL;
    elso=new Cell();
    tmp=elso;
    tmprhs=rhs.elso;
    if(rhs.elso==NULL) elso=NULL;
    else{
        while(tmprhs->kov!=NULL){
            Mystrcopy(tmp->tomb,tmprhs->tomb);
            tmprhs=tmprhs->kov;
            tmpelo=tmp;
            tmp->kov=new Cell;
            tmp=tmp->kov;
            tmp->elo=tmpelo;
        }
    }
    Mystrcopy(tmp->tomb,tmprhs->tomb);
    tmp->kov=NULL;
    return *this;
}

char MyString::at(unsigned int a){
    if(a>size())
        throw "hiba";
    else return begin().operator[](a);
}
//////////////////////////
//C sztring op =

MyString &MyString::operator=(const char* str)
{
    clear();
    Cell* tmp = elso, *elo = NULL;
    int i = 0;
    while (str[i])
    {
        if (i % 20 == 0)
        {
            if (i==0)
            {
                elso = new Cell();
                tmp = elso;
            }
            else
            {
                elo = tmp;
                tmp->kov = new Cell();
                tmp = tmp->kov;
            }
            tmp->elo = elo;
            tmp->kov = NULL;
        }
        tmp->tomb[i%20]=str[i];
        i++;
    }
    return *this;
}
//////////////////////////
//karakter op =
MyString &MyString::operator=(char c)
{
    clear();
    elso = new Cell();
    elso->elo = NULL;
    elso->kov = NULL;
    elso->tomb[0] = c;
    return *this;
}
///////////////////////////////

MyString& MyString::operator+=(const MyString& rhs){
    unsigned int i=size(),j=0;
    MyString tmpstr=rhs;
    Cell* tmp=elso, *tmpelo=NULL;
    Cell* tmprhs=tmpstr.elso;
    while(tmp->kov!=NULL)
        tmp=tmp->kov;
    while(tmprhs->tomb[j]||tmprhs->kov!=NULL){
        if(i%20==0){
            tmpelo=tmp;
            tmp->kov=new Cell();
            tmp=tmp->kov;
            tmp->elo=tmpelo;
            tmp->kov=NULL;
        }
        if(j==20){
            tmprhs=tmprhs->kov;
            j=0;
            if(tmprhs==NULL) break;
        }
        tmp->tomb[i%20]=tmprhs->tomb[j];
        i++;
        j++;
    }
    return *this;
}

MyString MyString::operator+(MyString& rhs)
{
    return MyString(*this) += rhs;
}

MyString MyString::operator+(char c)
{
    return MyString(*this) += c;
}

MyString& MyString::operator+=(char c)
{
    return *this += MyString(c);
}

bool MyString::operator==(MyString& rhs)
{
    if (this->size() != rhs.size())
        return false;
    else
    {
        size_t l = this->size();
        for (size_t i = 0; i < l; i++)
            if (this->operator[](i) != rhs[i])
                return false;
    }
    return true;
}

bool MyString::operator!=(MyString& rhs)
{
    return !(*this==rhs);
}

char MyString::operator[](unsigned int a)
{
    return begin().operator[](a);
}

char MyString::operator[](unsigned int a) const
{
    return begin().operator[](a);
}

const char* MyString::c_str()
{
    char *str = new char[size() + 1];
    int i = 0;
    for (Cell *tmp = elso; tmp != NULL; tmp = tmp->kov)
    {
        int x = 0;
        while (tmp->tomb[x] && x < 20)
            str[i++] = tmp->tomb[x++];
        if (x!=20&&!tmp->tomb[x])
            break;
    }
    str[i] = 0;
    return str;
}

std::ostream& operator<<(std::ostream& os,MyString& str)
{
    const char* s = str.c_str();
    os << s;
    delete[] s;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char c;
    MyString s2;
    while (!isspace(c = char(is.get())))
        s2 + c;
    is.putback(c);
    str = s2;
    return is;
}

/////////////////////////////////// iterátor

MyString::Iterator::Iterator(const MyString *s, Cell *c, size_t where)
                            : parent(s), hely(where)
{
    if (c == NULL)
        currentCell = s->elso;
    else
        currentCell = c;
}

char MyString::Iterator::operator[](unsigned int a)
{
    Cell* tmp = currentCell;
    hely+=a;
    while(hely>=20)
    {
        if(tmp->kov!=NULL)
        {
            tmp=tmp->kov;
            hely-=20;
        }
        else throw "rossz index";
    }
    return tmp->tomb[a];
}

MyString::Iterator& MyString::Iterator::operator+=(unsigned int a)
{
   Cell *tmp = currentCell;
    if (a != 0)
    {
            a += hely;
            while (a >= 20)
                if (tmp->kov != NULL){
                    tmp = tmp->kov;
                    a -= 20;
                }
    }
    currentCell = tmp;
    hely = a;
    return *this;
}

char& MyString::Iterator::operator*()
{
    if (hely >= 20)
        throw "tul nagy index";
    return currentCell->tomb[hely];
}

MyString::Iterator& MyString::Iterator::operator-=(unsigned int a)
{
    Cell* tmp= currentCell;
    if(a!=0){
        if(hely>a%20){
            tmp=tmp->elo;
        }
        a-=hely;
        while(a>=20)
            if(tmp->elo!=NULL){
                tmp=tmp->elo;
                a-=20;
            }
            else throw "hiba";
        if(a!=0) a=20-a;
    }
    currentCell=tmp;
    hely=a;
    return *this;
}

MyString::Iterator MyString::Iterator::operator+(unsigned int a){
    Cell* tmp = currentCell;
    if(a!=0){
        a+=hely;
        while(a>=20)
        if(tmp->kov!=NULL){
            tmp=tmp->kov;
            a-=20;
        }
        else throw "hiba";
    }
    return MyString::Iterator(parent,tmp,a);
}

MyString::Iterator MyString::Iterator::operator=(MyString::Iterator &i){
    parent = i.parent;
    currentCell=i.currentCell;
    hely=i.hely;
    return *this;
}

MyString::Iterator MyString::Iterator::operator++()
{
    if(hely==19) {
        if(currentCell->kov==NULL) hely=20;
        else {
            hely=0;
            currentCell = currentCell->kov;
        }
    }else if(hely==20){
        currentCell=currentCell->kov;
        hely=0;
    }
    else hely++;
    return *this;
}

MyString::Iterator MyString::Iterator::operator++(int){
    MyString::Iterator tmp(*this);
    ++(*this);
    return tmp;
}

MyString::Iterator MyString::Iterator::operator--(){
    if(hely==0){
        currentCell=currentCell->elo;
        hely=19;
    }
    else hely--;
    return *this;
}
MyString::Iterator MyString::Iterator::operator--(int)
{
    MyString::Iterator tmp(*this);
    --(*this);
    return tmp;
}
//nagyrészben megegyezik a -= operátorral
MyString::Iterator MyString::Iterator::operator-(unsigned int a)
{
    Cell* tmp= currentCell;
    if(a!=0){
        if(hely>a%20) tmp = tmp->elo;
        a-=hely;
        while(a>=20)
        if(tmp->elo!=NULL){
            tmp=tmp->elo;
            a-=20;
        }
        else throw "hiba";
        if(a!=0) a=20-a;
    }
    return MyString::Iterator(parent,tmp,a);    
}

char MyString::Iterator::value()
{
    if (hely == 20)
        return 0;
    return currentCell->tomb[hely];
}

bool MyString::Iterator::operator<(const MyString::Iterator& i)
{
    if (this->parent != i.parent)
        throw "mas sztringek";
    Cell *tmp = currentCell;
    if (tmp == i.currentCell)
        return hely < i.hely;
    while (tmp != i.currentCell && tmp != NULL)
        tmp = tmp->kov;
    if (tmp == i.currentCell)
        return true;
    return false;
}

bool MyString::Iterator::operator>(const Iterator& i)
{
    return !(*this<=i);
}

bool MyString::Iterator::operator<=(const Iterator& i)
{
    if (this->parent != i.parent)
        throw "nem ugyanaz a string";
    Cell *tmp = currentCell;
    if (tmp == i.currentCell)
        return hely <= i.hely;
    while (tmp != i.currentCell && tmp != NULL)
        tmp = tmp->kov;
    if (tmp == i.currentCell)
        return true;
    return false;
}

bool MyString::Iterator::operator>=(const MyString::Iterator& i)
{
    return !(*this<i);
}

bool MyString::Iterator::operator==(const MyString::Iterator& rhs)
{
    return (currentCell==rhs.currentCell && hely==rhs.hely);
}

bool MyString::Iterator::operator!=(const MyString::Iterator& rhs)
{
    return !(currentCell==rhs.currentCell && hely==rhs.hely);
}

}//namespace MyStr
