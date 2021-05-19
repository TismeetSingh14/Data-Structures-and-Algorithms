//lecture 019
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//DISPLAYS

//TO DISPLAY 1D DP
void display1D(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

//TO DISPLAY 2D DP
void display2D(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

//PROGRAM 1
//PROGRAM FOR FIBONACCI THROUGH MEMOIZATION
int fibMemo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return dp[n] = n; //storing answer

    if (dp[n] != -1)
        return dp[n]; //checking if answer is already present

    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp); //storing answer
}

//PROGRAM 2
//PROGRAM FOR FIBONACCI THROUGH TABULATION
int fibTab(int n, vector<int> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            dp[i] = i;
            continue;
        }

        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

//PROGRAM 3
//PROGRAM FOR FIBONACCI THROUGH MATRIX EXPONENTIATION
vector<vector<int>> matrixMultiplication(vector<vector<int>> a, vector<vector<int>> b)
{
    int a1 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    int a2 = a[0][0] * b[1][0] + a[0][1] * b[1][1];
    int a3 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    int a4 = a[1][0] * b[1][0] + a[1][1] * b[1][1];

    vector<vector<int>> ans{{a1, a2}, {a3, a4}};
    return ans;
}

vector<vector<int>> fibLogn(vector<vector<int>> a, int n)
{
    if (n == 1)
        return a;

    vector<vector<int>> recAns = fibLogn(a, n / 2);
    recAns = matrixMultiplication(recAns, recAns);
    return n % 2 != 0 ? matrixMultiplication(a, recAns) : recAns;
}

//SET 1
void basic()
{
    int n = 10;
    vector<int> dp(n + 1, -1);
    // cout << fibMemo(n, dp) << endl;
    // cout << fibTab(n, dp) << endl;
    // vector<vector<int>> a{{1, 1}, {1, 0}};
    // vector<vector<int>> fibAns = fibLogn(a, n);
    // cout << fibAns[1][0] << endl;
    // display1D(dp);
}

//==================================================================================================

//PROGRAM 4
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING MEMOIZATION (TWO DIRECTIONS ALLOWED)
int mazePath2DirMemo(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    if (dp.size() == dp[0].size() && dp[sc][sr] != -1)
        return dp[sr][sc];

    int count = 0;

    if (sr + 1 <= er)
        count += mazePath2DirMemo(sr + 1, sc, er, ec, dp);

    if (sc + 1 <= ec)
        count += mazePath2DirMemo(sr, sc + 1, er, ec, dp);

    return dp[sr][sc] = count;
}

//PROGRAM 5
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING TABULATION (TWO DIRECTIONS ALLOWED)
int mazePath2DirTab(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int i = er; i >= sr; i--)
    {
        for (int j = ec; j >= sc; j--)
        {
            if (i == er && j == ec)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;

            if (i + 1 <= er)
                count += dp[i + 1][j];

            if (j + 1 <= ec)
                count += dp[i][j + 1];

            dp[i][j] = count;
        }
    }

    return dp[sr][sc];
}

//PROGRAM 6
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING MEMOIZATION (THREE DIRECTIONS ALLOWED)
int mazePath3DirMemo(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    if (dp.size() == dp[0].size() && dp[sr][sc] != -1)
        return dp[sc][sr];

    int count = 0;

    if (sr + 1 <= er)
        count += mazePath3DirMemo(sr + 1, sc, er, ec, dp);

    if (sc + 1 <= ec)
        count += mazePath3DirMemo(sr, sc + 1, er, ec, dp);

    if (sr + 1 <= er && sc + 1 <= ec)
        count += mazePath3DirMemo(sr + 1, sc + 1, er, ec, dp);

    return dp[sr][sc] = count;
}

//PROGRAM 7
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING TABULATION (THREE DIRECTIONS ALLOWED)
int mazePath3DirTab(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int i = er; i >= sr; i--)
    {
        for (int j = ec; j >= sc; j--)
        {
            if (i == er && j == ec)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;

            if (i + 1 <= er)
                count += dp[i + 1][j];

            if (j + 1 <= ec)
                count += dp[i][j + 1];

            if (i + 1 <= er && j + 1 <= ec)
                count += dp[i + 1][j + 1];

            dp[i][j] = count;
        }
    }

    return dp[sr][sc];
}

//PROGRAM 8
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING MEMOIZATION (THREE DIRECTIONS, MULTIMOVE ALLOWED)
int mazePath3DirMultiMoveMemo(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
        return dp[sr][sc] = 1;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    if (dp.size() == dp[0].size() && dp[sr][sc] != -1)
        return dp[sc][sr];

    int count = 0;

    for (int i = 1; sr + i <= er; i++)
        count += mazePath3DirMultiMoveMemo(sr + i, sc, er, ec, dp);

    for (int i = 1; sc + i <= ec; i++)
        count += mazePath3DirMultiMoveMemo(sr, sc + i, er, ec, dp);

    for (int i = 1; sr + i <= er && sc + i <= ec; i++)
        count += mazePath3DirMultiMoveMemo(sr + i, sc + i, er, ec, dp);

    return dp[sr][sc] = count;
}

//PROGRAM 9
//TO COUNT THE NUMBER OF PATHS FROM SOURCE TO DESTINATION USING TABULATION (THREE DIRECTIONS, MULTIMOVE ALLOWED)
int mazePath3DirMultiMoveTab(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (int i = er; i >= sr; i--)
    {
        for (int j = ec; j >= sc; j--)
        {
            if (i == er && j == ec)
            {
                dp[i][j] = 1;
                continue;
            }

            int count = 0;

            for (int k = 1; i + k <= er; k++)
                count += dp[i + k][j];

            for (int k = 1; j + k <= ec; k++)
                count += dp[i][j + k];

            for (int k = 1; i + k <= er && j + k <= ec; k++)
                count += dp[i + k][j + k];

            dp[i][j] = count;
        }
    }

    return dp[sr][sc];
}

//PROGRAM 10
//TO COUNT OF ALL PATHS BETWEEN START AND END USING MEMOIZATION (JUMPS ALLOWED BETWEEN 1 TO 6)
int boardPathMemo(int start, int end, vector<int> &dp)
{
    if (start == end)
        return dp[start] = 1;

    if (dp[start] != -1)
        return dp[start];

    int count = 0;

    for (int i = 1; i <= 6; i++)
    {
        if (start + i <= end)
            count += boardPathMemo(start + i, end, dp);
    }

    return dp[start] = count;
}

//PROGRAM 11
//TO COUNT OF ALL PATHS BETWEEN START AND END USING TABULATION (JUMPS ALLOWED BETWEEN 1 TO 6)
int boardPathTab(int start, int end, vector<int> &dp)
{
    for (int i = end; i >= start; i--)
    {
        if (i == end)
        {
            dp[i] = 1;
            continue;
        }

        int count = 0;

        for (int k = 1; k <= 6; k++)
        {
            if (i + k <= end)
                count += dp[i + k];
        }

        dp[i] = count;
    }

    return dp[start];
}

//PROGRAM 12
//TO COUNT OF ALL PATHS BETWEEN START AND END USING MEMOIZATION (JUMPS ALLOWED ARE GIVEN IN AN ARRAY)
int boardPathJumpsMemo(int start, int end, vector<int> &dp, vector<int> &arr)
{
    if (start == end)
        return dp[start] = 1;

    if (dp[start] != -1)
        return dp[start];

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + start <= end)
            count += boardPathJumpsMemo(start + arr[i], end, dp, arr);
    }

    return dp[start] = count;
}

