/** 
 * * Classes and function/operator overloading: 
 * 
 * ? (a) For the MathVector class above, show how the square brackets operator (indexing operator) 
 * ? can be overloaded to return a given indexed element. Should this operator be a class member 
 * ? function, and if so will it be private or public?
 * 
 * 
 * ? (b) Explain how the * operator can be overloaded to enable expressions such as αv, vα, and u ∗ v 
 * ? (which we take to mean the cross-product, which you need only implement for 3-vectors), where u 
 * ? and v are vectors and α is a scalar.
 * 
 */
 

#include <vector>
#include <iostream>
#include <sstream>

class MathVector
{
    public:
        MathVector(int _length) 
        {   
            length = _length;
            elements.resize(length);
        };

        MathVector(int _length, double _elements[])
        {   
            length = _length;
            elements.resize(length);
            
            for (int i = 0; i < length; i++)
            {
                elements[i] = _elements[i];
            }; // ? easier ways to initialize vector from array. using c++ 98 so probably not?
        };

        MathVector(const MathVector & that)
        {
            elements = that.elements;
            length = that.length;
        };

        
        // * ======================== changes ============================

        // removed previous display() function


        double & operator[](const int & index) 
        {
            return elements[index];
        };
        
        /**
         * this overloading of [] must be a member function, as syntax.
         * 
         * it should be a public function, as other member function have
         * access the 'elements' vector in the first place.
         */


        int getLength()
        {
            return length;
        };

        std::string display()
        {
            std::stringstream ss;

            ss << "[";
            for (int i = 0; i < getLength() - 1; i++)
            {
                ss << (*this)[i] << ", ";
            }
            ss << (*this)[getLength()];

            ss << "]";

            return ss.str();
        }
        // * ==============================================================

    private:
        std::vector<double> elements;
        int length;
        
};


// * ======================== changes ============================

MathVector operator*(const double &a, MathVector &b)
{
    MathVector that(b);

    for (int i = 0; i < that.getLength(); i++)
    {
        that[i] = b[i] * a;
    }

    return that;
};

MathVector operator*(MathVector &a, const double &b)
{
    MathVector that(a);

    for (int i = 0; i < that.getLength(); i++)
    {
        that[i] = a[i] * b;
    }

    return that;
};

MathVector operator*(MathVector &a, MathVector &b) // ! only valid if MathVector a, b are three dimensional.
{
    double t1 = a[2] * b[3] - a[3] * b[2];
    double t2 = a[3] * b[1] - a[1] * b[3];
    double t3 = a[1] * b[2] - a[2] * b[1]; 
    
    double t[3] = {t1, t2, t3};
    MathVector that(3, t);

    return that;
};

std::ostream & operator<<(std::ostream & os, MathVector & a)
{
    os << a.display();
    return os;
}
// * ==============================================================



int main()
{
    double array[3] = {1, 2, 3};

    MathVector a(3, array);
    double b = 2;

    MathVector c1 = a * b;
    MathVector c2 = b * a;
    MathVector c3 = a * a;
    
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
};