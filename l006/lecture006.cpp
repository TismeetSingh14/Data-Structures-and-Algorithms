//lecture006
#include <iostream>
#include <vector>
using namespace std;

//PROGRAM 1
//TO TAKE INPUT IN A 2D ARRAY
void input(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cin >> arr[i][j];
        }
    }
}

//TO DISPLAY A 2D ARRAY
void display(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//PROGRAM 2
//TO PRINT A 2D ARRAY IN A HORIZONTAL WAVE FASHION
void waveprinthorizontal(vector<vector<int>> &arr)
{
    for (int r = 0; r < arr.size(); r++)
    {
        if (r % 2 == 0)
        {
            for (int i = 0; i < arr[0].size(); i++)
            {
                cout << arr[r][i] << " ";
            }
        }
        else
        {
            for (int i = arr[0].size() - 1; i >= 0; i--)
            {
                cout << arr[r][i] << " ";
            }
        }
    }
}

//PROGRAM 3
//TO PRINT A 2D ARRAY IN A VERTICAL WAVE FASHION
void waveprintvertical(vector<vector<int>> &arr)
{
    for (int r = 0; r < arr[0].size(); r++)
    {
        if (r % 2 == 0)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i][r] << " ";
            }
        }
        else
        {
            for (int i = arr.size() - 1; i >= 0; i--)
            {
                cout << arr[i][r] << " ";
            }
        }
    }
}

//PROGRAM 4
//TO PRINT A 2D ARRAY BY MOVING IN A SPIRAL FASHION
void spiralprint(vector<vector<int>> &arr)
{
    int minr = 0, minc = 0;
    int maxr = arr.size() - 1, maxc = arr[0].size() - 1;
    int tne = (maxr + 1) * (maxc + 1);
    while (tne != 0)
    {
        for (int i = minc; i <= maxc && tne != 0; i++)
        {
            cout << arr[minr][i] << " ";
            tne--;
        }
        minr++;
        for (int i = minr; i <= maxr && tne != 0; i++)
        {
            cout << arr[i][maxc] << " ";
            tne--;
        }
        maxc--;
        for (int i = maxc; i >= minc && tne != 0; i--)
        {
            cout << arr[maxr][i] << " ";
            tne--;
        }
        maxr--;
        for (int i = maxr; i >= minr && tne != 0; i--)
        {
            cout << arr[i][minc] << " ";
            tne--;
        }
        minc++;
    }
}

//PROGRAM 5
/*TO FIND THE EXITPOINT IN A MATRIX FILLED WITH 0s AND 1s
WHENEVER YOU ENCOUNTER A 1 YOU HAVE TO TAKE A RIGHT TURN*/
void exitpoint(vector<vector<int>> &arr)
{
    int dir = 0;
    int r = 0;
    int c = 0;
    while (true)
    {
        dir = (dir + arr[r][c]) % 4;
        if (dir == 0)
        {
            c++;
            if (c == arr[0].size())
            {
                cout << r << "," << (c - 1);
                break;
            }
        }
        else if (dir == 1)
        {
            r++;
            if (r == arr.size())
            {
                cout << (r - 1) << "," << c;
                break;
            }
        }
        else if (dir == 2)
        {
            c--;
            if (c == -1)
            {
                cout << r << "," << (c + 1);
                break;
            }
        }
        else
        {
            r--;
            if (r == -1)
            {
                cout << (r + 1) << "," << c;
                break;
            }
        }
    }
}

//PROGRAM 6
//TO DETERMINE TRANSPOSE OF A MATRIX
void transpose(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr[0].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

//TO SWAP COLUMNS OF A 2D MATRIX
void swapC(vector<vector<int>> &arr)
{
    int c1 = 0;
    int c2 = arr[0].size() - 1;
    while (c1 < c2)
    {

        for (int r = 0; r < arr.size(); r++)
        {
            swap(arr[r][c1], arr[r][c2]);
        }

        c1++;
        c2--;
    }
}

//TO SWAP ROWS OF A 2D MATRIX
void swapR(vector<vector<int>> &arr)
{
    int r1 = 0;
    int r2 = arr.size() - 1;
    while (r1 < r2)
    {
        swap(arr[r1], arr[r2]);
        r1++;
        r2--;
    }
}

//TO ROTATE A MATRIX 90 DEGREES IN CLOCKWISE AND ANTICLOCKWISE DIRECTIONS
void rotate90(vector<vector<int>> &arr, bool isClockWise)
{
    transpose(arr);
    if (isClockWise)
        swapC(arr);
    else
        swapR(arr);
    display(arr);
}
//MAIN
int main(int argc, char **argv)
{
    /*int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    input(arr);
    display(arr);*/
    //waveprinthorizontal(arr);
    //waveprintvertical(arr);
    //spiralprint(arr);
    //exitpoint(arr);
    //rotate90(arr,false);
}