//PROGRAM 13
//TO COUNT OF ALL PATHS BETWEEN START AND END USING TABULATION (JUMPS ALLOWED ARE GIVEN IN AN ARRAY)
int boardPathJumpsTab(int start, int end, vector<int> &dp, vector<int> &arr)
{
    for (int i = end; i >= start; i--)
    {
        if (i == end)
        {
            dp[i] = 1;
            continue;
        }

        int count = 0;

        for (int k = 0; k < arr.size(); k++)
        {
            if (i + arr[k] <= end)
                count += dp[i + arr[k]];
        }

        dp[i] = count;
    }

    return dp[start];
}

//SET 2
void pathType()
{
    // int sr = 0, sc = 0, er = 2, ec = 2;
    // vector<vector<int>> dp(er+1, vector<int>(ec+1, -1));
    // cout << mazePath2DirMemo(sr, sc, er, ec, dp) << endl;
    // cout << mazePath2DirTab(sr, sc, er, ec, dp) << endl;
    // cout << mazePath3DirMemo(sr, sc, er, ec, dp) << endl;
    // cout << mazePath3DirTab(sr, sc, er, ec, dp) << endl;
    // cout << mazePath3DirMultiMoveMemo(sr, sc, er, ec, dp) << endl;
    // cout << mazePath3DirMultiMoveTab(sr, sc, er, ec, dp) << endl;
    // display2D(dp);

    // int start = 0;
    // int end = 10;
    // vector<int> dp(end + 1, -1);
    // cout << boardPathMemo(start, end, dp) << endl;
    // cout << boardPathTab(start, end, dp) << endl;
    // vector<int> arr = {2, 3, 5, 7};
    // cout << boardPathJumpsMemo(start, end, dp, arr) << endl;
    // cout << boardPathJumpsTab(start, end, dp, arr) << endl;
    // display1D(dp);
}

//==================================================================================================

//PROGRAM 14
//GIVEN  N FRIENDS EACH ONE CAN REMAIN SINGLE OR CAN BE PAIRED UP WITH SOME OTHER FRIEND
//COUNT THE NUMBER OF WAYS FOR THE ABOVE STATEMENT THROUGH MEMOIZATION
int friendsPairingMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return dp[n] = 1;

    if (dp[n] != -1)
        return dp[n];

    int singles = friendsPairingMemo(n - 1, dp);
    int pairs = (n - 1) * friendsPairingMemo(n - 2, dp);

    return dp[n] = singles + pairs;
}

//PROGRAM 15
//GIVEN  N FRIENDS EACH ONE CAN REMAIN SINGLE OR CAN BE PAIRED UP WITH SOME OTHER FRIEND
//COUNT THE NUMBER OF WAYS FOR THE ABOVE STATEMENT THROUGH TABULATION
int friendsPairingTab(int n, vector<int> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            dp[i] = i;
            continue;
        }

        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}

//PROGRAM 16
//GIVEN  N FRIENDS EACH ONE CAN REMAIN SINGLE OR CAN BE PAIRED UP WITH SOME OTHER FRIEND
//COUNT THE NUMBER OF WAYS FOR THE ABOVE STATEMENT THROUGH TABULATION WITH SPACE OPTIMIZATION
int friendsPairingTabSpaceOptimized(int n)
{
    int a = 1, b = 1, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = a * (i - 1) + b;
        a = b;
        b = ans;
    }

    return b;
}

//PROGRAM 17
//GIVEN A GRID N*M START FROM ANY POSITION AND YOU CAN GO NORTHEAST, EAST, SOUTHEAST
//FIND THE MAXIMUM GOLD YOU CAN ACCUMULATE
int goldMineRec(vector<vector<int>> &mine, int x, int y)
{
    if (y == mine[0].size() - 1)
        return mine[x][y];

    int dir[3][2] = {{1, 1}, {0, 1}, {-1, 1}};
    int gold = 0;
    int maxGold = -1e8;
    for (int i = 0; i < 3; i++)
    {
        int nx = dir[i][0] + x;
        int ny = dir[i][1] + y;

        if (nx >= 0 && ny >= 0 && nx < mine.size() && ny < mine.size())
        {
            gold = mine[x][y] + goldMineRec(mine, nx, ny);
            if (gold > maxGold)
                maxGold = gold;
        }
    }

    return maxGold;
}

//PROGRAM 18
//GIVEN A GRID N*M START FROM ANY POSITION AND YOU CAN GO NORTHEAST, EAST, SOUTHEAST
//FIND THE MAXIMUM GOLD YOU CAN ACCUMULATE USING MEMOIZATION
int goldMineMemo(vector<vector<int>> &mine, int x, int y, vector<vector<int>> &dp)
{
    if (y == mine[0].size() - 1)
        return dp[x][y] = mine[x][y];

    if (dp[x][y] != -1)
        return dp[x][y];

    int dir[3][2] = {{1, 1}, {0, 1}, {-1, 1}};
    int gold = 0;
    int maxGold = -1e8;
    for (int i = 0; i < 3; i++)
    {
        int nx = dir[i][0] + x;
        int ny = dir[i][1] + y;

        if (nx >= 0 && ny >= 0 && nx < mine.size() && ny < mine.size())
        {
            gold = mine[x][y] + goldMineMemo(mine, nx, ny, dp);
            if (gold > maxGold)
                maxGold = gold;
        }
    }

    return dp[x][y] = maxGold;
}

//PROGRAM 19
//GIVEN A GRID N*M START FROM ANY POSITION AND YOU CAN GO NORTHEAST, EAST, SOUTHEAST
//FIND THE MAXIMUM GOLD YOU CAN ACCUMULATE USING TABULATION
int goldMineTab(vector<vector<int>> &mine, vector<vector<int>> &dp)
{
    for (int y = mine[0].size() - 1; y >= 0; y--)
    {
        for (int x = mine.size() - 1; x >= 0; x--)
        {
            if (y == mine[0].size() - 1)
            {
                dp[x][y] = mine[x][y];
                continue;
            }

            int dir[3][2] = {{1, 1}, {0, 1}, {-1, 1}};
            int gold = 0;
            int maxGold = -1e8;
            for (int i = 0; i < 3; i++)
            {
                int nx = dir[i][0] + x;
                int ny = dir[i][1] + y;

                if (nx >= 0 && ny >= 0 && nx < mine.size() && ny < mine.size())
                {
                    gold = mine[x][y] + dp[nx][ny];
                    if (gold > maxGold)
                        maxGold = gold;
                }

                dp[x][y] = maxGold;
            }
        }
    }

    display2D(dp);

    int goldAns = -1e8;
    for (int i = 0; i < dp.size(); i++)
        goldAns = goldAns > dp[i][0] ? goldAns : dp[i][0];

    return goldAns;
}

int goldMineCall(vector<vector<int>> &mine)
{
    int goldAns = -1e8;
    vector<vector<int>> dp(mine.size(), vector<int>(mine[0].size(), -1));
    // for (int i = 0; i < mine.size(); i++)
    // {
    //     // int ans=goldMineRec(mine,i,0);
    //     int ans = goldMineMemo(mine, i, 0, dp);
    //     if (ans > goldAns)
    //         goldAns = ans;
    // }
    // return goldAns;

    return goldMineTab(mine, dp);
}

//PROGRAM 20
//GIVEN N ELEMENTS AND K SETS, TO DISTRIBUTE N ELEMENTS IN K SETS SUCH THAT NO SET REMAINS EMPTY
//COUNT THE NUMBER OF WAYS TO ACHIEVE ABOVE DISTRIBUTION USING MEMOIZATION
int kSubsetsMemo(int n, int k, vector<vector<int>> &dp)
{
    if (n < k || k == 0 || n == 0)
        return dp[n][k] = 0;

    if (k == 1 || n == k) //ways to distribute 2 elements in 2 sets is 1 only
        return dp[n][k] = 1;

    if (dp[n][k] != 0)
        return dp[n][k];

    int a = kSubsetsMemo(n - 1, k - 1, dp); //a particular element takes its own set
    int b = k * kSubsetsMemo(n - 1, k, dp); //a particular element adds to some other set

    return dp[n][k] = a + b;
}

