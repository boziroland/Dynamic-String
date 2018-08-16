#include "f10.h"
#include <cstring>

F10::F10() : line(NULL), len(0)
{
    
}

F10::F10(const F10& a)
{
    if(this != &a && a.len>0)
    {
        len=a.len;
        line= new char[len];
        strcpy(line,a.line);
    }
}

F10& F10::operator=(const F10& a)
{
    if(this != &a && a.len>0)
    {
        len=a.len;
        delete[] line;
        line= new char[len];
        strcpy(line,a.line);
    }
    return *this;
}

F10::~F10()
{
    delete[] line;
}

const char* F10::ident() const
{
    return "Bozi Roland Sa'ndor,1MI,I16,L1B <boziroland99@gmail.com> EO7EGE\n";
}

bool F10::match(const char *line)
{
   //    alap 
   //    detekciot 
   //    szinuk 
   for(int i = 0; line[i]!='\0';i++)
   {
       if(line[i]=='a' && line[i+1]=='l' && line[i+2]=='a' && line[i+3]=='p')
        {
            this->len=strlen(line)+1;
            if(this->line!=NULL) delete[] this->line;
            this->line=new char[this->len];
            strcpy(this->line,line);
            return true;
        }
       if(line[i]=='d' && line[i+1]=='e' && line[i+2]=='t' && line[i+3]=='e' && line[i+4]=='k' && line[i+5]=='c' && line[i+6]=='i' && line[i+7]=='o' && line[i+8]=='t')
        {
            this->len=strlen(line)+1;
            if(this->line!=NULL) delete[] this->line;
            this->line=new char[this->len];
            strcpy(this->line,line);
            return true;
        }
        if(line[i]=='s' && line[i+1]=='z'&& line[i+2]=='i'&& line[i+3]=='n'&& line[i+4]=='u'&& line[i+5]=='k')
        {
            this->len=strlen(line)+1;
            if(this->line!=NULL) delete[] this->line;
            this->line=new char[this->len];
            strcpy(this->line,line);
            return true;
        }
   }
   return false;
}

const char* F10::getLine() const
{
    return line;
}