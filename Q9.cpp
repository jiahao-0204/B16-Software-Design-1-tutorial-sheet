/**
 * * Polymorphism: 
 * 
 * The box below shows the definitions of a small C++ class hierarchy.
 * 
 * 
 * ? (a) Draw a diagram showing the class hierarchy.
 * 
 * Foo
 * └── Bar
 * 
 * 
 * ? (b) Determine what output the code will produce, describing carefully how you 
 * ? reach your conclusions.
 * 
 * doit1(foo);
 * - passed in by value. 
 * - results are Foo::f() and Foo::g()
 * 
 * doit1(bar);
 * - passed in by value, since signiture specified Foo, only the Foo part of bar will
 *   be passed in.
 * - results are Foo::f() and Foo::g() 
 * 
 * doit2(foo);
 * - passed in by reference. 
 * - results are Foo::f() and Foo::g()
 * 
 * 
 * doit2(bar); 
 * - passed in by reference, thus content of the Bar class is passed in as well. 
 * - results are Foo::f() and Bar::g()
 * - the first one because signiture is Foo, member function in Foo will be considered first
 * - the second one is because the member function in Foo is labeled virtual, thus the one
 *   in Bar will be used instead.
 * 
 * 
 * 
 * 
 * ? (c) Test a real implementation to verify your answer.
 * 
 * implementation supports answer given
 * 
 * 
 * 
 * ? (d) Identify which parameters are passed by value and which by reference. Taking 
 * ? account of the meaning of this, and what will be stored in the activation record 
 * ? when doit1 and doit2 are called, explain the result.
 * 
 * doit1 by value
 * doit2 by reference
 * 
 * for doit1, only parts that are Foo will be stored in the activation record
 * for doit2, all parts will be stored in the activation record.
 * 
 */








 /** 
 * if an object is passed as its parent class
 * 
 * - we can only use interface defined in the parent class, we have 
 *   lost access to all interface/property defined by the children 
 *   class
 * 
 * - if passed by value, all children class is lost
 * - if passed by reference, content in the children class is kept, 
 *   but only accessible if corresponding parent class interface is 
 *   labeled virtual
 */








#include <iostream>
#include <string>

class Foo
{
    public:
        void f()
        {
            std::cout << "Foo::f()" << std::endl;
        };

        virtual void g()
        {
            std::cout << "Foo::g()" << std::endl;
        }
};

class Bar : public Foo 
{
    public:
        void f() 
        { 
            std::cout << "Bar::f()" << std::endl; 
        }
        
        virtual void g() 
        { 
            std::cout << "Bar::g()"; 
        }
};


void doit1(Foo f) 
{
    f.f();
    f.g(); 
};


void doit2(Foo & f) 
{
    f.f();
    f.g(); 
};


int main() 
{
    Foo foo;
    Bar bar;
    doit1(foo);
    doit1(bar);
    doit2(foo);
    doit2(bar);

    return 0; 
};