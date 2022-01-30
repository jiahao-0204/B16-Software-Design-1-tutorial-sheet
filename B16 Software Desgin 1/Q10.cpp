/**
 * * More Polymorphism: 
 * The box below shows the definitions of a set of C++ classes used for evaluating expressions.
 * 
 * 
 * ? (a) Draw a diagram showing the class hierarchy.
 * 
 * X
 * ├── Y
 * └── Z
 * 
 * ? (b) Determine what output the following code will produce and explain clearly how you arrive 
 * ? at your answer. Hence or otherwise explain polymorphism.
 * 
 * a.PrintValue() will produce -2.5. 
 * Z does not have a PrintValue() function, thus the function is called from its parent. When its parent 
 * calls this function. Since its Eval() is virtual, the Eval() in Z is called. 
 * Producing -2.5
 * 
 * d.PrintValue() will produce 7.5. 
 * Following the same logic above, the PrintValue() will call the Eval() in the child function. arg1 and 
 * arg2 are passed in by reference as class X from class Z. calling eval() on arg1 and arg2 will both call
 * the function in class Z since eval in class X is virtual, returning -2.5 * -3.0 = 7.5
 * 
 * 
 * e.PrintValue() will produce -75.
 * follow the same logic from d, the result will be 7.5 * -10 = -75
 * 
 * 
 * polymorphism allows multiple funcdtion overloading to occurs in the parent and children class. which function 
 * that will be called depend on if the object is passed in as value or as reference, what type it is passed in
 * as, as well as if the function in the parent class is labeled virtual. 
 * 
 * if function labled virtual is to be called, the compiler will look at its children to see if the function had 
 * been overwritten and call the overwritting one. the children part will be cropped away if passed by value as 
 * a parent type, making the parent function no longer overwritten.
 * 
 * 
 * 
 * ? (c) Implement a class Sum and a class Tan that respectively compute a sum of arguments, and 
 * ? the tan of a single argument in radians.
 * 
 * todo - don't understand what this is about?
 * 
 * 
 */

#include <iostream>
#include <string>

class X
{
    public:
        
        virtual double Eval() 
        { 
            return 1.0; 
        }
  
        void PrintValue() 
        { 
            std::cout << Eval() << std::endl; 
        }
};

class Y : public X
{
    public:
        
        Y(X & x1, X & x2) : arg1(x1), arg2(x2) {}
        
        double Eval() 
        { 
            return arg1.Eval() * arg2.Eval(); 
        }

    private:
        
        X & arg1;
        X & arg2;
};

class Z : public X
{
    public:
        
        Z(double v) : val(v) {}
        
        double Eval() 
        { 
            return -val; 
        }

    private:
        
        double val;
};



int main()
{
    Z a(2.5), b(3.0), c(10.0);
    Y d(a, b);
    Y e(d, c);
    
    a.PrintValue();
    d.PrintValue();
    e.PrintValue();
}