//PROGRAM 21
//GIVEN N ELEMENTS AND K SETS, TO DISTRIBUTE N ELEMENTS IN K SETS SUCH THAT NO SET REMAINS EMPTY
//COUNT THE NUMBER OF WAYS TO ACHIEVE ABOVE DISTRIBUTION USING MEMOIZATION
int kSubsetsTab(int n, int k, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j == 1 || i == j) //ways to distribute 2 elements in 2 sets is 1 only
            {
                dp[i][j] = 1;
                continue;
            }

            if (i < j || j == 0 || i == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            int a = dp[i - 1][j - 1]; //a particular element takes its own set
            int b = j * dp[i - 1][j]; //a particular element adds to some other set

            dp[i][j] = a + b;
        }
    }

    return dp[n][k];
}

//PROGRAM 22
//GIVEN A MATRIX WITH ONLY 0s AND 1s, TO FIND LARGEST SQUARE MATRIX THAT CAN BE FORMED WITH ONLY 1s
//USING MEMOIZATION
int maxSq = 0;
int maximalSquareMemo(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp)
{
    if (x == matrix.size() || y == matrix[0].size())
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    int minAns = 0;
    int down = maximalSquareMemo(matrix, x + 1, y, dp);
    int diag = maximalSquareMemo(matrix, x + 1, y + 1, dp);
    int right = maximalSquareMemo(matrix, x, y + 1, dp);

    if (matrix[x][y] == 1)
        minAns = min(down, min(diag, right)) + 1;

    maxSq = max(maxSq, minAns);
    return dp[x][y] = minAns;
}

//PROGRAM 23
//GIVEN A MATRIX WITH ONLY 0s AND 1s, TO FIND LARGEST SQUARE MATRIX THAT CAN BE FORMED WITH ONLY 1s
//USING TABULATION
int maximalSquareTab(vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int maxSq = 0;

    for (int i = matrix.size() - 1; i >= 0; i--)
    {
        for (int j = matrix[0].size() - 1; j >= 0; j--)
        {
            if (i == matrix.size() || j == matrix[0].size() || matrix[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            int minAns = 0;
            int down = dp[i + 1][j];
            int diag = dp[i + 1][j + 1];
            int right = dp[i][j + 1];

            if (matrix[i][j] == 1)
                minAns = min(down, min(diag, right)) + 1;

            maxSq = max(maxSq, minAns);
            dp[i][j] = minAns;
        }
    }

    return maxSq;
}

//PROGRAM 24
//GIVEN A BOARD N X M, TO FIND THE NUMBER OF WAYS THE BOARDS CAN BE TILES WITH TILES
// OF DIMENSIONS 1 X M USING MEMOIZATION
int tilingProblemMemo(int n, int m, vector<int> &dp)
{
    if (n == m)
        return dp[n] = 2;
    if (n < m)
        return dp[n] = 1;

    if (dp[n] != 0)
        return dp[n];

    int count = 0;
    count += tilingProblemMemo(n - 1, m, dp);
    count += tilingProblemMemo(n - m, m, dp);

    return dp[n] = count;
}

//PROGRAM 25
//GIVEN A BOARD N X M, TO FIND THE NUMBER OF WAYS THE BOARDS CAN BE TILES WITH TILES
//OF DIMENSIONS 1 X M USING TABULATION
int tilingProblemTab(int n, int m, vector<int> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == m)
        {
            dp[i] = 2;
            continue;
        }

        if (i < m)
        {
            dp[i] = 1;
            continue;
        }

        dp[i] = dp[i - 1] + dp[i - m];
    }

    return dp[n];
}

//PROGRAM 26
//COIN CHANGE PERMUTATION PROBLEM TO GENERATE ALL PERMUTATIONS OF ELEMENTS WHICH SUM UP
//TO THE TARGET USING MEMOIZATION
int coinChangePermutationInfiniteMemo(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 1;

    if (dp[tar] != 0)
        return dp[tar];

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
            count += coinChangePermutationInfiniteMemo(arr, tar - arr[i], dp);
    }

    return dp[tar] = count;
}

//PROGRAM 27
//COIN CHANGE PERMUTATION PROBLEM TO GENERATE ALL PERMUTATIONS OF ELEMENTS WHICH SUM UP
//TO THE TARGET USING TABULATION
int coinChangePermutationInfiniteTab(vector<int> &arr, int tar, vector<int> &dp)
{
    for (int i = 0; i <= tar; i++)
    {
        if (i == 0)
        {
            dp[i] = 1;
            continue;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (i - arr[j] >= 0)
                dp[i] += dp[i - arr[j]];
        }
    }

    return dp[tar];
}

//PROGRAM 28
//COIN CHANGE COMBINATION PROBLEM TO GENERATE ALL COMBINATIONS OF ELEMENTS WHICH SUM UP
//TO THE TARGET USING TABULATION
int coinChangeCombinationInfiniteTab(vector<int> &arr, int tar, vector<int> &dp)
{
    dp[0] = 1;
    for (int j = 0; j < arr.size(); j++)
    {
        for (int i = 1; i <= tar; i++)
        {
            if (i - arr[j] >= 0)
                dp[i] += dp[i - arr[j]];
        }
    }

    return dp[tar];
}

//PROGRAM 29
//TO FIND MINIMUM COINS THAT SUM UP TO TARGET USING MEMOIZATION
int minCoinChangeMemo(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0)
        return dp[tar] = 0;

    if (dp[tar] != 0)
        return dp[tar];

    int minCoins = 1e8;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            int change = minCoinChangeMemo(arr, tar - arr[i], dp);
            if (change != 1e8)
                minCoins = min(minCoins, change + 1);
        }
    }

    dp[tar] = minCoins;
}

