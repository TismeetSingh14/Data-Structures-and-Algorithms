// lecture 001
#include <iostream>
using namespace std;

// PROGRAM 2
// CALCULATING SIMPLE INTEREST
float simpleInterest(float p, float r, float t)
{
    float si;
    si = (p * r * t) / 100;
    return si;
}

// PROGRAM 3
// LEARNING TO USE LOOPS
void looping(int a)
{
    for (int i = 1; i <= 10; i++)
    {
        cout << a << " ";
        a += 2;
    }
}

// PROGRAM 4
// MORE ON LOOPS BASIC
void nEvenOdd(int n)
{
    cout << "even upto n ";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl
         << "odd upto n ";
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
    }
}

// MAIN
int main(int argc, char **argv)
{
    // PROGRAM 1
    // BASIC PROGRAM
    // cout<<"hello world"<<endl;
    // cout<<simpleInterest(1115,4.5,5);
    // looping(2);
    // nEvenOdd(50);
}