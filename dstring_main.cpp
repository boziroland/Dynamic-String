#include <iostream>
#include "dstring.h"
#include "memtrace.h"

using namespace MyStr;
using std::cout;
using std::cin;
using std::endl;

int main(){
    try{
        MyString s1("husznal nagyobb teszt szoveg(41 karakter)");
        MyString s2=s1;
        MyString s3;
        s3=s2;
        cout << s3 << endl;
        MyString c1('c');
        MyString c2=c1;
        MyString c3;
        c3=c2;
        cout << c3 << endl;
        cout << "ures-e s2? " << s2.empty() << endl;
        s2.clear();
        cout << "es most? " << s2.empty() << endl;
        s1+=s1; 
        cout << s1 << endl;
        cout << "s1 merete: "<< s1.size() <<endl;
        cout << "az altala foglalt terulet: " << s1.capacity() <<endl;
        s1.write(cout);
        MyString s4;
        s4.read(cin);
        cout << "s4 tartalma: " << s4 << endl;
        if(s1!=s4) cout << "s1 es s4 kulonbozik" << endl;
        if(s1==s4) cout << "s1 es s4 megegyezik" << endl;
        cout << "s1 elso karaktere: " << s1[0] << endl;
        cout << "s1 elso karatkere at()-tel: " << s1.at(0)<<endl;
        //cout << s1.at(50);//hibat dob
        MyString::Iterator It=s1.begin()+3;
        MyString::Iterator It2=It;
        cout << "s1 4. eleme, a value() fuggvennyel:: " << It.value() << endl;
        cout << "s1 4. eleme, most dereferalva: " << *It <<endl;
        cout << "s1 4. eleme, (poszt-inkremens operátorral): " << *(It++)<<endl;
        cout << "s1 6. eleme: " << *(++It)<<endl;
        if(It>It2) cout << "It nagyobb mint It2"<< endl;
        It+=4;
        if(It>=It2) cout << "It nagyobb egyenlo mint It2"<< endl;
        It++;
        if(It<=It2) cout << "It kisebb egyenlo mint It2"<< endl;
        It--;
        MyString s7;
        s7="teszt";
        MyString c7;
        c7='c';
        MyString s8;
        s8="teszz";
        if(s7==s8) cout << "true"; // file coverage miatt
        const MyString s9="hello"; // file coverage miatt
        cout << "s9 (hello) elso (nulladik) eleme: " << s9[0] << endl;             // file coverage miatt
    }catch(...){
        return -1;
    }
    return 0;
}