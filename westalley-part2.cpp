/*

    pseudocode time!
    t = min(n,m)
    while(t != 0)
    {
        if(m % t == 0)
        {
            if(n % t == 0)
                return t;
        }
        t--;
    }
*/

#include <iostream>
using namespace std;

int main(int size, char *nums[])
{
    int num1 = abs(stoi(nums[1]));
    int num2 = abs(stoi(nums[2]));
    int t;
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
    // if else blocks used to assign the minimum variable "t".
    if (num1 > num2)
        t = num2;
    else
        t = num1;
    // this while loop is the consecutive integer method.
    while (t != 0)
    {
        if (num1 % t == 0)
        {
            // this is the case were the GCD is found: t = GCD
            if (num2 % t == 0)
                break;
        }
        t--;
    }
    cout << "GCD is: " << t;
}