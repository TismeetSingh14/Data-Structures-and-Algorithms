//lecture011
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// PROGRAM 1
// TO PRINT ALL SUBSEQUENCES OF A STRING
int subsequences(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char ch = s[0];
    int count = 0;

    count += subsequences(s.substr(1), ans + ch);
    count += subsequences(s.substr(1), ans);

    return count;
}

// PROGRAM 2
// TO PRINT ALL SUBSEQUENCES OF A STRING WITH THEIR ASCII VALUES
int asciisubsequences(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    char ch = s[0];
    int n = (char)ch;
    int count = 0;

    count += asciisubsequences(s.substr(1), ans + ch);
    count += asciisubsequences(s.substr(1), ans + to_string(n));
    count += asciisubsequences(s.substr(1), ans);

    return count;
}

//SET 1
void basic()
{
    // cout<<subsequences("abc","");
    // cout<<asciisubsequences("abc","");
}

// PROGRAM 3
// TO PRINT ALL PERMUTATIONS OF A STRING
int permutationwithrepitition(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        count += permutationwithrepitition(s.substr(0, i) + s.substr(i + 1), ans + ch);
    }

    return count;
}

// PROGRAM 4
// TO PRINT ALL PERMUTATIONS OF A STRING WITH NO REPITITION
int permutationwithoutrepitition(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    vector<int> arr(26, 0);
    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (arr[s[i] - 'a'] == 0)
        {
            arr[s[i] - 'a'] = 1;
            count += permutationwithoutrepitition(s.substr(0, i) + s.substr(i + 1), ans + ch);
        }
    }

    return count;
}

// PROGRAM 5
// TO PRINT ALL PERMUTATIONS OF A STRING WITH NO REPITITION (WITH BITMASKING)
int permutationwithoutrepititionbitmasking(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    int num = 0;

    for (int i = 0; i < s.length(); i++)
    {
        int mask = 1 << s[i] - 'a';
        char ch = s[i];
        if ((num & mask) == 0)
        {
            num = (num | mask);
            count += permutationwithoutrepititionbitmasking(s.substr(0, i) + s.substr(i + 1), ans + ch);
        }
    }

    return count;
}

// PROGRAM 6
// NOKIA KEYPAD STRING DECODING VOID TYPE
int nokiakeypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    vector<string> words = {"_", "+-/", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "*()%", "#"};
    int idx = s[0] - '0';
    char n = s[0];
    string word = words[idx];
    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        count += nokiakeypad(s.substr(1), ans + ch);
    }

    if (s.length() > 1 && n != '0')
    {
        int num = idx * 10 + (s[1] - '0');
        if (num < 12)
        {
            string word1 = words[num];
            for (int i = 0; i < word1.length(); i++)
            {
                char ch = word1[i];
                count += nokiakeypad(s.substr(2), ans + ch);
            }
        }
    }

    return count;
}

// PROGRAM 7
// DECODING STRING WITH MAPPING A-1 B-2 C-3 ..... Y-25 Z-26
int mapping(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    int idx = s[0] - '0';
    char ch = s[0];

    if (idx == 0)
        return mapping(s.substr(1), ans);

    char ch1 = (char)(idx - 1) + 'a';
    count += mapping(s.substr(1), ans + ch1);

    if (s.length() > 1 && ch != '0')
    {
        int num = idx * 10 + (s[1] - '0');
        if (num < 27)
        {
            char ch2 = (char)(num - 1) + 'a';
            count += mapping(s.substr(2), ans + ch2);
        }
    }

    return count;
}

// SET 2
void permutation()
{
    // cout<<permutationwithrepitition("abc","");
    // cout<<permutationwithoutrepitition("213","");
    // cout<<permutationwithoutrepititionbitmasking("213","");
    // cout<<nokiakeypad("234","");
    // cout<<mapping("128","");
}