//PROGRAM 30
//TO FIND MINIMUM COINS THAT SUM UP TO TARGET USING TABULATION
int minCoinChangeTab(vector<int> &arr, int tar, vector<int> &dp)
{
    for (int i = 0; i < dp.size(); i++)
        dp[i] = 1e8;

    for (int i = 0; i <= tar; i++)
    {
        if (i == 0)
        {
            dp[i] = 0;
            continue;
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (i - arr[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }

    return dp[tar];
}

//PROGRAM 31
//TO SUM UP TO A PARTICULAR TARGET WITH CONSTRAINT AS COINS CAN BE USED AT MOST ONE TIME USING MEMOIZATION
int targetSumMemo(vector<int> &arr, int tar, int idx, vector<vector<int>> &dp)
{
    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - arr[idx] >= 0)
        count += targetSumMemo(arr, tar - arr[idx], idx - 1, dp);
    count += targetSumMemo(arr, tar, idx - 1, dp);

    return dp[idx][tar] = count;
}

//PROGRAM 32
//TO SUM UP TO A PARTICULAR TARGET WITH CONSTRAINT AS COINS CAN BE USED AT MOST ONE TIME USING TABULATION
int targetSumTab(vector<int> &arr, int tar, int idx, vector<vector<int>> &dp)
{
    dp[0][0] = 1;

    for (int idx = 1; idx < dp.size(); idx++)
    {
        for (int t = 0; t <= tar; t++)
        {

            int count = 0;
            if (t - arr[idx - 1] >= 0)
            {
                count += dp[idx - 1][t - arr[idx - 1]];
            }
            count += dp[idx - 1][t];

            dp[idx][t] = count;
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

//PROGRAM 33
//TO SUM UP TO A PARTICULAR WEIGHT USING WEIGHTS (USED AT MOST ONE TIME) SUCH THAT THE VALUES ARE MAXIMIZED USING MEMOIZATION
//KNAPSACK PROBLEM
int knapsack01Memo(vector<int> &values, vector<int> &weights, int idx, int maxWgt, vector<vector<int>> &dp)
{
    if (idx == weights.size() || maxWgt == 0)
        return 0;

    if (dp[idx][maxWgt] != 0)
        return dp[idx][maxWgt];

    int maxProf = -1e8;
    if (maxWgt - weights[idx] >= 0)
        maxProf = max(maxProf, values[idx] + knapsack01Memo(values, weights, idx + 1, maxWgt - weights[idx], dp));
    maxProf = max(maxProf, knapsack01Memo(values, weights, idx + 1, maxWgt, dp));

    dp[idx][maxWgt] = maxProf;
}

//PROGRAM 34
//TO SUM UP TO A PARTICULAR WEIGHT USING WEIGHTS (USED AT MOST ONE TIME) SUCH THAT THE VALUES ARE MAXIMIZED USING TABULATION
//KNAPSACK PROBLEM
int knapsack01Tab(vector<int> &values, vector<int> &weights, int maxWgt, vector<vector<int>> &dp)
{
    dp[0][0] = 0;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int t = 0; t <= maxWgt; t++)
        {
            int picked = 0;
            if (t - weights[i - 1] >= 0)
                picked += values[i - 1] + dp[i - 1][t - weights[i - 1]];
            int notPicked = dp[i - 1][t];

            dp[i][t] = max(picked, notPicked);
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

//PROGRAM 35
//TO SUM UP TO A PARTICULAR WEIGHT USING WEIGHTS (INFINITE WEIGHTS ALLOWED) SUCH THAT THE VALUES ARE MAXIMIZED USING TABULATION
//UNBOUNDED KNAPSACK PROBLEM
int unboundedKnapsack(vector<int> &weight, vector<int> &cost, int capacity)
{
    vector<int> dp(capacity + 1, 0);
    dp[0] = 0;
    for (int idx = 0; idx < weight.size(); idx++)
    {
        for (int cap = 1; cap <= capacity; cap++)
        {
            if (cap - weight[idx] >= 0)
            {
                int picked = dp[cap - weight[idx]] + cost[idx];
                int notpicked = dp[cap];
                dp[cap] = max(picked, notpicked);
            }
        }
    }
    display1D(dp);
    return dp[capacity];
}

//PROGRAM 36
//GIVEN AN ARRAY OF NON NEGATIVE INTEGERS EACH REPRESENTING THE MAXIMUM JUMP FROM ONE CELL
//TO ANOTHER, TO REACH THE LAST INDEX IN MINIMUM JUMP USING MEMOIZATION
int minJumpMemo(vector<int> &arr, int i, vector<int> &dp)
{
    if (i == arr.size() - 1)
        return dp[i] = 0;

    if (dp[i] != -1)
        return dp[i];

    int minAns = 1e8;

    for (int jump = 1; jump <= arr[i] && i + jump < arr.size(); jump++)
    {
        int recAns = minJumpMemo(arr, i + jump, dp);
        if (recAns + 1 < minAns)
            minAns = recAns + 1;
    }

    return dp[i] = minAns;
}

//PROGRAM 37
//GIVEN AN ARRAY OF NON NEGATIVE INTEGERS EACH REPRESENTING THE MAXIMUM JUMP FROM ONE CELL
//TO ANOTHER, TO REACH THE LAST INDEX IN MINIMUM JUMP USING TABULATION
int minJumpTab(vector<int> &arr, vector<int> &dp)
{
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (i == arr.size() - 1)
        {
            dp[i] = 0;
            continue;
        }

        int minAns = 1e8;

        for (int jump = 1; jump <= arr[i] && i + jump < arr.size(); jump++)
        {
            int recAns = dp[i + jump];
            if (recAns + 1 < minAns)
                minAns = recAns + 1;
        }

        dp[i] = minAns;
    }

    return dp[0];
}

//SET 3
void dpProblems_Set_1()
{
    // int n = 4;
    // vector<int> dp(n + 1, -1);
    // cout << friendsPairingMemo(n, dp) << endl;
    // cout << friendsPairingMemo(n, dp) << endl;
    // cout << friendsPairingTabSpaceOptimized(n) << endl;
    // display1D(dp);

    //====================================================

    // vector<vector<int>> mine = {
    //     {1, 3, 3},
    //     {2, 1, 4},
    //     {0, 6, 4}};
    // cout << goldMineCall(mine);

    //====================================================

    // int n = 5, k = 3;
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // //cout << kSubsetsMemo(n, k, dp) << endl;
    // cout << kSubsetsTab(n, k, dp) << endl;
    // display2D(dp);

    //====================================================

    // vector<vector<int>> matrix = {{0, 1, 1, 0, 1},
    //                               {1, 1, 0, 1, 0},
    //                               {0, 1, 1, 1, 0},
    //                               {1, 1, 1, 1, 0},
    //                               {1, 1, 1, 1, 1},
    //                               {0, 0, 0, 0, 0}};
    // vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    // maximalSquareMemo(matrix, 0, 0, dp);
    // cout << maxSq << endl;
    // cout << maximalSquareTab(matrix, dp) << endl;
    // display2D(dp);

    //====================================================

    // int n = 7, m = 4;
    // vector<int> dp(n + 1, 0);
    // cout << tilingProblemMemo(n, m, dp) << endl;
    // cout << tilingProblemTab(n, m, dp) << endl;
    // display1D(dp);

    //====================================================

    // int tar = 10;
    // vector<int> dp(tar + 1, 0);
    // vector<int> arr = {1,1,1,1,1};
    // cout << coinChangePermutationInfiniteMemo(arr, tar, dp) << endl;
    // cout << coinChangePermutationInfiniteTab(arr, tar, dp) << endl;
    // cout << coinChangeCombinationInfiniteTab(arr, tar, dp) << endl;
    // cout << minCoinChangeMemo(arr, tar, dp) << endl;
    // cout << minCoinChangeTab(arr, tar, dp) << endl;
    // display1D(dp);
    // vector<vector<int>> dp(arr.size(),vector<int>(tar+1,0));
    // cout << targetSumMemo(arr,tar,arr.size()-1,dp) << endl;
    // cout << targetSumMemo(arr,tar,arr.size()-1,dp) << endl;
    // display2D(dp);

    //====================================================

    vector<int> values = {1, 6, 18, 22,28};
    vector<int> weights = {1,2,5,6,7};
    int maxWgt = 11;
    vector<vector<int>> dp(weights.size() + 1, vector<int>(maxWgt + 1, 0));
    // cout << knapsack01Memo(values,weights,0,maxWgt,dp) << endl;
    cout << knapsack01Tab(values,weights,maxWgt,dp) << endl;
    display2D(dp);

    // vector<int> weight={1,50};
    // vector<int> cost={1,30};
    // int capacity=100;
    // cout << unboundedKnapsack(weight,cost,capacity);

    //====================================================

    // vector<int> arr = {2, 3, 1, 1, 4, 3, 5, 6, 2, 8, 9, 1, 2, 4};
    // vector<int> dp(arr.size(), -1);
    // cout << minJumpMemo(arr, 0, dp) << endl;
    // cout << minJumpTab(arr, dp) << endl;
    // display1D(dp);

    //====================================================
}

//==================================================================================================

//PROGRAM 38
//TO FIND WHETHER THE GIVEN SUBSTRING IS PALINDROME OR NOT
vector<vector<bool>> isPalindromicSubstring(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < s.length(); si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = true;

            else if (gap == 1 && s[si] == s[ei])
                dp[si][ei] = true;

            else
                dp[si][ei] = (s[si] == s[ei]) && (dp[si + 1][ei - 1]); //to go back diagonally, si should be
                                                                       //incremented and ei should be decremented
        }
    }

    return dp;
}

//PROGRAM 39
//TO FIND THE LENGTH OF LONGEST PALINDROMIC SUBSTRING IN A STRING USING TABULATION
int longestPalindromicSubstring(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    int maxLen = 0;

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < s.length(); si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = 1;
            else if (gap == 1 && s[si] == s[ei])
                dp[si][ei] = 2;
            else if (s[si] == s[ei] && dp[si + 1][ei - 1] != 0)
                dp[si][ei] = dp[si + 1][ei - 1] + 2;

            maxLen = max(maxLen, dp[si][ei]);
        }
    }

    display2D(dp);
    return maxLen;
}

//PROGRAM 40
//TO COUNT ALL POSSIBLE PALINDROMIC SUBSTRINGS USING TABULATION
int countOfPalindromicSubstring(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    int count = 0;

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < s.length(); si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = 1;

            else if (gap == 1 && s[si] == s[ei])
                dp[si][ei] = 2;

            else if (s[si] == s[ei] && dp[si + 1][ei - 1] != 0)
                dp[si][ei] = dp[si + 1][ei - 1] + 2;

            count = dp[si][ei] ? count + 1 : count;
        }
    }

    display2D(dp);
    return count;
}

