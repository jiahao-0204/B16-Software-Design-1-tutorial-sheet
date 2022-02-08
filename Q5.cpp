/** 
 * * Constructors
 * 
 * A MathVector class is defined as follows. You can think of std::vector< double > as a list that can 
 * only store doubles. It supports the [] operator for accessing, and has member functions size which 
 * returns its length and resize which changes its length. Further details on this standard class are 
 * available in the recommended text or online.
 * 
 * ? (a) Design and code three constructors (using C++ or pseudo-code if you prefer):
 * ? i. a default constructor taking a single integer indicating the size of the vector; 
 * ? ii. a constructor that takes a length integer and an array of doubles to initialise the values;
 * ? iii. a copy constructor.
 * 
 * ? (b) Give a example usage of each. 
 * 
 * ? (c) Explain the problem that would arise if we used dynamic memory allocation (that is, working with 
 * ? memory on the heap using new) instead of using std::vector<>.
 * 
 * ? (d) [optional, not covered in lectures] What mechanism would be used to overcome the problems arising 
 * ? in part (c)?
 * 
 */

#include <vector>
#include <iostream>

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

        void display()
        {
            for (int i = 0; i < elements.size(); i++)
            {
                std::cout << elements[i] << std::endl;
            }
        }

    private:
        std::vector<double> elements;
        int length;
};



int main()
{
    // ? (a) i
    MathVector a(3);

    // ? (a) ii
    double bb[3] = {1, 2, 3};
    MathVector b(3, bb);

    // ? (a) iii
    MathVector c(b);


    // ? (b)
    a.display();
    b.display();
    c.display();

    /**
     * ? (c) 
     * - have to take care of the memory
     * - we can not change size of the array after it is initialized. 
     */

    /**
     * ? (d)
     * - a destructor
     * - we can initialize a new array with the size desired and copy the data over
     */

}