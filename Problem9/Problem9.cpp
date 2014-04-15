/*
Project Euler, Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>

int main(){

    int a = 0, b = 0, c = 0;
    int s = 1000;
    bool found = false;

/* This For loop tests for a + b + c = 1000. When it finds a situation where that is  true,
    It tests to see if it is a Pythagorean triplet. Since we know that b has to greater then A,
    We set it's value to a in the second loop. */

    for(a = 1; a < s / 3; a++){
        for(b = a + 1; b < s / 2; b++){
            c = s - a - b;
            if(a*a + b*b == c*c){
                found = true;
            break;
            }
        }
        if(found)
            break;
    }

    std::cout << a << "+" << b << "+" << c << "+" << a+b+c << " " << "\n"; //Verify conditions of problem are met.
    std::cout << a * b * c; // Display the Product of a+b+c

return 0;
}
