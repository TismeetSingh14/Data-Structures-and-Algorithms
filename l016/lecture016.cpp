#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>
using namespace std;

//PROGRAM 1
//TO FIND Kth LARGEST ELEMENT IN AN ARRAY
void downheapify(vector<int> &arr, int idx, int lidx)
{
	int max_idx = idx;
	int lci = 2 * idx + 1;
	int rci = 2 * idx + 2;

	if (lci <= lidx && arr[lci] > arr[max_idx])
	{
		max_idx = lci;
	}

	if (rci <= lidx && arr[rci] > arr[max_idx])
	{
		max_idx = rci;
	}

	if (max_idx != idx)
	{
		swap(arr[idx], arr[max_idx]);
		downheapify(arr, max_idx, lidx);
	}
}

int findKthLargest(vector<int> &arr, int k)
{
	int n = arr.size() - 1;

	for (int i = n; i >= 0; i--)
	{
		downheapify(arr, i, n);
	}

	for (int i = 0; i < k; i++)
	{
		swap(arr[0], arr[n - i]);
		downheapify(arr, 0, n - i - 1);
	}

	return arr[n - k + 1];
}

//PROGRAM 2
//TO FIND Kth LARGEST ELEMENT IN A STREAM
class KthLargest
{
public:
	priority_queue<int, vector<int>, greater<int>> pq;
	int size;
	KthLargest(int k, vector<int> &nums)
	{
		size = k;

		for (int ele : nums)
		{
			pq.push(ele);

			if (pq.size() > k)
				pq.pop();
		}
	}

	int add(int val)
	{
		pq.push(val);
		if (pq.size() > size)
			pq.pop();

		return pq.top();
	}
};

//PROGRAM 3
//K MOST FREQUENT ELEMENTS IN AN ARRAY REFER LEETOCDE 347 
vector<int> topKFrequent(vector<int> &nums, int k)
{
	unordered_map<int, int> map;
	for (int ele : nums)
		map[ele]++;

	// first -> freq, second -> number and by default it is min PQ.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (pair<int, int> key : map)
	{
		pq.push({key.second, key.first});
		if (pq.size() > k)
			pq.pop();
	}

	vector<int> ans;
	while (pq.size() != 0)
	{
		ans.push_back(pq.top().second);
		pq.pop();
	}
	return ans;
}

//PROGRAM 4
//FIND MEDIAN IN A DATA STREAM REFER LEETCODE
class MedianFinder {
public:
    priority_queue<int> smallerPQ;                            // max PQ, isme hme chote number daalne hai
															  // jiska top in sabka max ho
															  // iska size n/2 se zyada nhi hona chahiye
															   
    priority_queue<int, vector<int>, greater<int>> greaterPQ; // min PQ, isme hme bade number daalne hai
															  // jiska top in sabka min ho
															  // iska size n/2 ya n/2 + 1 se zyada nhi hona chahiye

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (smallerPQ.size() == 0 || smallerPQ.top() > num) // chote number daalna hai
            smallerPQ.push(num);
        else												// bada number daalna hai
            greaterPQ.push(num);

        if (smallerPQ.size() > (greaterPQ.size() + 1))      // smallerPQ ka size maintain karna hai n/2
															// isliye smallerPQ se pop krwa ke greaterPQ mein dala
        {
            greaterPQ.push(smallerPQ.top());
            smallerPQ.pop();
        }
        else if (smallerPQ.size() < greaterPQ.size())       // smallerPQ ka size maintain karna hai n/2
															// isliye greaterPQ se pop krwa ke smallerPQ mein dala
        {
            smallerPQ.push(greaterPQ.top());
            greaterPQ.pop();
        }
    }

    double findMedian()
    {
        if (smallerPQ.size() == greaterPQ.size())
            return smallerPQ.size() == 0 ? 0 : (smallerPQ.top() + greaterPQ.top()) / 2.0;
        else
            return smallerPQ.top();
    }
};

int main(int argc, char **argv)
{
	vector<int> arr = {2, 5, 2, 6, 7, 7, 2, 6, 6, 9, 1, 0, -1, 8};
	cout << findKthLargest(arr, 4);
	return 0;
}