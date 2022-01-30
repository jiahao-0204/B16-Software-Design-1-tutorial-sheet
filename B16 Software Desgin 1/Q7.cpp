/** 
 * * Access control and const: 
 * Consider the code given below. The two class definitions contain the same data.
 * 
 * 
 * 
 * ? (a) Discuss the benefits and drawbacks of each implementation.
 * 
 * the differences between the two implementaiton is on the visibility of data member p. 
 * A has private p and have a getter method. 
 * B has a public p and thus do not need a getter method.
 * 
 * A have stricter data control, the value of p is unchangable after instantiation, thus safer.
 * however, it does require a getter function to be implemented.
 * 
 * B has more convenient data access method, allows both read and write. 
 * however, whoever have access to the instance can alter its data member, less safe
 * 
 * 
 * 
 * ? (b) A fellow engineer presents you with the definitions of the following functions, 
 * ? without giving you access to the implementation. What will you know about input 
 * ? parameter b after each of them are called?
 * 
 * i. void fn_i(BernoulliDistributionA & b); 
 * won't change
 * 
 * ii. void fn_ii(BernoulliDistributionA *& b);
 * won't change
 * 
 * 
 * 
 * iii. void fn_iii(const BernoulliDistributionB & b); 
 * won't change
 * 
 * iv. void fn_iv(BernoulliDistributionB & b); 
 * p can be changed
 * 
 * v. void fn_v(BernoulliDistributionB b);
 * won't change
 * 
 */


class BernoulliDistributionA
{
    private: // default class member are private
        float p;

    public:
        BernoulliDistributionA (float _p) : p(_p) {};
        float getProbability() const 
        {
            return p;
        }
};


class BernoulliDistributionB
{
    public:
        BernoulliDistributionB(float _p) : p(_p) {};
        float p;
};

