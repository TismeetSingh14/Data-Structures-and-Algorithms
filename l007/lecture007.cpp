//lecture007
#include <iostream>
#include <vector>
using namespace std;

//PROGRAM 1
//TO TOGGLE Kth BIT i.e TO SET THE BIT IF UNSET AND VICE VERSA
int toggle_Kthbit(int n, int k)
{
    int mask = (1 << k);
    n = (n ^ mask);
    return n;
}

//PROGRAM 2
//TO SET THE Kth BIT i.e IF UNSET SET IT ELSE LEAVE IT
int set_Kthbit(int n, int k)
{
    int mask = (1 << k);
    n = (n | mask);
    return n;
}

//PROGRAM 3
//TO DETERMINE ODD/EVEN USING BITS
void oddeven(int n)
{
    if ((n & 1) == 0)
        cout << "even";

    if ((n & 1) != 0)
        cout << "odd";
}

//PROGRAM 4
//TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(1st METHOD)
int noofsetbits_01(int n)
{
    int count = 0;

    for (int i = 0; i < 32; i++)
    {
        int mask = (1 << i);

        if ((n & mask) != 0)
            count++;
    }

    return count;
}

//PROGRAM 5
//TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(2nd METHOD)
int noofsetbits_02(int n)
{
    int count = 0;

    while (n != 0 && count < 32)
    {
        if ((n & 1) == 1)
            count++;

        n >>= 1;
    }

    return count;
}

//PROGRAM 6
//TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(3rd METHOD)
int noofsetbits_03(int n)
{
    int count = 0;
    while (n != 0)
    {
        n &= (n - 1);
        count++;
    }

    return count;
}

//PROGRAM 7
//TO FIND UNIQUE NUMBER IN THE ARRAY i.e THE NUMBER OCCURING ONLY ONCE
int uniquenum(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = (ans ^ arr[i]);
    }

    return ans;
}

//PROGRAM 8
//TO FIND UNIQUE NUMBER IN AN ARRAY WHERE EACH NUMBER IS REPEATED K TIMES
int uniquenum_ktimes(vector<int> &arr, int k)
{
    vector<int> bits(32, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < 32; j++)
        {
            int mask = (1 << j);

            if ((arr[i] & mask) != 0)
                bits[j]++;
        }
    }

    int ans = 0;

    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] % k != 0)
        {
            int mask = (1 << i);
            ans |= mask;
        }
    }

    return ans;
}

//MAIN
int main(int argc, char **argv)
{
    //cout<<toggle_Kthbit(2,2);
    //cout<<set_Kthbit(2,3);
    //oddeven(4);
    //cout<<noofsetbits_01(7);
    //cout<<noofsetbits_02(-1);
    //cout<<noofsetbits_03(9);
    vector<int> arr = {1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
    //cout<<uniquenum(arr);
    //cout<<uniquenum_ktimes(arr,3);
}

//=====================================================================

// *********UNIQUE NUMBER 2**********

// #include<iostream>
// #include<vector>
// using namespace std;

// void unique2(vector<int>&arr)
// {
//     int ans=0;

//     for(int i=0;i<arr.size();i++)
//     {
//         ans=(ans^arr[i]);
//     }

//     int temp=ans;
//     int set=-1;

//     for(int i=0;i<32;i++)
//     {
//         int mask=1<<i;

//         if((temp & mask)==1)
//         {
//             set=i;
//             break;
//         }
//     }

//     int ans1=0;

//     for(int i=0;i<arr.size();i++)
//     {
//         int mask=1<<set;

//         if((arr[i] & mask)==1)
//         {
//             ans1=(ans1^arr[i]);
//         }
//     }

//     int ans2=(ans1^temp);

//     if(ans1>ans2)
//     {
//         cout<<ans2<<" "<<ans1;
//     }

//     else
//     {
//         cout<<ans1<<" "<<ans2;
//     }
    
// }

// int main(int argc,char** argv)
// {
//     int n;
//     cin>>n;
//     vector<int>arr(n,0);

//     for(int i=0;i<arr.size();i++)
//     {
//         cin>>arr[i];
//     }

//     unique2(arr);
// }