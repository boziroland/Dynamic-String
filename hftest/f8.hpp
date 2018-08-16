#ifndef F8_HPP 
#define F8_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>

template <unsigned int T>
class F8 
{
    public:
        double vec[T];
        unsigned int cap;

        F8(){cap=0;}
        ~F8(){}

        F8& operator=(F8& a)
        {
            cap=a.cap;
            for(unsigned int i=0;i<cap;i++)
            {
                vec[i]=a.vec[i];
            }
            return *this;
        }

        double& operator[](unsigned int n)
        {
            if (n>=T) throw std::out_of_range("out_of_range");
            if (n>=cap) cap++;
            return vec[n];    
        }

        void rendez()
        {
            unsigned int i, j;
            for (i = 0; i < cap-1; i++)//T-1        
                for (j = 0; j < cap-i-1; j++)//T-i-1 
                    if (vec[j] > vec[j+1])
                    {
                        double tmp = vec[j];
                            vec[j] = vec[j+1];
                            vec[j+1] = tmp;
                    }
        }
        const char* c_str() { return "Bozi Roland Sa'ndor,1MI,I16,L1B <boziroland99@gmail.com> EO7EGE\n"; }
};   

template <unsigned int T>
std::ostream& operator<<(std::ostream& os, F8<T>& a)
    {
        os << std::fixed;
        os << std::setprecision(4) << a.vec[22] << std::endl;
        os << std::setprecision(4) << a.vec[16] << std::endl;
        os << std::setprecision(4) << a.vec[79] << std::endl;
        os << std::setprecision(4) << a.vec[78] << std::endl;
        os << std::setprecision(4) << a.vec[412] << std::endl;
        return os;
    }

#endif
