/** 
 * * Function encapsulation and side-effects
 * 
 * ? (a) Explain what are function side-effects and why should they be avoided.
 * when arguments are passed in as pointers or references, the function will gain access to variables outside its scope. 
 * This could pose unpredictable behaviour to function caller outside. could be mitigated by adding const to the function
 * declaration
 * 
 * ? (b) Determine what the code below does, indicate its design flaws, and improve its design and presentation.
 * 
 * ? i. what it does
 * to compute the residue of a number
 * 
 * ? ii. design flaws
 * 1. num and res are declared as global variables, making the code less portable. 
 *    they should be ideally passed in as arguments
 * 2. the coding doesn't have indentation to improve readability 
 * 3. printf function doesn't exists in c++, it is a python function.
 * 
 * ? iii. improvement
 * see below
 * 
 * ? (c) Compile and run the code above and your improved version. Make sure that they produce the same result.
 * ? yes indeed.
 */


#include <iostream>
#include <string>

int calc_res(int num, int den) 
{
    while (num >= 0)
    {
        num = num - den;
    }
    num = num + den;

    int res = num;
    return res;
}

int main()
{
    int num = 10;
    int res = calc_res(10, 4);
    std::cout << res << std::endl;
}












