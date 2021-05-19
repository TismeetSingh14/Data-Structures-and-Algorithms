//lecture005
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//PROGRAM 1
//TAKING INPUT IN AN ARRAY
void input(vector<int> &arr)
{
    cout << "input" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

//DISPLAY ELEMENTS IN AN ARRAY
void display(vector<int> &arr)
{
    cout << "output" << endl;
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}

//PROGRAM 2
//FINDING DATA IN AN ELEMENT
int find(vector<int> &arr, int data)
{
    int i, k, flag = 0;
    for (i = 0; i < arr.size(); i++)
    {
        if (arr[i] == data)
        {
            flag = 1;
            k = i;
        }
    }
    if (flag)
    {
        return k;
    }
    else
    {
        cout << "not found";
    }
}

//PROGRAM 3
//FINDING MAXIMUM ELEMENT IN AN ARRAY
int maxele(vector<int> &arr)
{
    int a = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        a = arr[i] > a ? arr[i] : a;
    }
    return a;
}

//PROGRAM 4
//FINDING MINIMUM ELEMENT IN AN ARRAY
int minele(vector<int> &arr)
{
    int a = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        a = arr[i] < a ? arr[i] : a;
    }
    return a;
}

//PROGRAM 5
//ROTATING AN ARRAY BY r
//ROTATE 1 2 3 4 5 BY 2
//OUTPUT-> 3 4 5 1 2
void reverse(vector<int> &arr, int s, int e)
{
    for (int i = s, j = e; i <= j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void rotate(vector<int> &arr, int r)
{
    r = r % arr.size();
    r = r < 0 ? r + arr.size() : r;
    reverse(arr, 0, r - 1);
    reverse(arr, r, arr.size() - 1);
    reverse(arr, 0, arr.size() - 1);
    display(arr);
}

//PROGRAM 6
//GIVEN AN ARRAY REPRESENTING LINES.FIND TWO LINES WHICH CAN TRAP THE MAXIMUM AMOUNT OF WATER
int maxrainwater(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    int maxwater = 0;
    while (i < j)
    {
        if (arr[i] > arr[j])
        {
            maxwater = max((j - i) * arr[j], maxwater);
            j--;
        }

        else
        {
            maxwater = max(arr[i] * (j - i), maxwater);
            i++;
        }
    }

    return maxwater;
}

//PROGRAM 7
//IMPLEMENTING BINARY SEARCH
int binarysearch(vector<int> &arr, int data)
{
    int li = 0;
    int ui = arr.size() - 1;
    while (li <= ui)
    {
        int mid = (li + ui) / 2;
        if (arr[mid] > data)
        {
            ui = mid - 1;
        }
        else if (arr[mid] < data)
        {
            li = mid + 1;
        }
        else
        {
            return mid;
        }
        return -1;
    }
}

//PROGRAM 8
//FINDING LOWERBOUND INDEX
int lowerbs(vector<int> &arr, int data)
{
    int li = 0;
    int ui = arr.size() - 1;
    while (li <= ui)
    {
        int mid = (li + ui) / 2;
        if (arr[mid] > data)
        {
            ui = mid - 1;
        }
        else if (arr[mid] < data)
        {
            li = mid + 1;
        }
        else
        {
            if (mid - 1 >= 0 && arr[mid - 1] == arr[mid])
            {
                ui = mid - 1;
            }
            else
            {
                return mid;
            }
        }
    }
    return -1;
}

//PROGRAM 9
//FINDING UPPERBOUND INDEX
int upperbs(vector<int> &arr, int data)
{
    int li = 0;
    int ui = arr.size() - 1;
    while (li <= ui)
    {
        int mid = (li + ui) / 2;
        if (arr[mid] > data)
        {
            ui = mid - 1;
        }
        else if (arr[mid] < data)
        {
            li = mid + 1;
        }
        else
        {
            if (mid + 1 < arr.size() && arr[mid + 1] == data)
            {
                li = mid + 1;
            }
            else
            {
                return mid;
            }
        }
    }
    return -1;
}

//PROGRAM 10
//FINDING ELEMENT WHICH IS CLOSEST TO THE GIVEN DATA
int closeelebs(vector<int> &arr, int data)
{
    int li = 0;
    int ui = arr.size() - 1;
    if (arr[ui] < data)
    {
        return arr[ui];
    }
    if (arr[li] > data)
    {
        return arr[li];
    }
    while (li <= ui)
    {
        int mid = (li + ui) / 2;
        if (arr[mid] > data)
        {
            ui = mid - 1;
        }
        else if (arr[mid] < data)
        {
            li = mid + 1;
        }
        else if (arr[mid] == data)
        {
            return mid;
        }
    }

    if (data - arr[ui] > arr[li] - data)
    {
        return arr[li];
    }
    else if (data - arr[ui] <= arr[li] - data)
    {
        return arr[ui];
    }
    return -1;
}

//PROGRAM 11
//TO FIND TWO NUMBERS WHOSE SUM EQUALS TARGET
void targetsumdoublet(vector<int> &arr, int target)
{
    int li = 0;
    int ui = arr.size() - 1;
    while (li < ui)
    {
        int sum = arr[li] + arr[ui];
        if (sum == target)
        {
            cout << "(" << arr[li] << "," << arr[ui] << ")";
            li++;
            ui--;
        }
        else if (sum < target)
        {
            li++;
        }
        else
        {
            ui--;
        }
    }
}

//PROGRAM 12
//TO FIND THREE NUMBERS WHOSE SUM EQUALS TARGET
void targetsumtriplet(vector<int> &arr, int target, int li, int ui, int i)
{
    while (li < ui)
    {
        int sum = arr[li] + arr[ui];
        if (sum == target)
        {
            cout << "(" << arr[i] << "," << arr[li] << "," << arr[ui] << ")";
            li++;
            ui--;
        }
        else if (sum < target)
        {
            li++;
        }
        else
        {
            ui--;
        }
    }
}

//PROGRAM 13
//GIVEN A ROW OF SHOES IN PAIRS FIND THE INDEX AND THE SHOE THAT IS MISSING(i.e NOT IN PAIR)
void missingshoe(vector<int> &arr)
{
    int li = 0;
    int ri = arr.size() - 1;
    while (li < ri)
    {
        int mid = (li + ri) / 2;
        if (mid % 2 != 0)
        {
            if (arr[mid] == arr[mid - 1])
            {
                li = mid + 1;
            }
            else
            {
                ri = mid - 1;
            }
        }

        else
        {
            if (arr[mid] == arr[mid + 1])
            {
                li = mid + 2;
            }
            else
            {
                ri = mid;
            }
        }
    }
    cout << li << " " << arr[li];
}

//PROGRAM 14
//FIND THE PIVOT POINT IN THE ARRAY
int fluctuationpoint(vector<int> &arr)
{
    int li = 0;
    int ri = arr.size() - 1;

    while (li < ri)
    {
        int mid = (li + ri) / 2;
        bool leftset = arr[mid] > arr[li] ? true : false;
        bool rightset = arr[mid] < arr[ri] ? true : false;

        if ((!leftset && rightset) || (!leftset && !rightset))
        {
            ri = mid;
        }

        else if ((leftset && !rightset) || (leftset && rightset))
        {
            li = mid;
        }
    }

    return li;
}

//MAIN
int main(int argc, char **argv)
{
    /*vector<int> arr(7,0);
    input(arr);
    display(arr);*/
    //cout<<"found at "<<find(arr,4);
    //cout<<endl<<maxele(arr);
    //cout<<endl<<minele(arr);
    //rotate(arr,2);
    //cout<<endl<<binarysearch(arr,2);
    //cout<<endl<<lowerbs(arr,2);
    //cout<<endl<<upperbs(arr,2);
    //cout<<endl<<closeelebs(arr,18);
    //targetsumdoublet(arr,16);
    /*for(int i=0;i<arr.size();i++)
    {
        targetsumtriplet(arr,6-arr[i],i+1,arr.size()-1,i);
    }*/
    /*vector<int>arr(14,0);
    input(arr);
    missingshoe(arr);*/
    vector<int> arr = {8, 9, 10, 1, 2, 3, 4, 5, 6};
    cout << fluctuationpoint(arr);
}