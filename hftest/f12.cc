#include "f12.h"

const char* F2::myId="Bozi Roland Sa'ndor,1MI,I16,L1B <boziroland99@gmail.com> EO7EGE\n";

double F2::f(double X) const{
    if(X>28)
        return X/103.15;
    else
    {
        double eredmeny=0;
        eredmeny = 0.402*X*X*X*X;
        eredmeny -= 0.805*X*X*X;
        eredmeny += 51.50*X*X;
        eredmeny += 12*X;
        eredmeny -= 28;
        return eredmeny;
    }
}
// Konstruktor nullaval lezart stringre mutato pointerrel
// Letrehozza a sort
Queue::Queue(const char *p){
    if(p)
    for(int i=0;p[i]!='\0';i++)
        q.push_back(p[i]);
}

// Kiveszi a sorbol a legutolso karaktert es visszadja azt.
// ha a sor ures underflow_error() kivetelt dob.
//                  throw std::underflow_error("Empty")  
char Queue::pop_back(){
    if(q.empty()) throw std::underflow_error("Empty");
    char lastchar = q.back();
    q.pop_back();
    return lastchar;
}

// A sor elejere tesz egy karaktert
void Queue::push_front(const char c){
    q.push_front(c);
}

// Kiveszi a sorbol a legelso karaktert es visszadja azt.
// ha a sor ures underflow_error() kivetelt dob.
//                  throw std::underflow_error("Empty")  
char Queue::pop_front(){
    if(q.empty()) throw std::underflow_error("Empty");
    char firstchar=q.front();
    q.pop_front();
    return firstchar;
}

// true, ha ures a sor
bool Queue::empty(){
    return q.empty();
}

// Letrehoz egy iteratort es a sor elejere allitja
Queue::myIterator Queue::begin(){
    return q.begin();
}

// Letrehoz egy iteratort es a sor vegere allitja
Queue::myIterator Queue::end(){
    return q.end();
}