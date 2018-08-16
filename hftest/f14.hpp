#ifndef F14_H
#define F14_H

#include <string>
#include <iostream>
#include <stdexcept>

template <class T>
class F14{
    T* a;
    int meret;
public:
    typedef T* iterator;

    F14(){
        meret=0;
        a=new T[meret];
    }
    F14(int mer):meret(mer){
        a=new T[meret];
    }
    F14(int mer, const T& value):meret(mer){
        a=new T[meret];
        for(int i=0;i<meret;i++)
            a[i]=value;
    }
    F14(T *b, T *c){
        a=new T[c-b];
        for(int i = 0; b[i]!=*c;i++){
            a[i]=b[i];
        }
    }
    ~F14() {delete[] a;}

    inline T& front() {return a[0];}

    void push_back(T x){
        T* tmp=new T[meret+1];
        for(int i=0;i<meret;i++)
            tmp[i]=a[i];
        delete[] a;
        a=new T[meret+1];
        for(int i=0;i<meret;i++)
            a[i]=tmp[i];
        a[meret]=x;
        meret+=1;
        delete[] tmp;
    }

    void pop_back(){
        if(!meret) throw std::out_of_range("hiba");
        delete &a[meret-1];
        //delete a+meret-1;
        meret--;
    }

    void resize(int n)
    {
        if(n>meret){
            T* m=new T[n];
            for(int i=0;i<meret;i++)
                m[i]=a[i];
            delete[] a;
            a=new T[n];
            for(int i=0;i<meret;i++)
                a[i]=m[i];
            meret=n;
            delete[] m;
        }else if(n<=meret){
            int kul=meret-n;
            for(int i=0;i<kul;i++)
                pop_back();
        }
    }

    inline T& back(){
        if(!meret) throw std::out_of_range("hiba");
        return a[meret-1];
    }

    T get_back(){
        T l=back();
        pop_back();
        return l;
    }

    inline T* begin(){
        return a;
    }

    inline T* end(){
        return &a[meret];
    }

};

template<>
int F14<int>::get_back(){
    int l=back()-28;
    pop_back();
    return l;
}

template<>
std::string F14<std::string>::get_back(){
    return "Bozi Roland Sa'ndor,1MI,I16,L1B <boziroland99@gmail.com> EO7EGE\n";
}

template <class T>
class osFunctor{
    std::ostream& os;
    const char* delim;
public:
    osFunctor(std::ostream& os, const char* a=""):os(os),delim(a){}
    void operator()(T& a){ os << a << delim;}
};
#endif