//PROGRAM 41
//TO FIND THE LENGTH OF LONGEST PALINDROMIC SUBSEQUENCES IN A STRING USING MEMOIZATION
int longestPalindromicSubsequenceMemo(string s, int si, int ei, vector<vector<int>> &dp)
{
    if (si > ei)
        return 0;

    if (si == ei)
        return dp[si][ei] = 1;

    if (dp[si][ei] != 0)
        return dp[si][ei];

    if (s[si] == s[ei])
        return dp[si][ei] = longestPalindromicSubsequenceMemo(s, si + 1, ei - 1, dp) + 2;

    int down = longestPalindromicSubsequenceMemo(s, si + 1, ei, dp);
    int left = longestPalindromicSubsequenceMemo(s, si, ei - 1, dp);

    return dp[si][ei] = max(down, left);
}

//PROGRAM 42
//TO FIND THE LENGTH OF LONGEST PALINDROMIC SUBSEQUENCES IN A STRING USING TABULATION
int longestPalindromicSubsequenceTab(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < s.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    display2D(dp);
    return dp[0][s.length() - 1];
}

//PROGRAM 43
//TO FIND THE COUNT OF NUMBER OF PALINDROMIC SUBSEQUENCES IN A STRING USING MEMOIZATION
int countOfPalindromicSubsequencesMemo(string s, int si, int ei, vector<vector<int>> &dp)
{
    if (si > ei)
        return 0;

    if (si == ei)
        return dp[si][ei] = 1;

    if (dp[si][ei] != 0)
        return dp[si][ei];

    int middle = countOfPalindromicSubsequencesMemo(s, si + 1, ei - 1, dp);
    int frontChar = countOfPalindromicSubsequencesMemo(s, si + 1, ei, dp);
    int rearChar = countOfPalindromicSubsequencesMemo(s, si, ei - 1, dp);

    int recAns = frontChar + rearChar;
    recAns = s[si] == s[ei] ? recAns + 1 : recAns - middle;

    return dp[si][ei] = recAns;
}

//PROGRAM 44
//TO FIND THE COUNT OF NUMBER OF PALINDROMIC SUBSEQUENCES IN A STRING USING TABULATION
int countOfPalindromicSubsequencesTab(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < s.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (s[i] == s[j])
            {
                dp[i][j] += dp[i + 1][j - 1] + 1;
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
            else
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
    }

    display2D(dp);
    return dp[0][s.length() - 1];
}

//PROGRAM 45
//TO FIND THE LENGTH THE LONGEST COMMON SUBSEQUENCE IN TWO STRINGS USING MEMOIZATION
int longestCommonSubsequenceMemo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = longestCommonSubsequenceMemo(s1, s2, i + 1, j + 1, dp) + 1;

    int len1 = longestCommonSubsequenceMemo(s1, s2, i + 1, j, dp);
    int len2 = longestCommonSubsequenceMemo(s1, s2, i, j + 1, dp);

    return dp[i][j] = max(len1, len2);
}

//PROGRAM 46
//TO FIND THE LENGTH THE LONGEST COMMON SUBSEQUENCE IN TWO STRINGS USING TABULATION
int longestCommonSubsequenceTab(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    display2D(dp);
    return dp[0][0];
}

//PROGRAM 47
//TO FIND THE LONGEST COMMON SUBSEQUENCE IN TWO STRINGS USING TABULATION
string longestCommonSubsequenceTabPrintLCS(string s1, string s2)
{
    vector<vector<string>> dp(s1.length() + 1, vector<string>(s2.length() + 1, ""));

    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
                dp[i][j] = s1[i] + dp[i + 1][j + 1];

            else
                dp[i][j] = dp[i + 1][j].length() > dp[i][j + 1].length() ? dp[i + 1][j] : dp[i][j + 1];
        }
    }

    return dp[0][0];
}

//PROGRAM 48
//TO FIND THE LONGEST COMMON SUBSTRING IN TWO STRINGS USING MEMOIZATION
int maxStr = 0;
int longestCommonSubstringMemo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length() || j == s2.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        dp[i][j] = longestCommonSubstringMemo(s1, s2, i + 1, j + 1, dp) + 1;
        maxStr = max(maxStr, dp[i][j]);
        return dp[i][j];
    }

    longestCommonSubstringMemo(s1, s2, i + 1, j, dp);
    longestCommonSubstringMemo(s1, s2, i, j + 1, dp);

    return dp[i][j] = 0;
}

//PROGRAM 49
//TO FIND THE LONGEST COMMON SUBSTRING IN TWO STRINGS USING TABULATION
int longestCommonSubstringTab(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    int maxStr = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            dp[i][j] = s1[i] == s2[j] ? dp[i + 1][j + 1] + 1 : 0;
            maxStr = max(maxStr, dp[i][j]);
        }
    }

    return maxStr;
}

//PROGRAM 50
//TO FIND MINIMUM OPERATIONS (REPLACE, DELETE AND INSERT) TO CONVERT WORD1 TO WORD2 USING MEMOIZATION
int editDistanceMemo_1(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == s1.length())
        return dp[i][j] = s2.length() - j;

    else if (j == s2.length())
        return dp[i][j] = s1.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        dp[i][j] = editDistanceMemo_1(s1, s2, i + 1, j + 1, dp);

    else
    {
        int deleteOperation = editDistanceMemo_1(s1, s2, i + 1, j, dp);
        int insertOperation = editDistanceMemo_1(s1, s2, i, j + 1, dp);
        int replaceOperation = editDistanceMemo_1(s1, s2, i + 1, j + 1, dp);

        dp[i][j] = min(deleteOperation, min(insertOperation, replaceOperation)) + 1;
    }

    return dp[i][j];
}

//PROGRAM 51
//TO FIND MINIMUM OPERATIONS (REPLACE, DELETE AND INSERT) TO CONVERT WORD1 TO WORD2 USING MEMOIZATION
int editDistanceMemo_2(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0)
        return dp[i][j] = j;

    else if (j == 0)
        return dp[i][j] = i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        dp[i][j] = editDistanceMemo_2(s1, s2, i - 1, j - 1, dp);

    else
    {
        int deleteOperation = editDistanceMemo_2(s1, s2, i - 1, j, dp);
        int insertOperation = editDistanceMemo_2(s1, s2, i, j - 1, dp);
        int replaceOperation = editDistanceMemo_2(s1, s2, i - 1, j - 1, dp);

        dp[i][j] = min(deleteOperation, min(insertOperation, replaceOperation)) + 1;
    }

    return dp[i][j];
}

