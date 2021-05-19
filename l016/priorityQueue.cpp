#include <iostream>
#include <vector>
using namespace std;

vector<int> pq;
bool isMax = false;

//DOWNHEAPIFY AND UPHEAPIFY

bool compareTo(int a, int b)
{
    if (isMax)
        return a > b;
    else
        return a < b;
}

void downHeapify(int pi)
{
    int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;
    int maxIdx = pi;

    if (lci < pq.size() && compareTo(pq[lci], pq[maxIdx]))
        maxIdx = lci;

    if (rci < pq.size() && compareTo(pq[rci], pq[maxIdx]))
        maxIdx = rci;

    if (maxIdx != pi)
    {
        swap(pq[maxIdx], pq[pi]);
        downHeapify(maxIdx);
    }
}

void upHeapify(int ci)
{
    int pi = (ci - 1) / 2;
    if (pi >= 0 && compareTo(pq[ci], pq[pi]))
    {
        swap(pq[ci], pq[pi]);
        upHeapify(pi);
    }
}

int top()
{
    return pq[0];
}

void push(int val)
{
    pq.push_back(val);
    upHeapify(pq.size() - 1);
}

void pop()
{
    int n = pq.size() - 1;
    swap(pq[0], pq[n]);
    pq.erase(pq.begin() + n);
    downHeapify(0);
}

void priorityQueueCreation(vector<int> &arr)
{
    for (int ele : arr)
        pq.push_back(ele);

    for (int i = pq.size() - 1; i >= 0; i--)
        downHeapify(i);
}

void display()
{
    for(int ele:pq)
        cout<<ele<<" ";
    cout<<endl;    
}

int main(int argc,char** argv)
{
    vector<int> arr{10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    isMax=false;
    priorityQueueCreation(arr);

    while (pq.size() != 0)
    {
        cout << top() << " ";
        pop();
    }
}