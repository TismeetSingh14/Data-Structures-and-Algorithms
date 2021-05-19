//lecture014
#include<iostream>
#include<vector>
using namespace std;

int *set2()
{
    //int *a=new int(10);         /*To allocate new memory on heap use keyword 'new'*/
    //int *a=new int[10];         /*To allocate new memory to an array on heap*/
    int *a=new int[10]; 
    for(int i=0;i<10;i++)
    {
        a[i]=i*10;
    }
    return a;
}

int **set3()
{
    int **a=new int*[10];         /*to allocate new memory for an array of addresses*/
    for(int i=0;i<10;i++)
    {
        a[i]=new int[5];

        for(int j=0;j<5;j++)
        {
            a[i][j]=i*j+1;
        }
    }
    return a;
}

void set1()
{
    int a=10;
    int *b=&a;
    int **c=&b;
    cout<<a<<endl;
    cout<<b<<" "<<&a<<endl;
    cout<<c<<" "<<&c<<endl;

    cout<<*b<<endl;
    cout<<*c<<endl;
    cout<<**c<<endl;
}

void solve()
{
    //set1();
    
    int *a=set2();
    for(int i=0;i<10;i++)
    {
        //cout<<*(a+i)<<" ";
        cout<<a[i]<<" ";
    }

    int **b=set3();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc,char** argv)
{
    solve();
    return 0;
}