// PROGRAM 8
// TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL AND VERTICAL)
int mazepath2dir(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    if (sc + 1 <= ec)
    {
        count += mazepath2dir(sr, sc + 1, er, ec, ans + "h");
    }

    if (sr + 1 <= er)
    {
        count += mazepath2dir(sr + 1, sc, er, ec, ans + "v");
    }

    return count;
}

// PROGRAM 9
// TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL, DIAGONAL AND VERTICAL)
int mazepath3dir(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    if (sc + 1 <= ec)
    {
        count += mazepath3dir(sr, sc + 1, er, ec, ans + "h");
    }

    if (sr + 1 <= er)
    {
        count += mazepath3dir(sr + 1, sc, er, ec, ans + "v");
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazepath3dir(sr + 1, sc + 1, er, ec, ans + "d");
    }

    return count;
}

// PROGRAM 10
// TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL, DIAGONAL AND VERTICAL) MULTI MOVE
int mazepath3dirmultimove(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 1; i <= ec; i++)
    {
        if (sc + i <= ec)
        {
            count += mazepath3dirmultimove(sr, sc + i, er, ec, ans + "h" + to_string(i));
        }
    }

    for (int i = 1; i <= er; i++)
    {
        if (sr + i <= er)
        {
            count += mazepath3dirmultimove(sr + i, sc, er, ec, ans + "v" + to_string(i));
        }
    }

    for (int i = 1; i <= min(er, ec) + 1; i++)
    {
        if (sc + i <= ec && sr + i <= er)
        {
            count += mazepath3dirmultimove(sr + i, sc + i, er, ec, ans + "d" + to_string(i));
        }
    }

    return count;
}

//SET 3
void mazepath()
{
    // cout<<mazepath2dir(0,0,20,23,"");
    // cout<<mazepath3dir(0,0,2,2,"");
    // cout<<mazepath3dirmultimove(0,0,2,2,"");
}

// PROGRAM 11
// TO PRINT ALL SUBSETS OF A SET THAT SUM UP TO THE TARGET
int targetsumallset(vector<int> &arr, int target, int idx, string ans)
{
    if (idx == arr.size() || target == 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            count += targetsumallset(arr, target - arr[i], i + 1, ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

// PROGRAM 12
// TO PRINT ALL SUBSETS OF A SET THAT SUM UP TO THE TARGET USING SUBSEQUENCES APPROACH
int targetsumallsetsubsequences(vector<int> &arr, int target, int idx, string ans)
{
    if (idx == arr.size() || target == 0)
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (target - arr[idx] >= 0)
    {
        count += targetsumallsetsubsequences(arr, target - arr[idx], idx + 1, ans + to_string(arr[idx]) + " ");
    }

    count += targetsumallsetsubsequences(arr, target, idx + 1, ans);

    return count;
}

// PROGRAM 13
// TO DIVIDE A SET INTO TWO SETS SUCH THAT THEIR SUM IS EQUAL,
// THEIR INTERSECTION IS A NULL SET AND THEIR UNION IS THE SET ITSELF
int equiset(vector<int> &arr, int idx, int set1, int set2, string ans1, string ans2)
{
    if (arr.size() == idx)
    {
        if (set1 == set2)
        {
            cout << ans1 << "=" << ans2 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    count += equiset(arr, idx + 1, set1 + arr[idx], set2, ans1 + to_string(arr[idx]) + " ", ans2);
    count += equiset(arr, idx + 1, set1, set2 + arr[idx], ans1, ans2 + to_string(arr[idx]) + " ");

    return count;
}

//SET 4
void sets()
{
    // vector<int>arr={1,3,5,7,0};
    // cout<<targetsumallset(arr,6,0,"");
    // cout<<targetsumallsetsubsequences(arr,100,0,"");
    // cout<<equiset(arr,1,10,0,"10 ","");
}

//MAIN
int main(int argc, char **argv)
{
    // basic();
    // permutation();
    // mazepath();
    // sets();
}