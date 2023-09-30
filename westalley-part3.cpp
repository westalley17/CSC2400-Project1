#include <iostream>

using namespace std;

// Function to find prime factors of a number
int *findPrimeFactors(int num, int &size)
{
    int *factors = new int[100]; // we only allow 100 prime factors, but this number can be changed at any time to accomodate for excessive inputs.
    size = 0;

    while (num % 2 == 0)
    {
        factors[size] = 2;
        size++;
        num /= 2;
    }

    for (int i = 3; i * i <= num; i += 2)
    {
        while (num % i == 0) // Note: This is the same thing as the while loop above.
        {                    // It just does it for factors leading up to the number we are checking.
            factors[size] = i;
            size++;
            num /= i;
        }
    }

    if (num > 2)
    {
        factors[size] = num;
    }

    return factors; // returns all the prime factors of a certain number "n".
}

// Function to calculate GCD using prime factorization
int calculateGCD(int num1, int num2)
{
    int *factorsA;
    int *factorsB;
    int sizeA, sizeB;

    // using dynamic arrays to store factors of numbers because vectors are stinky.
    factorsA = findPrimeFactors(num1, sizeA);
    factorsB = findPrimeFactors(num2, sizeB);

    int gcd = 1;
    int i = sizeA;
    int j = sizeB;

    while (i >= 0 && j >= 0)
    {
        if (factorsA[i] == factorsB[j])
        {
            gcd = factorsA[i];
            break;
        }
        else if (factorsA[i] > factorsB[j])
            i--;
        else
            j--;
    }

    delete[] factorsA;
    delete[] factorsB;

    return gcd;
}

int main()
{
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    num1 = abs(num1);
    cout << "Enter second number: ";
    cin >> num2;
    num2 = abs(num2);
    // edge cases of inputs of 0.
    if (num1 == 0 && num2 == 0)
    {
        cout << "There is no GCD of 0 and 0!";
        return 0;
    }
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

    int gcd = calculateGCD(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}
