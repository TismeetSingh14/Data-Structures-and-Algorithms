//lecture003
#include <iostream>
#include <vector>
using namespace std;

//PROGRAM 1
/*
TO PRINT THE PATTERN
        *
       ** 
      *** 
     **** 
    ***** 
*/
void mirrortriangle(int rows)
{
    int nst = 1;
    int nsp = rows - 1;
    for (int r = 0; r < rows; r++)
    {
        for (int csp = 0; csp < nsp; csp++)
        {
            cout << " ";
        }
        for (int cst = 0; cst < nst; cst++)
        {
            cout << "*";
        }
        cout << endl;
        nst++;
        nsp--;
    }
}

//PROGRAM 2
/*
TO PRINT THE PATTERN
    *
    ** 
    *** 
    **** 
    ***** 
*/
void triangle(int rows)
{
    int nst = 1;
    int nsp = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int csp = 0; csp < nsp; csp++)
        {
            cout << " ";
        }
        for (int cst = 0; cst < nst; cst++)
        {
            cout << "*";
        }
        cout << endl;
        nst++;
        nsp--;
    }
}

//PROGRAM 3
/*
TO PRINT THE PATTERN
        *
       *** 
      *****    
     ******* 
    ********* 
*/
void pyramid(int rows)
{
    int nst = 1;
    int nsp = rows - 1;
    for (int r = 0; r < rows; r++)
    {
        for (int csp = 0; csp < nsp; csp++)
        {
            cout << " ";
        }
        for (int cst = 0; cst < nst; cst++)
        {
            cout << "*";
        }
        cout << endl;
        nst = nst + 2;
        nsp--;
    }
}

//PROGRAM 4
/*
TO PRINT THE PATTERN
        1   
       232
      34543
     4567654
    567898765
     4567654
      34543
       232
        1    
*/
void diamond(int rows)
{
    int nst = 1;
    int nsp = rows / 2;
    for (int r = 1; r <= rows; r++)
    {
        int c = 1;
        if (r >= (rows + 1) / 2)
        {
            c = rows - r + 1;
        }

        else
        {
            c = r;
        }

        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << " ";
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << c;

            if (cst > nst / 2)
            {
                c--;
            }

            else
            {
                c++;
            }
        }

        if (r > rows / 2)
        {
            nst = nst - 2;
            nsp++;
        }

        else
        {
            nst = nst + 2;
            nsp--;
        }

        cout << endl;
    }
}

//PROGRAM 5
/*
TO PRINT THE PATTERN
        1
      1  1
    1  2  1
  1  3  3  1
1  4  6  4  1    
*/
void pascaltriangle(int rows)
{
    int nst = 1;
    int nsp = rows - 1;
    for (int r = 0; r < rows; r++)
    {
        for (int csp = 0; csp < nsp; csp++)
        {
            cout << "  ";
        }

        int val = 1;
        for (int cst = 0; cst < nst; cst++)
        {
            cout << val << "  ";
            val = (val * (r - cst)) / (cst + 1);
        }
        cout << endl;
        nst = nst + 1;
        nsp--;
    }
}

//PROGRAM 6
/*
TO PRINT THE PATTERN
    0 1 1 2 3 5 8 13 21
*/
void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    int c = a + b;
    cout << a << " " << b << " ";
    for (int i = 1; i <= n - 2; i++)
    {
        cout << c << " ";
        a = b;
        b = c;
        c = a + b;
    }
}

//PROGRAM 7
/*
TO PRINT THE PATTERN
        *
       *** 
      *****    
     ******* 
    ********* 
     *******
      *****
       ***
        *     
*/
void stardiamond(int rows)
{
    int nst = 1;
    int nsp = rows / 2;
    for (int r = 1; r <= rows; r++)
    {
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << " ";
        }
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*";
        }
        if (r > rows / 2)
        {
            nst = nst - 2;
            nsp++;
        }
        else
        {
            nst = nst + 2;
            nsp--;
        }
        cout << endl;
    }
}

//MAIN
int main(int argc, char **argv)
{
    //mirrortriangle(5);
    //triangle(5);
    //pyramid(5);
    //diamond(9);
    //pascaltriangle(5);
    //fibonacci(7);
    //stardiamond(7);
}