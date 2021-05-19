#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int bucketSize = 0;
vector<int> buckets, arr;

//COMPLEXITY OF UPDATE FUNCTION IS O(1)
void updateAnswer(int idx, int val)
{
    buckets[idx / bucketSize] = buckets[idx / bucketSize] - arr[idx] + val;
    arr[idx] = val;
}

//COMPLEXITY OF UPDATE FUNCTION IS O(sqrt(N))
int queryAnswer(int left, int right)
{
    int sum = 0;
    while (left % bucketSize != 0 && left <= right)
        sum += arr[left ++];

    while (left + bucketSize <= right) 
    {
        sum += buckets[left/bucketSize];
        left += bucketSize;
    } 

    while (left <= right)
        sum += arr[left++];

    return sum;    
}

void solve()
{
    int n;
    cin >> n;
    bucketSize = (int)sqrt(n);
    arr.resize(n,0);
    buckets.resize(bucketSize + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        buckets[i / bucketSize] += a;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int left, right;
            cin >> left >> right;
            cout << queryAnswer(left, right) << endl;
        }

        if (c == 0)
        {
            int idx, val;
            cin >> idx >> val;
            updateAnswer(idx, val);
        }
    }
}

int main(int argc, char **argv)
{
    int t;
    cin >> t;
    while (t--)
        solve();
}