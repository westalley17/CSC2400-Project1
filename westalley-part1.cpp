#include <iostream>
using namespace std;

int main(int size, char *nums[])
{
    // edge case if no numbers were typed in the CLI.
    if (size == 1)
    {
        cout << "No arguments were given.";
        return -1;
    }
    // edge case if more than 2 numbers were typed in the CLI.
    else if (size > 3)
    {
        cout << "Too many arguments were given.";
        return -1;
    }

    // main code

    int num1 = abs(stoi(nums[1])); // makes it to where our GCD is always positive.
    int num2 = abs(stoi(nums[2]));

    // edge case if numbers provided cause a math error.
    if (num1 == 0 && num2 == 0)
    {
        cout << "There is no GCD of 0 and 0!";
        return -1;
    }
    // edge cases if either one of the inputs are 0.
    else if (num1 == 0)
    {
        cout << num2 << " is the GCD!";
        return 0;
    }
    else if (num2 == 0)
    {
        cout << num1 << " is the GCD!";
        return 0;
    }
    // this is the normal case that does the Extended Euclidean method.
    else
    {
        int coeff1, coeff2, u, v, quotient, remainder, m, n; // u,v,m, and n are temp variables.
        coeff1 = 0, coeff2 = 1, u = 1, v = 0;
        while (num1 != 0)
        {
            quotient = num2 / num1;
            remainder = num2 % num1;
            m = coeff1 - u * quotient;
            n = coeff2 - v * quotient;
            num2 = num1;
            num1 = remainder;
            coeff1 = u;
            coeff2 = v;
            u = m;
            v = n;
        }
        cout << "GCD is: " << num2 << endl
             << "The coefficients of the inputs needed to create the GCD are: " << coeff1 << " and " << coeff2;
        return 0;
    }
}