//PROGRAM 52
//TO FIND MINIMUM OPERATIONS (REPLACE, DELETE AND INSERT) TO CONVERT WORD1 TO WORD2 USING TABULATION
int editDistanceTab(string s1, string s2)
{
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
                continue;
            }

            else if (j == 0)
            {
                dp[i][j] = i;
                continue;
            }

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
            {
                int insertion = dp[i][j - 1];
                int deletion = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = min(insertion, min(deletion, replace)) + 1;
            }
        }
    }

    display2D(dp);
    return dp[s1.length() - 1][s2.length() - 1];
}

//PROGRAM 53
//TO FIND THE NUMBER OF TIMES A STRING OCCURS AS A SUBSEQUENCE IN ANOTHER STRING USING MEMOIZATION
int stringOccursAsSubsequenceMemo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (j == s2.length() || (i == s1.length() && j == s2.length()))
        return dp[i][j] = 1;

    if (i == s1.length() || (s1.length() - i < s2.length() - j))
        return dp[i][j] = 0;

    if (dp[i][j] != 0)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        int x = stringOccursAsSubsequenceMemo(s1, s2, i + 1, j + 1, dp);
        int y = stringOccursAsSubsequenceMemo(s1, s2, i + 1, j, dp);
        return dp[i][j] = x + y;
    }

    int z = stringOccursAsSubsequenceMemo(s1, s2, i + 1, j, dp);
    return dp[i][j] += z;
}

//PROGRAM 54
//TO FIND THE NUMBER OF TIMES A STRING OCCURS AS A SUBSEQUENCE IN ANOTHER STRING USING TABULATION
int stringOccursAsSubsequenceTab(string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = s1.length(); i >= 0; i--)
    {
        for (int j = s2.length(); j >= 0; j--)
        {
            if (j == s2.length() || (i == s1.length() && j == s2.length()))
            {
                dp[i][j] = 1;
                continue;
            }

            if (i == s1.length() || (s1.length() - i < s2.length() - j))
            {
                dp[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j])
                dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];

            else
                dp[i][j] = dp[i + 1][j];
        }
    }

    return dp[0][0];
}

//PROGRAM 55
//TO FIND THE LENGTH OF LONGEST INCREASING SUBSEQUENCE IN AN ARRAY USING MEMOIZATION
int maxSubSeq = 0;
int longestIncreasingSubsequenceMemo(vector<int> &arr, int ei, vector<int> &dp)
{
    if (ei == 0)
        return 1;

    if (dp[ei] != -1)
        return dp[ei];

    int maxSeq = 1;
    for (int i = ei - 1; i >= 0; i--)
    {
        int len = longestIncreasingSubsequenceMemo(arr, i, dp);
        if (arr[ei] > arr[i])
        {
            maxSeq = max(maxSeq, len + 1);
            maxSubSeq = max(maxSeq, maxSubSeq);
        }
    }

    return dp[ei] = maxSeq;
}

//PROGRAM 56
//TO FIND THE LENGTH OF LONGEST INCREASING SUBSEQUENCE IN AN ARRAY USING TABULATION
int longestIncreasingSubsequenceTab(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int maxAns = 1;

    for (int ei = 0; ei < arr.size(); ei++)
    {
        for (int k = 0; k < ei; k++)
        {
            if (arr[ei] > arr[k])
                dp[ei] = max(dp[ei], dp[k] + 1);

            maxAns = max(dp[ei], maxAns);
        }
    }

    display1D(dp);
    return maxAns;
}

//PROGRAM 57
//TO FIND THE LENGTH OF LONGEST DECREASING SUBSEQUENCE IN AN ARRAY USING TABULATION
int longestDecreasingSubsequenceTab(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int maxAns = 1;

    for (int ei = 0; ei < arr.size(); ei++)
    {
        for (int k = 0; k < ei; k++)
        {
            if (arr[ei] < arr[k])
                dp[ei] = max(dp[ei], dp[k] + 1);

            maxAns = max(dp[ei], maxAns);
        }
    }

    display1D(dp);
    return maxAns;
}

//PROGRAM 58
//TO FIND THE LENGTH OF LONGEST BITONIC SUBSEQUENCE IN AN ARRAY USING TABULATION
vector<int> longestIncreasingSubsequenceTabLBS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int maxAns = 1;

    for (int ei = 0; ei < arr.size(); ei++)
    {
        for (int k = 0; k < ei; k++)
        {
            if (arr[ei] > arr[k])
                dp[ei] = max(dp[ei], dp[k] + 1);

            maxAns = max(dp[ei], maxAns);
        }
    }

    return dp;
}

vector<int> longestDecreasingSubsequenceTabLBS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int maxAns = 1;

    for (int ei = 0; ei < arr.size(); ei++)
    {
        for (int k = 0; k < ei; k++)
        {
            if (arr[ei] < arr[k])
                dp[ei] = max(dp[ei], dp[k] + 1);

            maxAns = max(dp[ei], maxAns);
        }
    }

    return dp;
}

int longestBitonicSubsequenceTab(vector<int> &arr)
{
    vector<int> LIS = longestIncreasingSubsequenceTabLBS(arr);
    vector<int> LDS = longestDecreasingSubsequenceTabLBS(arr);
    vector<int> LBS(arr.size(), 0);
    int maxAns = -1e8;

    for (int i = 0; i < arr.size(); i++)
    {
        LBS[i] = LIS[i] + LDS[i] - 1;
        maxAns = max(maxAns, LBS[i]);
    }

    return maxAns;
}

//PROGRAM 59
//TO FIND LONGEST INCREASING SUBSEQUENCE WITH MAXIMUM SUM
int maximumIncreasingSubsequence(vector<int> &arr)
{
    vector<int> dp(arr.size(), 0);
    int maxAns = -1e8;
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + arr[i]);
            maxAns = max(dp[i], maxAns);
        }
    }

    display1D(dp);
    return maxAns;
}

//PROGRAM 60
//TO FIND MINIMUM DELETIONS FROM AN ARRAY TO MAKE IT SORTED
int minimumDeletions(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int maxAns = 1;

    for (int ei = 0; ei < arr.size(); ei++)
    {
        for (int k = 0; k < ei; k++)
        {
            if (arr[ei] >= arr[k])
                dp[ei] = max(dp[ei], dp[k] + 1);

            maxAns = max(dp[ei], maxAns);
        }
    }

    return arr.size() - maxAns;
}

//PROGRAM 61
//TO COUNT THE NUMBER OF LAONGEST INCREASING SUBSEQUENCES IN AN ARRAY
int countOfLongestIncreasingSubsequence(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    vector<int> count(arr.size(), 1);
    int maxLen = 0;
    int maxCount = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }

                else if (dp[j] + 1 == dp[i])
                    count[i] += count[j];
            }
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxCount = count[i];
        }

        else if (dp[i] == maxLen)
            maxCount += count[i];
    }

    return maxCount;
}

//PROGRAM 62
//REFER LEETCODE
int russianDollEnvelopes(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    });

    vector<int> dp(arr.size(), 1);
    int maxEnv = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i][1] > arr[j][1])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        maxEnv = max(maxEnv, dp[i]);
    }

    return maxEnv;
}

//PROGRAM 63
//TO FIND THE LENGTH OF LONGEST INCREASING SUBSEQUENCE IN O(N.logN)
int ceiling(vector<int> arr, int li, int ri, int data)
{
    while (ri - li > 1)
    {
        int mid = li + (ri - li) / 2; //to avoid overflow from (li+ri)/2

        if (arr[mid] < data)
            li = mid;

        else
            ri = mid;
    }

    return ri;
}

