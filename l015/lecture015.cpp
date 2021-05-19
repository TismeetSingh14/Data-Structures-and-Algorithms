#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

//PROGRAM 1
//TO FIND THE NEXT GREATER ELEMENT ON THE RIGHT OF ALL THE ELEMENTS IN A VECTOR
vector<int> nextGreaterElementRight(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }

        st.push(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return ans;
}

//PROGRAM 2
//TO FIND THE NEXT SMALLER ELEMENT ON THE RIGHT OF ALL THE ELEMENTS IN A VECTOR
vector<int> nextSmallerElementRight(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }

        st.push(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return ans;
}

//PROGRAM 3
//TO FIND THE NEXT GREATER ELEMENT ON THE LEFT OF ALL THE ELEMENTS IN A VECTOR
vector<int> nextGreaterElementLeft(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] < arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }

        st.push(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return ans;
}

//PROGRAM 4
//TO FIND THE NEXT SMALLER ELEMENT ON THE LEFT OF ALL THE ELEMENTS IN A VECTOR
vector<int> nextSmallerElementLeft(vector<int> &arr)
{
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() != 0 && arr[st.top()] > arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = i;
        }

        st.push(i);
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return ans;
}

//PROGRAM 5
//TO FIND WHETHER THE GIVEN PARENTHESES ARE VALID OR NOT i.e BALANCED PARENTHESES
char closing(char ch)
{
    if (ch == ')')
        return '(';
    if (ch == '}')
        return '{';
    if (ch == ']')
        return '[';
    if (ch == '>')
        return '<';
    return ' ';
}

bool validParentheses_balancedParentheses(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{')
            st.push(s[i]);
        else if (!st.empty())
        {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>')
            {
                if (st.top() != closing(s[i]))
                    return false;
                else if (st.top() == closing(s[i]))
                    st.pop();
            }
        }

        else
            return false;
    }

    if (st.size() != 0)
        return false;
    return true;
}

//PROGRAM 6
//TO REMOVE OUTERMOST PARENTHESES
string removeOutermostParentheses(string s)
{
    int bracketCount = 0;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' && bracketCount++ > 0)
            ans += s[i];
        if (s[i] == ')' && bracketCount-- > 1)
            ans += s[i];
    }

    return ans;
}

//PROGRAM 7
//TO FIND THE LENGTH OF LONGEST SUBSTRING OF BALANCED PARENTHESES
int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLength = INT_MIN;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.top() != -1 && s[i] == ')' && s[st.top()] == '(')
        {
            st.pop();
            int length = i - st.top();
            maxLength = max(maxLength, length);
        }

        else
            st.push(i);
    }

    return maxLength;
}

//PROGRAM 8
//TO FIND THE AREA OF THE LARGEST RECTANGLE IN A HISTOGRAM
int largestRectangleInHistogram(vector<int> &arr)
{
    vector<int> nsol = nextSmallerElementLeft(arr);
    vector<int> nsor = nextSmallerElementRight(arr);
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int area = (nsor[i] - nsol[i] - 1) * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

//PROGRAM 9
//TO FIND THE AREA OF THE LARGEST RECTANGLE IN A HISTOGRAM (OPTIMIZED)
int largestRectangleInHistogramOptimized(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            int idx = st.top();
            st.pop();
            int area = (i - st.top() - 1) * arr[idx];
            maxArea = max(area, maxArea);
        }

        st.push(i);
    }

    while (st.top() != -1)
    {
        int idx = st.top();
        st.pop();
        int area = (arr.size() - st.top() - 1) * arr[idx];
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

//PROGRAM 10
//TO FIND THE MAXIMAL RECTANGLE OF 1s IN A GRID FILLED WITH ONLY 0s AND 1s
int maximalRectangle(vector<vector<char>> &arr)
{
    int maxArea = 0;
    vector<int> height(arr[0].size(), 0);

    if (arr.size() == 0 || arr[0].size() == 0)
        return 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            int val = arr[i][j] - '0';
            if (val == 1)
                height[i]++;

            else
                height[i] = 0;

            int area = largestRectangleInHistogramOptimized(height);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

//PROGRAM 11
//ASTEROID COLLISION LEETCODE
vector<int> asteroidCollision(vector<int> &arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            st.push(arr[i]);
        else
        {
            while (st.size() != 0 && st.top() > 0 && -arr[i] > st.top())
                st.pop();

            if (st.size() != 0 && st.top() == -arr[i])
                st.pop();

            else if (st.size() == 0 || st.top() < 0)
                st.push(arr[i]);
        }
    }

    vector<int> ans(st.size(), 0);

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}

//PROGRAM 12
//TO IMPLEMENT QUEUE USING STACKS (POP EFFICIENT)
class queueStack_1
{
public:
    stack<int> st1;
    stack<int> st2;

    queueStack_1()
    {
    }

    void push(int x)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop()
    {
        if (st1.size() == 0)
            return 0;

        int ele = st1.top();
        st1.pop();
        return ele;
    }

    int front()
    {
        if (st1.size() == 0)
            return 0;
        return st1.top();
    }

    bool empty()
    {
        return st1.size() == 0;
    }
};

//PROGRAM 13
//TO IMPLEMENT QUEUE USING STACKS (PUSH EFFICIENT)
class queueStack_2
{
public:
    stack<int> st1;
    stack<int> st2;

    queueStack_2()
    {
    }

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st1.size() == 0 && st2.size() == 0)
            return 0;

        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ele = st2.top();
        st2.pop();
        return ele;
    }

    int front()
    {
        if (st1.size() == 0 && st2.size() == 0)
            return 0;

        if (st2.size() == 0)
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int ele = st2.top();
        return ele;
    }

    bool empty()
    {
        return st1.size() == 0;
    }
};

