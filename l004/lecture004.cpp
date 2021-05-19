//lecture004
#include <iostream>
using namespace std;

//PROGRAM 1
//CONVERTING DECIMAL NUMBER TO BINARY
int dectobin(int n)
{
    int a, r = 0;
    int pow = 1;
    while (n != 0)
    {
        a = n % 2;
        r = r + a * pow;
        n = n / 2;
        pow *= 10;
    }
    return r;
}

//PROGRAM 2
//CONVERTING BINARY TO DECIMAL
int bintodec(int n)
{
    int pow = 1;
    int a, r = 0;
    while (n != 0)
    {
        a = n % 10;
        r = r + a * pow;
        pow *= 2;
        n = n / 10;
    }
    return r;
}

//PROGRAM 3
//CONVERTING DECIMAL TO ANY BASE
int dectoany(int n, int base)
{
    int a, r = 0;
    int pow = 1;
    while (n != 0)
    {
        a = n % base;
        r = r + a * pow;
        pow *= 10;
        n = n / base;
    }
    return r;
}

//PROGRAM 4
//CONVERTING ANY BASE TO DECIMAL
int anytodec(int n, int base)
{
    int a, r = 0;
    int pow = 1;
    while (n != 0)
    {
        a = n % 10;
        r = r + a * pow;
        pow *= base;
        n = n / 10;
    }
    return r;
}

//PROGRAM 5
//ADDING TWO OCTAL NUMBERS
int octaladd(int n1, int n2)
{
    int down, carry = 0;
    int res = 0, pow = 1;
    while (n1 != 0 || n2 != 0 || carry > 0)
    {
        int sum = n1 % 10 + n2 % 10 + carry;
        carry = sum / 8;
        down = sum % 8;
        res = res + down * pow;
        n1 /= 10;
        n2 /= 10;
        pow *= 10;
    }
    return res;
}

//PROGRAM 6
//SUBTRACTING TWO OCTAL NUMBERS
int octalsub(int n1, int n2)
{
    int a, b, res = 0, pow = 1;
    if (n1 < n2)
    {
        b = n1;
        a = n2;
    }
    else
    {
        a = n1;
        b = n2;
    }

    while (a != 0 || b != 0)
    {
        int dif = a % 10 - b % 10;
        a /= 10;
        b /= 10;
        if (dif < 0)
        {
            dif = dif + 8;
            a--;
        }
        res = res + dif * pow;
        pow *= 10;
    }
    return res = n1 < n2 ? res * (-1) : res;
}

//MAIN
int main(int argc, char **argv)
{
    //cout<<dectobin(11);
    //cout<<bintodec(1010);
    //cout<<dectoany(10,2);
    //cout<<anytodec(1011,2);
    //cout<<octaladd(234,147);
    //cout<<octalsub(234,147);
}