int longestIncreasingSubsequence_NlogN(vector<int> &arr)
{
    vector<int> temp(arr.size(), 0);
    int maxLen = 1;
    temp[0] = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < temp[0])
            temp[0] = arr[i];

        else if (arr[i] > temp[maxLen - 1])
            temp[maxLen++] = arr[i];

        else
        {
            int idx = ceiling(temp, -1, maxLen - 1, arr[i]);
            temp[idx] = arr[i];
        }
    }

    return maxLen;
}

//SET 4
void dpProblems_Set_2_Subsequences()
{
    // string s = "GEEKSSE";
    // cout << longestPalindromicSubstring(s) << endl;
    // cout << countOfPalindromicSubstring(s) << endl;
    // vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    // cout << longestPalindromicSubsequenceMemo(s, 0, s.length() - 1, dp) << endl;
    // cout << longestPalindromicSubsequenceTab(s) << endl;
    // cout << countOfPalindromicSubsequencesMemo(s,0,s.length()-1,dp)<<endl;
    // display2D(dp);
    // cout << countOfPalindromicSubsequencesTab(s);

    //====================================================

    // string s1 = "PQRSTPQRS";
    // string s2 = "PRATPBRQRPS";
    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    // cout << longestCommonSubsequenceMemo(s1, s2, 0, 0, dp) << endl;
    // display2D(dp);
    // cout << longestCommonSubsequenceTab(s1, s2);
    // cout << longestCommonSubsequenceTabPrintLCS(s1,s2);

    //====================================================

    // string s1 = "bcdabcdefg";
    // string s2 = "aqweabcdek";
    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    // longestCommonSubstringMemo(s1, s2, 0, 0, dp);
    // cout << maxStr << endl;
    // display2D(dp);
    // cout << longestCommonSubstringTab(s1, s2);

    //====================================================

    // string s1 = "sunday";
    // string s2 = "saturday";
    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    // cout << editDistanceMemo_1(s1, s2, 0, 0, dp) << endl;
    // cout << editDistanceMemo_2(s1, s2, s1.length(), s2.length(), dp) << endl;
    // display2D(dp);
    // cout << editDistanceTab(s1, s2);

    // string s1 = "GEEKSFORGEEKS";
    // string s2 = "GKS";
    // vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    // cout << stringOccursAsSubsequenceMemo(s1, s2, 0, 0, dp) << endl;
    // cout << stringOccursAsSubsequenceTab(s1, s2, dp) << endl;
    // display2D(dp);

    //====================================================

    // vector<int> arr1 = {2, 1, 4, 5, 6, 8, 3, 6, 4, 8};
    // vector<int> arr2 = {5, 0, 5, 6, 4, 3, 2, 7, 8, 9};
    // vector<int> arr3 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    // vector<int> arr4 = {10, 3, 4, 5};
    // vector<int> arr5 = {2, 3, 6, 4, 7, 2};
    // vector<int> dp(arr1.size(), -1);
    // cout << longestIncreasingSubsequenceMemo(arr1, arr1.size() - 1, dp) << endl;
    // cout << maxSubSeq << endl;
    // display1D(dp);
    // cout << longestIncreasingSubsequenceTab(arr1);
    // cout << longestDecreasingSubsequenceTab(arr2);
    // cout << longestBitonicSubsequenceTab(arr3);
    // cout << maximumIncreasingSubsequence(arr4);
    // cout << minimumDeletions(arr5);
    // cout << countOfLongestIncreasingSubsequence(arr3);
    // vector<vector<int>> arr = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    // cout << russianDollEnvelopes(arr);
    // cout<< longestIncreasingSubsequence_NlogN(arr3);

    //====================================================
}

//==================================================================================================

//PROGRAM 64
//TO MINIMIZE THE COST OF MULTIPLICATION OF A GIVEN NUMBER OF MATRICES USING MEMOIZATION
int matrixChainMultiplicationMemo(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
        return dp[si][ei] = 0;

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int minCost = 1e8;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = matrixChainMultiplicationMemo(arr, si, cut, dp);
        int right = matrixChainMultiplicationMemo(arr, cut, ei, dp);

        int netCost = left + arr[si] * arr[cut] * arr[ei] + right;

        minCost = min(netCost, minCost);
    }

    return dp[si][ei] = minCost;
}

//PROGRAM 65
//TO MINIMIZE THE COST OF MULTIPLICATION OF A GIVEN NUMBER OF MATRICES USING TABULATION
int matrixChainMultiplicationTab(vector<int> &arr, vector<vector<int>> &dp)
{
    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (gap == 1)
            {
                dp[si][ei] = 0;
                continue;
            }

            int minCost = 1e8;
            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut][ei];
                int netCost = left + arr[si] * arr[cut] * arr[ei] + right;
                minCost = min(minCost, netCost);
            }

            dp[si][ei] = minCost;
        }
    }

    return dp[0][arr.size() - 1];
}

//PROGRAM 66
//TO MINIMIZE THE COST OF MULTIPLICATION OF A GIVEN NUMBER OF MATRICES USING MEMOIZATION
//TO PRINT THE ORDER OF MULTIPLICATION OF THE MATRICES
pair<int, string> matrixChainMultiplicationMemoString(vector<int> &arr, int si, int ei, vector<vector<pair<int, string>>> &dp)
{
    if (si + 1 == ei)
    {
        string str = string(1, (char)(si + 'A'));
        dp[si][ei] = {0, str};
        return dp[si][ei];
    }

    if (dp[si][ei].first != 0)
        return dp[si][ei];

    pair<int, string> minAns = {1e7, ""};
    for (int cut = si + 1; cut < ei; cut++)
    {
        pair<int, string> left = matrixChainMultiplicationMemoString(arr, si, cut, dp);
        pair<int, string> right = matrixChainMultiplicationMemoString(arr, cut, ei, dp);

        int myCost = left.first + arr[si] * arr[cut] * arr[ei] + right.first;
        if (myCost < minAns.first)
        {
            minAns.first = myCost;
            minAns.second = "(" + left.second + right.second + ")";
        }
    }

    dp[si][ei] = minAns;
    return minAns;
}

//PROGRAM 67
//TO MINIMIZE THE COST OF MULTIPLICATION OF A GIVEN NUMBER OF MATRICES USING TABULATIOM
//TO PRINT THE ORDER OF MULTIPLICATION OF THE MATRICES
int matrixChainMultiplicationTabString(vector<int> &arr, vector<vector<int>> &dp)
{
    int n = arr.size();
    vector<vector<string>> sdp(n, vector<string>(n, ""));

    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (si + 1 == ei)
            {
                sdp[si][ei] = string(1, char(si + 'A'));
                continue;
            }

            int minAns = 1e8;
            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut][ei];

                int netCost = left + arr[si] * arr[cut] * arr[ei] + right;
                if (netCost < minAns)
                {
                    dp[si][ei] = netCost;
                    minAns = netCost;
                    sdp[si][ei] = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }
        }
    }

    cout << sdp[0][arr.size() - 1] << " -> " << dp[0][arr.size() - 1] << endl;
    return dp[0][arr.size() - 1];
}

