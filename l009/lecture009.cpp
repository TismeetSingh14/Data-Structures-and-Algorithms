//lecture009
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//PROGRAM 1
//TO TAKE INPUT IN AN ARRAY USING RECURSION
void input(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return;
    }

    cin >> arr[i];
    input(arr, i + 1);
}

//TO DISPLAY ELEMENTS IN AN ARRAY USING RECURSION
void display(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return;
    }

    cout << arr[i] << " ";
    display(arr, i + 1);
}

//PROGRAM 2
//TO FIND MAXIMUM ELEMENT IN AN ARRAY USING RECURSION
int maxele(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return INT_MIN;
    }

    int M = arr[i];
    return M = maxele(arr, i + 1) > M ? maxele(arr, i + 1) : M;

    //int recans=maxele(arr,i+1);
    //return max(arr[i],recans);
}

//PROGRAM 3
//TO FIND MINIMUM ELEMENT IN ARRAY USING RECURSION
int minele(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return INT_MAX;
    }

    //int m=arr[i];
    //return m=minele(arr,i+1)<m?maxele(arr,i+1):m;

    int recans = minele(arr, i + 1);
    return min(arr[i], recans);
}

//PROGRAM 4
//TO FIND ELEMENT IN AN ARRAY USING RECURSION
bool find(vector<int> &arr, int i, int data)
{
    if (i == arr.size())
    {
        return false;
    }

    if (arr[i] == data)
    {
        return true;
    }

    return find(arr, i + 1, data);
}

//PROGRAM 5
//TO FIND INDEX OF ELEMENT IN AN ARRAY USING RECURSION
int findindex(vector<int> &arr, int i, int data)
{
    if (i == 0)
    {
        return -1;
    }

    if (arr[i] == data)
    {
        return i;
    }

    return findindex(arr, i - 1, data);
}

//PROGRAM 6
//TO RETURN VECTOR CONTAINING ALL THE INDICES OF A GIVEN ELEMENT IN AN ARRAY
vector<int> allindex(vector<int> &arr, int i, int data, int count)
{
    if (i == arr.size())
    {
        vector<int> base(count, 0);
        return base;
    }

    if (arr[i] == data)
    {
        count++;
    }

    vector<int> ans = allindex(arr, i + 1, data, count);
    if (arr[i] == data)
    {
        ans[count - 1] = i;
    }
    return ans;
}

//PROGRAM 7
//TO FIND THE INVERSE OF AN ARRAY
void inverse(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return;
    }
    int val = arr[i];
    inverse(arr, i + 1);
    arr[val] = i;
}

//MAIN
int main(int argc, char **argv)
{
    vector<int> arr(5, 0);
    input(arr, 0);
    //display(arr,0);
    //cout<<maxele(arr,0);
    //cout<<minele(arr,0);
    //cout<<find(arr,0,5);
    //cout<<findindex(arr,arr.size()-1,5);
    //vector<int>myans=allindex(arr,0,5,0);
    //display(myans,0);
    //inverse(arr,0);
    //display(arr,0);
}