//PROGRAM 14
//TO IMPLEMENT STACK USING QUEUES (POP EFFICIENT)
class stackQueue_1
{
public:
    queue<int> q1;
    queue<int> q2;
    int size;

    stackQueue_1()
    {
        size = 0;
    }

    void push(int x)
    {
        size++;

        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        if (q1.size() == 0)
            return 0;

        int ele = q1.front();
        q1.pop();
        size--;
        return ele;
    }

    int top()
    {
        if (q1.size() == 0)
            return 0;
        return q1.front();
    }

    bool empty()
    {
        return q1.size() == 0 && q2.size() == 0;
    }
};

//PROGRAM 15
//TO IMPLEMENT STACK USING QUEUES (PUSH EFFICIENT)
class stackQueue_2
{
public:
    queue<int> q1;
    queue<int> q2;
    int size;

    stackQueue_2()
    {
        size = 0;
    }

    void push(int x)
    {
        size++;
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return 0;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();
        size--;

        queue<int> q = q1;
        q1 = q2;
        q2 = q;

        return ele;
    }

    int top()
    {
        if (q1.empty())
            return 0;

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();
        q2.push(ele);

        queue<int> q = q1;
        q1 = q2;
        q2 = q;

        return ele;
    }

    bool empty()
    {
        return q1.size() == 0 && q2.size() == 0;
    }
};

//PROGRAM 16
//IMPLEMENT A STACK WHICH RETURNS MIN VALUE WHEN getMin IS CALLED
class minStack_1
{
public:
    stack<int> st;
    stack<int> minst;
    int minsf = INT_MAX;

    minStack_1()
    {
    }

    void push(int x)
    {
        st.push(x);
        minst.push(min(minsf, x));
        minsf = minst.top();
    }

    void pop()
    {
        if (st.size() == 0)
            return;

        st.pop();
        minst.pop();

        if (minst.size() != 0)
            minsf = minst.top();

        else
            minsf = INT_MAX;
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minst.top();
    }
};

//PROGRAM 17
//IMPLEMENT A STACK WHICH RETURNS MIN VALUE WHEN getMin IS CALLED (SPACE OPTIMIZED)
class minStack_2
{
public:
    stack<int> st;
    int minsf = 0;
    minStack_2()
    {
    }

    void push(int x)
    {
        int val = x;
        if (st.size() == 0)
        {
            minsf = val;
            st.push(val);
            return;
        }

        if (val > minsf)
        {
            st.push(val);
        }

        else
        {
            st.push(val - minsf + val);
            minsf = val;
        }
    }

    void pop()
    {
        if (st.top() <= minsf)
        {
            minsf = minsf - st.top() + minsf;
        }
        st.pop();
    }

    int top()
    {
        if (st.top() <= minsf)
        {
            return minsf;
        }

        int val = st.top();
        return val;
    }

    int getMin()
    {
        return minsf;
    }
};

//PROGRAM 18
//TO FIND AMOUNT OF RAINWATER STORED BETWEEN BUILDINGS
int rainWaterHarvesting(vector<int> &arr)
{
    vector<int> leftHeight(arr.size(), 0);
    vector<int> rightHeight(arr.size(), 0);

    int prev = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        leftHeight[i] = max(prev, arr[i]);
        prev = leftHeight[i];
    }

    prev = -1;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        rightHeight[i] = max(prev, arr[i]);
        prev = rightHeight[i];
    }

    int amount = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int minHeight = min(leftHeight[i], rightHeight[i]);
        amount += minHeight - arr[i];
    }

    return amount;
}

//PROGRAM 19
//TO FIND AMOUNT OF RAINWATER STORED BETWEEN BUILDINGS (BETTER SOLUTION)
int rainWaterHarvestingOptimized(vector<int> &arr)
{
    stack<int> st;
    st.push(-1);
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (st.top() != -1 && arr[st.top()] < arr[i])
        {
            int h = arr[st.top()];
            st.pop();
            if (st.top() == -1)
                break;
                
            int width = i - st.top() - 1;
            int height = min(arr[st.top()], arr[i]) - h;
            ans += height * width;
        }

        st.push(i);
    }

    return ans;
}

//SET 1
void stackProblems()
{
    // vector<int> arr = {11, 13, 21, 3, 6, 5, 9};
    // nextGreaterElementRight(arr);
    // nextSmallerElementRight(arr);
    // nextGreaterElementLeft(arr);
    // nextSmallerElementLeft(arr);

    //===============================================================

    // string s = "((()))()";
    // cout << boolalpha << validParentheses_balancedParentheses(s);
    // string str = "(()())(())(()(())";
    // cout << removeOutermostParentheses(str);
    // cout << longestValidParentheses(str);

    //===============================================================
    
    // vector<int> histograms = {2,5,3,6,6,6,7,3,7,7,6,6,4,2};
    // cout << largestRectangleInHistogram(histograms);
    // cout << largestRectangleInHistogramOptimized(histograms);
    // vector<vector<char>> grid = {
    //     {'1', '0', '1', '0', '0'},
    //     {'1', '0', '1', '1', '1'},
    //     {'1', '1', '0', '1', '1'},
    //     {'1', '0', '0', '1', '0'}};
    // cout << maximalRectangle(grid);

    //===============================================================

    // vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout << rainWaterHarvesting(arr);
    // cout << rainWaterHarvestingOptimized(arr);

    //===============================================================
}

//MAIN
int main(int argc, char **argv)
{
    // stackProblems();
    
}