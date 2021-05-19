#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//PROGRAM 1
//MAP BASICS
void mapBasics()
{
    unordered_map<string, int> m;
    m["Ind"] = 100;
    m["Eng"] = 80;
    m["USA"] = 85;
    m["Spain"] = 75;

    cout << m["ind"] << endl;
    cout << m.count("ind") << endl;

    if (m.find("ind") != m.end())
        cout << m["ind"] << endl;

    for (pair<string, int> key : m)
        cout << key.first << " = " << key.second << endl;
}

//PROGRAM 2
//TO RETURN THE FREQUENCY OF ALL THE CHARACTERS IN A STRING
void frequencyOfCharacters(string s)
{
    unordered_map<char, int> map;

    for (int i = 0; i < s.length(); i++)
        map[s[i]]++;

    for (pair<char, int> e : map)
        cout << e.first << " - " << e.second << endl;
}

//PROGRAM 3
//TO RETURN THE INDEX OF ALL THE CHARACTERS IN STRING IN THE FORM OF A VECTOR
void indexOfCharacters(string s)
{
    unordered_map<char, vector<int>> map;

    for (int i = 0; i < s.length(); i++)
    {
        if (map.count(s[i]) == 0)
        {
            vector<int> arr;
            map[s[i]] = arr;
        }

        map[s[i]].push_back(i);
    }

    for (auto key : map)
    {
        cout << key.first << " - ";
        for (int i = 0; i < key.second.size(); i++)
            cout << key.second[i] << ", ";
        cout << endl;
    }
}

//PROGRAM 4
//TO FIND INTERSECTION OF TWO ARRAYS CHECK LEETCODE 349
void intersectionOfArrays(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, bool> map;
    vector<int> ans;

    for (int i = 0; i < arr1.size(); i++)
        map[arr1[i]] = true;

    for (int ele : arr2)
    {
        if (map.count(ele) == 1)
        {
            ans.push_back(ele);
            map.erase(ele);
        }
    }

    for (int ele : ans)
        cout << ele << " ";
}

//PROGRAM 5
//TO FIND INTERSECTION OF TWO ARRAYS (ANOTHER VERSION) CHECK LEETCODE 350
void intersectionOfArraysNew(vector<int> &arr1, vector<int> &arr2)
{
    unordered_map<int, int> map;
    vector<int> ans;

    for (int i = 0; i < arr1.size(); i++)
        map[arr1[i]]++;

    for (int ele : arr2)
    {
        if (map.count(ele) == 1 && map[ele] > 0)
        {
            ans.push_back(ele);
            map[ele]--;
        }
    }

    for (int ele : ans)
        cout << ele << " ";
}

//PROGRAM 6
//LONGEST CONSECUTIVE SUBSET/SUBSEQUENCE CHECK LEETCODE 128
int longestConsecutiveSubsequence(vector<int> &arr)
{
    unordered_map<int, int> map;
    for (int ele : arr)
        map[ele]++;

    int len = 0;
    for (int ele : arr)
    {
        if (!map.count(ele))
            continue;

        map.erase(ele);
        int prevEle = ele - 1;
        int nextEle = ele + 1;

        while (map.count(prevEle))
            map.erase(prevEle--);
        while (map.count(nextEle))
            map.erase(nextEle++);

        len = max(len, nextEle - prevEle - 1);
    }

    return len;
}

//PROGRAM 7
//TO FIND LONGEST ARITHMETIC SUBSEQUENCE CHECK LEETCODE
int longestArithSeqLength(vector<int> &arr)
{
    int n = arr.size();
    int len = 0;
    vector<unordered_map<int, int>> dp(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int diff = arr[i] - arr[j];
            int maxEndingHere = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            int maxPrevLen = dp[i][diff];
            dp[i][diff] = max(maxEndingHere, maxPrevLen);
            len = max(len, dp[i][diff]);
        }
    }

    return len;
}

//PROGRAM 8
//TO FIND THE LONGEST SUBARRAY SUM DIVISIBLE BY K
int longestSubArrSumDivK(vector<int> &arr, int k)
{
    if (arr.size() == 0)
        return 0;

    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int rem = sum % k;
        rem = (rem < 0) ? rem + k:rem;

        if(map.count(rem) == 0) 
            map[rem] = i;
        else
            len = max(len, i - map[rem]);
    }

    return len;
}

//PROGRAM 9
//TO FIND THE LARGEST SUBARRAY WITH EQUAL 0s AND 1s
int largestSubarrayWith0s1s(vector<int> &arr)
{
    unordered_map<int,int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;

    for(int i = 0;i< arr.size();i++)
    {
        if(arr[i] == 0)
            sum += -1;
        sum += arr[i];

        if(map.count(sum) == 0)
            map[sum] = i;
        else
            len = max(len,i - map[sum]);         
    }

    return len;
}

//PROGRAM 10
//TO FIND THE NUMBER OF SUBARRAYS WITH EQUAL 0s AND 1s
int countOfSubarraysWith0s1s(vector<int> &arr)
{
    unordered_map<int,int> map;
    int sum = 0;

    for(int i = 0;i< arr.size();i++)
    {
        if(arr[i] == 0)
            sum += -1;
        sum += arr[i];

        map[sum]++;         
    }

    int count = 0;

    for(pair<int,int> key:map)
    {
        if(key.second > 1)
        {
            int smallCount = (key.second*(key.second - 1))/2;
            count += smallCount;
        }
    }

    if(map.count(0))
        count += map[0];

    return count;
}

//PROGRAM 11
//GROUP ANAGRAMS LEETCODE 49
vector<vector<string>> groupAnagrams(vector<string> &arr)
{
    unordered_map<string,vector<int>> map;

    for(string str:arr)
    {
        int freq[26] = {0};

        for(char ch:str)
            freq[ch-'a']++;

        string RLES = "";  //Run Length Encoded String

        for(int i = 0 ;i< 26; i++)
        {
            if(freq[i])
                RLES += (char)(i + 'a') + to_string(freq[i]);
        }  

        map[RLES].push_back(str);  
    }

    vector<vector<string>> ans;

    for(auto key: map)
        ans.push_back(key.second);

    return ans;    
}

void mapProblems()
{
    string s = "abbbab";
    // frequencyOfCharacters(s);
    // indexOfCharacters(s);
    vector<int> arr1 = {1, 1, 1, 1, 2, 2, 2, 3, 5, 4};
    vector<int> arr2 = {1, 2, 2, 2, 2, 3};
    // intersectionOfArrays(arr1,arr2);
    // intersectionOfArraysNew(arr1,arr2);
    // vector<int> arr = {100, 4, 200, 1, 3, 2};
    // cout << longestConsecutiveSubsequence(arr);
    // vector<int> arr = {1,2,3,5,6};
    // cout << longestSubArrSumDivK(arr,3);
    vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
    // cout << largestSubarrayWith0s1s(arr);
    // cout << countOfSubarraysWith0s1s(arr);
}

int main(int argc, char **argv)
{
    // mapBasics();
    mapProblems();
}