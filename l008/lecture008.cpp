//lecture008
#include <iostream>
using namespace std;

//PROGRAM 1
//BASIC RECURSION TO PRINT NUMBERS TILL N IN INCREASING ORDERF
void increasingorder(int n)
{
    if (n == 0)
    {
        return;
    }
    increasingorder(n - 1);
    cout << n << " ";
}

//PROGRAM 2
//BASIC RECURSION TO PRINT NUMBERS UPTO N IN DECREASING ORDER
void decreasingorder(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    decreasingorder(n - 1);
}

//PROGRAM 3
//TO PRINT FIRST N/2 EVEN NUMBERS AND THEN N/2 ODD NUMBERS USING RECURSION
void evenodd(int n)
{
    if (n == 0)
    {
        cout << "base" << n << " ";
        return;
    }
    if (n % 2 == 0)
    {
        cout << "pre" << n << " ";
    }
    evenodd(n - 1);
    if (n % 2 != 0)
    {
        cout << "post" << n << " ";
    }
}

//PROGRAM 4
//TO FIND FACTORIAL OF A NUMBER USING RECURSION
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

//PROGRAM 5
//TO FIND Nth FIBONACCI NUMBER USING RECURSION
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//PROGRAM 6
//TO FIND A RAISED TO THE POWER B O(n) METHOD
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * power(a, b - 1);
}

//PROGRAM 7
//TO FIND A RAISED TO THE POWER B O(log(n)) METHOD
int powerbetter(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    int ans = powerbetter(a, b / 2);
    ans = ans * ans;

    return (ans = b % 2 != 0 ? ans * a : ans);
}

//MAIN
int main(int argc, char **argv)
{
    //increasingorder(8);
    //decreasingorder(8);
    //evenodd(10);
    //cout<<factorial(5);
    //cout<<fibonacci(5);
    //cout<<power(2,3);
    //cout<<powerbetter(2,3);
}