// lecture 002
#include <iostream>
using namespace std;

// PROGRAM 1
// USING LOOPS TO FIND FACTORIAL OF A NUMBER
int factorial(int n)
{
    int a = 1;
    for (int i = 1; i <= n; i++)
    {
        a = a * i;
    }
    return a;
}

// PROGRAM 2
// USING FACTORIAL FUNCTION TO FIND nCr
int combination(int n, int r)
{
    int res = factorial(n) / ((factorial(n - r) * factorial(r)));
    return res;
}

//PROGRAM 3
// TO ROTATE A GIVEN NUMBER BY A NUMBER r
// EXAMPLE-> 12345 r=2
// OUTPUT-> 34512
int digits(int n)           //FUNCTION TO FIND NO. OF DIGITS
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int rotationOfNumber(int n, int r)
{
    int div = 1;
    int mul = 1;
    r = r % digits(n);
    r = r < 0 ? r + digits(n) : r;

    for (int i = 1; i <= digits(n); i++)
    {
        if (i <= r)
        {
            mul *= 10;
        }
        else
        {
            div *= 10;
        }
    }
    int a = n / div;
    int b = n % div;
    int res = b * mul + a;
    return res;
}

// PROGRAM 4
// TO CHECK WHETHER A GIVEN NUMBER IS PRIME
bool isPrime(int n)
{
    bool h = true;
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            h = false;
        }
    }
    return h;
}

// PROGRAM 5
// GIVEN n NUMBER OF BULBS, DURING EACH ITERATION THE BULBS AT MULTIPLE OF SAY 1 ARE SWITCHED ON 
// THEN IN THE NEXT ITERATION THE BULBS AT MULTILE OF 2 ARE SWITCHED OFF AND SO ON...
// FIND AFTER n ITERATIONS WHICH BULBS ARE SWITCHED ON.
void bulbs(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        cout << i * i << " ";
    }
}

// MAIN
int main(int argc, char **argv)
{
    // cout<<factorial(5);
    // cout<<combination(5,3);
    // cout<<rotationOfNumber(12345,-1);
    // cout<<isPrime(30);
    // bulbs(40);
}