//PROGRAM 68
//TO FIND THE NUMBER OF MINIMUM PALINDROMIC CUTS TO CONVERT A STRING
//INTO PALIDROMIC SUBSTRINGS USING MEMOIZATION
int minimumPalindromicCutMemo(string s, int si, int ei, vector<vector<int>> &dp, vector<vector<bool>> &isPalindrome)
{
    if (si == ei || isPalindrome[si][ei])
        return dp[si][ei] = 0;

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int minCut = 1e8;
    for (int cut = si; cut < ei; cut++)
    {
        int left = minimumPalindromicCutMemo(s, si, cut, dp, isPalindrome);
        int right = minimumPalindromicCutMemo(s, cut + 1, ei, dp, isPalindrome);
        int palindromicCuts = left + 1 + right;
        minCut = min(minCut, palindromicCuts);
    }

    return dp[si][ei] = minCut;
}

//PROGRAM 69
//TO FIND THE NUMBER OF MINIMUM PALINDROMIC CUTS TO CONVERT A STRING
//INTO PALIDROMIC SUBSTRINGS USING TABULATION
int minimumPalindromicCutTab(string s, vector<vector<int>> &dp, vector<vector<bool>> &isPalindrome)
{
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < s.length(); si++, ei++)
        {
            if (isPalindrome[si][ei])
            {
                dp[si][ei] = 0;
                continue;
            }

            int minCut = 1e8;
            for (int cut = si; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut + 1][ei];
                int palindromicCuts = left + 1 + right;
                minCut = min(minCut, palindromicCuts);
            }

            dp[si][ei] = minCut;
        }
    }

    return dp[0][s.length() - 1];
}

//PROGRAM 70
//TO FIND THE NUMBER OF MINIMUM PALINDROMIC CUTS TO CONVERT A STRING
//INTO PALIDROMIC SUBSTRINGS USING MEMOIZATION WITH SPEED OPTIMIZATION
int minimumPalindromicCutMemoOptimized(string s, int si, int ei, vector<int> &dp, vector<vector<bool>> &isPalindrome)
{
    if (si > ei)
        return -1;

    if (dp[si] != -1)
        return dp[si];

    int minCut = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        if (isPalindrome[si][cut])
        {
            int palindromicCut = minimumPalindromicCutMemoOptimized(s, cut + 1, ei, dp, isPalindrome) + 1;
            minCut = min(minCut, palindromicCut);
        }
    }

    return dp[si] = minCut;
}

//PROGRAM 71
//TO FIND THE NUMBER OF MINIMUM PALINDROMIC CUTS TO CONVERT A STRING
//INTO PALIDROMIC SUBSTRINGS USING TABULATION WITH SPEED OPTIMIZATION
int minimumPalindromicCutTabOptimized(string s, vector<int> &dp, vector<vector<bool>> &isPalindrome)
{
    int ei = s.length() - 1;
    for (int si = ei; si >= 0; si--)
    {
        int minCut = 1e8;
        for (int cut = si; cut <= ei; cut++)
        {
            if (isPalindrome[si][cut])
            {
                int palindromicCut = ((cut + 1 == ei + 1) ? -1 : dp[cut + 1]) + 1;
                minCut = min(minCut, palindromicCut);
            }
        }

        dp[si] = minCut;
    }

    return dp[0];
}

//PROGRAM 72
//TO MINIMIZE THE COST OF SEARCHING IN A BINARY SEARCH TREE USING MEMOIZATION
//REFER GEEKSFORGEEKS
int frequencySum(vector<int> &freq, int si, int ei)
{
    int sum = 0;
    for (int i = si; i <= ei; i++)
        sum += freq[i];
    return sum;
}

int optimalBinarySearchTreeMemo(vector<int> &keys, vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int minAns = 1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = (cut == si) ? 0 : optimalBinarySearchTreeMemo(keys, freq, si, cut - 1, dp);
        int right = (cut == ei) ? 0 : optimalBinarySearchTreeMemo(keys, freq, cut + 1, ei, dp);

        int ans = left + frequencySum(freq, si, ei) + right;
        minAns = min(minAns, ans);
    }

    return dp[si][ei] = minAns;
}

//PROGRAM 73
//TO MINIMIZE THE COST OF SEARCHING IN A BINARY SEARCH TREE USING TABULATION
//REFER GEEKSFORGEEKS
int optimalBinarySearchTreeTab(vector<int> &keys, vector<int> &freq, vector<vector<int>> &dp)
{
    for (int gap = 0; gap < keys.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < keys.size(); si++, ei++)
        {
            int minAns = 1e8;
            for (int cut = si; cut <= ei; cut++)
            {
                int left = (cut == si) ? 0 : dp[si][cut - 1];
                int right = (cut == ei) ? 0 : dp[cut + 1][ei];

                int ans = left + right;
                minAns = min(minAns, ans);
            }

            dp[si][ei] = minAns + ((minAns == 1e8) ? 0 : frequencySum(freq, si, ei));
        }
    }

    return dp[0][keys.size() - 1];
}

//PROGRAM 74
//REFER LEETCODE MAXIMUM COINS AFTER BURSTING BALLOONS
int burstBalloons(vector<int> &balloons, int si, int ei, vector<vector<int>> &dp)
{
    if(dp[si][ei] != 0)
        return dp[si][ei];

    int l = (si - 1 == -1) ? 1 : balloons[si - 1];
    int r = (ei + 1 == balloons.size()) ? 1 : balloons[ei + 1];

    int maxCost = -1e8;
    for (int cut = si; cut <= ei; cut++)
    {
        int left = (cut == si) ? 0 : burstBalloons(balloons, si, cut - 1, dp);
        int right = (cut == ei) ? 0 : burstBalloons(balloons, cut + 1, ei, dp);

        int cost = left + (l * balloons[cut] * r) + right;

        maxCost = max(maxCost, cost);
    }

    return dp[si][ei] = maxCost;
}

//SET 5
void cutType()
{
    vector<int> arr = {30,35,15,5,10,20,25};
    vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
    // cout << matrixChainMultiplicationMemo(arr, 0, arr.size() - 1, dp) << endl;
    // cout << matrixChainMultiplicationTab(arr, dp) << endl;
    // vector<vector<pair<int,string>>> dp(arr.size(), vector<pair<int,string>>(arr.size(), {0,""}));
    // pair<int,string> p=matrixChainMultiplicationMemoString(arr, 0, arr.size() - 1, dp);
    // cout<< p.first << " -> "<< p.second;
    // cout << matrixChainMultiplicationTabString(arr, dp) << endl;
    // display2D(dp);

    //====================================================

    // string s = "aabbbabab";
    // vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    // vector<vector<bool>> isPalindrome = isPalindromicSubstring(s);
    // cout << minimumPalindromicCutMemo(s, 0, s.length() - 1, dp, isPalindrome) << endl;
    // cout << minimumPalindromicCutTab(s, dp, isPalindrome) << endl;
    // vector<int> dp(s.length(), -1);
    // cout << minimumPalindromicCutMemoOptimized(s, 0, s.length() - 1, dp, isPalindrome) << endl;
    // cout << minimumPalindromicCutTabOptimized(s,dp,isPalindrome) << endl;
    // display2D(dp);

    //====================================================

    // vector<int> keys = {10, 12, 20};
    // vector<int> freq = {34, 8, 50};
    // vector<vector<int>> dp(keys.size(), vector<int>(keys.size(), 0));
    // cout << optimalBinarySearchTreeMemo(keys, freq, 0, keys.size()-1, dp) << endl;
    // cout << optimalBinarySearchTreeTab(keys, freq, dp) << endl;
    // display2D(dp);

    //====================================================

    // vector<int> balloons = {3,1,5,8};
    // vector<vector<int>> dp(balloons.size(),vector<int>(balloons.size(),0));
    // cout << burstBalloons(balloons,0,balloons.size()-1,dp);

    //====================================================
}

//==================================================================================================

//MAIN
int main(int argc, char **argv)
{
    basic();
    pathType();
    dpProblems_Set_1();
    dpProblems_Set_2_Subsequences();
    cutType();
}