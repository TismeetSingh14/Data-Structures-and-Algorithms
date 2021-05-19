//lecture012
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// PROGRAM 1
int coinpermutationinfinite(vector<int> &arr, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coinpermutationinfinite(arr, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

// PROGRAM 2
int coincombinationinfinite(vector<int> &arr, int idx, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coincombinationinfinite(arr, i, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

// PROGRAM 3
int coincombination(vector<int> &arr, int idx, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0)
        {
            count += coincombination(arr, i + 1, target - arr[i], ans + to_string(arr[i]) + " ");
        }
    }

    return count;
}

// PROGRAM 4
int coincombinationinfinitesubsequences(vector<int> &arr, int idx, int target, string ans)
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
        count += coincombinationinfinitesubsequences(arr, idx, target - arr[idx], ans + to_string(arr[idx]) + " ");
    }

    count += coincombinationinfinitesubsequences(arr, idx + 1, target, ans);

    return count;
}

// PROGRAM 5
int coincombinationsubsequences(vector<int> &arr, int idx, int target, string ans)
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
        count += coincombinationsubsequences(arr, idx + 1, target - arr[idx], ans + to_string(arr[idx]) + " ");
    }

    count += coincombinationsubsequences(arr, idx + 1, target, ans);

    return count;
}

// PROGRAM 6
int coinpermutation(vector<int> &arr, vector<bool> &visit, int target, string ans)
{
    if (target == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (target - arr[i] >= 0 && visit[i] == false)
        {
            visit[i] = true;
            count += coinpermutation(arr, visit, target - arr[i], ans + to_string(arr[i]) + " ");
            visit[i] = false;
        }
    }

    return count;
}

// PROGRAM 7
int coinpermutationsubsequences(vector<int> &arr, vector<bool> &visit, int idx, int target, string ans)
{
    if (target == 0 || idx == arr.size())
    {
        if (target == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (target - arr[idx] >= 0 && visit[idx] == false)
    {
        visit[idx] = true;
        count += coinpermutationsubsequences(arr, visit, 0, target - arr[idx], ans + to_string(arr[idx]) + " ");
        visit[idx] = false;
    }

    count += coinpermutationsubsequences(arr, visit, idx + 1, target, ans);

    return count;
}

//SET 1
void coinchange()
{
    vector<int>arr={2,3,5,6};
    // vector<bool>visit(arr.size(),false);
    // cout<<coinpermutationinfinite(arr,10,"");
    // cout<<coincombinationinfinite(arr,0,10,"");
    // cout<<coincombination(arr,0,10,"");
    // cout<<coincombinationinfinitesubsequences(arr,0,10,"");
    // cout<<coincombinationsubsequences(arr,0,10,"");
    // cout<<coinpermutation(arr,visit,10,"");
    // cout<<coinpermutationsubsequences(arr,visit,0,10,"");
}

// PROGRAM 8
int nqueenspermutation(int queens, vector<bool> &boxes, string ans)
{
    if (queens == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < boxes.size(); i++)
    {
        if (boxes[i] == false)
        {
            boxes[i] = true;
            count += nqueenspermutation(queens - 1, boxes, ans + "q" + to_string(queens) + " " + "b" + to_string(i) + " ");
            boxes[i] = false;
        }
    }

    return count;
}

// PROGRAM 9
int nqueenscombination(int queens, int idx, vector<bool> &boxes, string ans)
{
    if (queens == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size(); i++)
    {
        count += nqueenscombination(queens - 1, i + 1, boxes, ans + "q" + to_string(queens) + " " + "b" + to_string(i) + " ");
    }

    return count;
}

// PROGRAM 10
int nqueenspermutationsubsequences(int queens, int idx, vector<bool> &boxes, string ans)
{
    if (idx == boxes.size() || queens == 0)
    {
        if (queens == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (queens > 0 && boxes[idx] == false)
    {
        boxes[idx] = true;
        count += nqueenspermutationsubsequences(queens - 1, 0, boxes, ans + "q" + to_string(queens) + " " + "b" + to_string(idx) + " ");
        boxes[idx] = false;
    }

    count += nqueenspermutationsubsequences(queens, idx + 1, boxes, ans);

    return count;
}

// PROGRAM 11
int nqueenscombinationsubsequences(int queens, int idx, vector<bool> &boxes, string ans)
{
    if (idx == boxes.size() || queens == 0)
    {
        if (queens == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    if (queens > 0)
    {
        count += nqueenscombinationsubsequences(queens - 1, idx + 1, boxes, ans + "q" + to_string(queens) + " " + "b" + to_string(idx) + " ");
    }

    count += nqueenscombinationsubsequences(queens, idx + 1, boxes, ans);

    return count;
}

// PROGRAM 12
int nqueens2dpermutation(int queens, vector<vector<bool>> &boxes, string ans)
{
    if (queens == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = 0; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();

        if (boxes[x][y] == false)
        {
            boxes[x][y] = true;
            count += nqueens2dpermutation(queens - 1, boxes, ans + "q" + to_string(queens) + " b " + to_string(x) + "," + to_string(y) + " ");
            boxes[x][y] = false;
        }
    }

    return count;
}

// PROGRAM 13
int nqueens2dcombination(int queens, int idx, vector<vector<bool>> &boxes, string ans)
{
    if (queens == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();

        count += nqueens2dcombination(queens - 1, i + 1, boxes, ans + "q" + to_string(queens) + " b " + to_string(x) + "," + to_string(y) + " ");
    }

    return count;
}

// PROGRAM 14
bool issafetoplacequeen(vector<vector<bool>> boxes, int x, int y)
{
    int r = 0;
    int c = 0;
    vector<int> xdir = {0, -1, -1, -1};
    vector<int> ydir = {-1, -1, 0, 1};

    for (int rad = 1; rad < max(boxes.size(), boxes[0].size()); rad++)
    {
        for (int d = 0; d < 4; d++)
        {
            r = x + xdir[d] * rad;
            c = y + ydir[d] * rad;

            if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes[0].size() && boxes[r][c])
            {
                return false;
            }
        }
    }

    return true;
}

int nqueensproblem(int queens, int idx, vector<vector<bool>> &boxes, string ans)
{
    if (queens == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();

        if (issafetoplacequeen(boxes, x, y))
        {
            boxes[x][y] = true;
            count += nqueensproblem(queens - 1, i + 1, boxes, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
            boxes[x][y] = false;
        }
    }

    return count;
}

// PROGRAM 15
int nqueensproblemsubsequences(int queens, int idx, vector<vector<bool>> &boxes, string ans)
{
    if (queens == 0 || idx == boxes.size() * boxes[0].size())
    {
        if (queens == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;

    int x = idx / boxes[0].size();
    int y = idx % boxes[0].size();

    if (issafetoplacequeen(boxes, x, y))
    {
        boxes[x][y] = true;
        count += nqueensproblemsubsequences(queens - 1, idx + 1, boxes, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
        boxes[x][y] = false;
    }

    count += nqueensproblemsubsequences(queens, idx + 1, boxes, ans);

    return count;
}

// PROGRAM 16
bool issafetoplaceknight(vector<vector<bool>> &boxes, int x, int y)
{
    int xdir[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int ydir[8] = {2, 2, 1, -1, -2, -2, -1, 1};

    for (int d = 0; d < 8; d++)
    {
        int r = x + xdir[d];
        int c = y + ydir[d];

        if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes[0].size() && boxes[r][c])
        {
            return false;
        }
    }

    return true;
}

int nknightsproblem(int knights, int idx, vector<vector<bool>> &boxes, string ans)
{
    if (knights == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;

    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if (issafetoplaceknight(boxes, x, y))
        {
            boxes[x][y] = true;
            count += nknightsproblem(knights - 1, i + 1, boxes, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
            boxes[x][y] = false;
        }
    }

    return count;
}

//SET 2
void nqueen()
{
    // vector<bool>boxes(6,false);
    // vector<vector<bool>>boxes(4,vector<bool>(4,false));
    // cout<<nqueenspermutation(3,boxes,"");
    // cout<<nqueenscombination(3,0,boxes,"");
    // cout<<nqueenspermutationsubsequences(3,0,boxes,"");
    // cout<<nqueenscombinationsubsequences(3,0,boxes,"");
    // cout<<nqueens2dpermutation(2,boxes,"");
    // cout<<nqueens2dcombination(2,0,boxes,"");
    // cout<<nqueensproblem(4,0,boxes,"");
    // cout<<nqueensproblemsubsequences(4,0,boxes,"");
    // cout<<nknightsproblem(9,0,boxes,"");


    // N QUEENS ALTERNATE SOLUTION CHECK IN O(1)
    // vector<bool> col(30, false);
    // vector<bool> diag1(30, false);
    // vector<bool> diag2(30, false);

    // int nQueensProblem(int noq, string ans, int r, int n)
    // {
    //     if (r == n)
    //     {
    //         cout << ans << endl;
    //         return 1;
    //     }

    //     int count = 0;
    //     for (int c = 0; c < n; c++)
    //     {
    //         if (col[c] == false && diag1[r + c] == false && diag2[n + r - c - 1] == false)
    //         {
    //             col[c] = diag1[r + c] = diag2[n + r - c - 1] = true;
    //             count += nQueensProblem(noq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ", r + 1, n);
    //             col[c] = diag1[r + c] = diag2[n + r - c - 1] = false;
    //         }
    //     }

    //     return count;
    // }
}

// PROGRAM 17
string s1 = "send";
string s2 = "more";
string s3 = "money";
vector<int> mapchartonumber(26, 0);
vector<bool> check(10, 0);

string generate_string()
{
    vector<int> freqmap(26, 0);
    string s = s1 + s2 + s3;

    for (int i = 0; i < s.length(); i++)
    {
        freqmap[s[i] - 'a']++;
    }

    string str = "";
    for (int i = 0; i < 26; i++)
    {
        if (freqmap[i] > 0)
        {
            str = str + (char)(i + 'a');
        }
    }
    return str;
}

int string_to_number(string s)
{
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        ans = ans * 10 + mapchartonumber[s[i] - 'a'];
    }
    return ans;
}

int cryptosimple(string s, int idx)
{
    if (idx == s.length())
    {
        int n1 = string_to_number(s1);
        int n2 = string_to_number(s2);
        int n3 = string_to_number(s3);

        if (n1 + n2 == n3 && mapchartonumber[s3[0] - 'a'] != 0 && mapchartonumber[s2[0] - 'a'] != 0 && mapchartonumber[s1[0] - 'a'] != 0)
        {
            cout << n1 << " " << n2 << " " << n3 << endl;
            return 1;
        }

        return 0;
    }

    int count = 0;

    for (int num = 9; num >= 0; num--)
    {
        if (check[num] == false)
        {
            check[num] = true;
            mapchartonumber[s[idx] - 'a'] = num;
            count += cryptosimple(s, idx + 1);
            check[num] = false;
        }
    }

    return count;
}

// PROGRAM 18
int cryptosubsequences(string s, int idx, int num)
{
    if (idx == s.length() || num == -1)
    {
        if (num == -1)
        {
            int n1 = string_to_number(s1);
            int n2 = string_to_number(s2);
            int n3 = string_to_number(s3);

            if (n1 + n2 == n3 && mapchartonumber[s3[0] - 'a'] != 0 && mapchartonumber[s2[0] - 'a'] != 0 && mapchartonumber[s1[0] - 'a'] != 0)
            {
                cout << n1 << " " << n2 << " " << n3 << endl;
                return 1;
            }
        }

        return 0;
    }

    int count = 0;

    if (check[num] == false)
    {
        check[num] = true;
        mapchartonumber[s[idx] - 'a'] = num;
        count += cryptosubsequences(s, idx + 1, 9);
        check[num] = false;
    }

    count += cryptosubsequences(s, idx, num - 1);
    return count;
}

//SET 3
void crypto()
{
    string s0 = generate_string();
    cout << cryptosimple(s0, 0);
    // cout<<cryptosubsequences(s0,0,9);
}

// PROGRAM 19
bool issafetoplacenumber(vector<vector<int>> board, int x, int y, int data)
{
    for (int i = 0; i < board[0].size(); i++)
    {
        if (board[i][y] == data)
        {
            return false;
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        if (board[x][i] == data)
        {
            return false;
        }
    }

    x = (x / 3) * 3;
    y = (y / 3) * 3;

    for (int i = 0; i < board.size() / 3; i++)
    {
        for (int j = 0; j < board[0].size() / 3; j++)
        {
            if (board[x + i][y + j] == data)
                return false;
        }
    }

    return true;
}

int sudokusolutions(int idx, vector<vector<int>> &board)
{
    if (idx == board.size() * board[0].size())
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return 1;
    }

    int count = 0;
    int x = idx / board[0].size();
    int y = idx % board[0].size();

    if (board[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (issafetoplacenumber(board, x, y, i))
            {
                board[x][y] = i;
                count += sudokusolutions(idx + 1, board);
                board[x][y] = 0;
            }
        }
    }

    else
    {
        count += sudokusolutions(idx + 1, board);
    }

    return count;
}

// PROGRAM 20
int sudokusolutionssubsequences(int idx, int num, vector<vector<int>> &board)
{
    if (idx == board.size() * board[0].size() || num == 10)
    {
        if (idx == board.size() * board[0].size())
        {
            for (int i = 0; i < board.size(); i++)
            {
                for (int j = 0; j < board[0].size(); j++)
                {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
            return 1;
        }
        return 0;
    }

    int count = 0;
    int x = idx / board[0].size();
    int y = idx % board[0].size();

    if (board[x][y] == 0)
    {
        if (issafetoplacenumber(board, x, y, num))
        {
            board[x][y] = num;
            count += sudokusolutionssubsequences(idx + 1, 1, board);
            board[x][y] = 0;
        }
    }

    else
    {
        count += sudokusolutionssubsequences(idx + 1, num, board);
    }

    return count;
}

// PROGRAM 21
int sudokusolutionslesscalls(vector<int> &calls, vector<vector<int>> &board, int idx)
{
    if (idx == calls.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return 1;
    }

    int count = 0;
    int x = calls[idx] / 9;
    int y = calls[idx] % 9;

    for (int num = 1; num <= 9; num++)
    {
        if (issafetoplacenumber(board, x, y, num))
        {
            board[x][y] = num;
            count += sudokusolutionslesscalls(calls, board, idx + 1);
            board[x][y] = 0;
        }
    }

    return count;
}

// PROGRAM 22
int row[9] = {0};
int col[9] = {0};
int mat[3][3] = {0};

int sudokusolutionsbitmasking(vector<int> &calls, vector<vector<int>> &board, int idx)
{
    if (idx == calls.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return 1;
    }

    int count = 0;
    int x = calls[idx] / 9;
    int y = calls[idx] % 9;

    for (int num = 1; num <= 9; num++)
    {
        int mask = 1 << num;
        if ((row[x] & mask) == 0 && (col[y] & mask) == 0 && (mat[x / 3][y / 3] & mask) == 0)
        {
            board[x][y] = num;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;
            count += sudokusolutionsbitmasking(calls, board, idx + 1);
            board[x][y] = 0;
            row[x] ^= mask;
            col[y] ^= mask;
            mat[x / 3][y / 3] ^= mask;
        }
    }
    return count;
}

//SET 4
void sudoku()
{
    vector<vector<int>> board = {{1, 0, 0, 0, 0, 7, 0, 6, 0},
                                 {6, 0, 0, 0, 3, 4, 0, 0, 0},
                                 {0, 0, 0, 0, 8, 0, 1, 0, 9},
                                 {8, 6, 0, 0, 0, 0, 3, 0, 0},
                                 {0, 4, 0, 0, 0, 0, 0, 2, 0},
                                 {0, 0, 1, 0, 0, 0, 0, 4, 5},
                                 {2, 0, 8, 0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 2, 7, 0, 0, 0, 8},
                                 {0, 7, 0, 6, 0, 0, 0, 0, 4}};

    //cout<<sudokusolutions(0,board);
    //cout<<sudokusolutionssubsequences(0,1,board);

    // vector<int>calls;
    // for(int i=0;i<9;i++)
    // {
    //     for(int j=0;j<9;j++)
    //     {
    //         if(board[i][j]==0)
    //         {
    //             int num=i*9+j;
    //             calls.push_back(num);
    //         }
    //     }
    // }

    // cout<<sudokusolutionslesscalls(calls,board,0);

    // vector<int>calls;
    // for(int i=0;i<9;i++)
    // {
    //     for(int j=0;j<9;j++)
    //     {
    //         if(board[i][j]==0)
    //         {
    //             int num=i*9+j;
    //             calls.push_back(num);
    //         }

    //         else
    //         {
    //             int mask=1<<board[i][j];
    //             row[i]|=mask;
    //             col[j]|=mask;
    //             mat[i/3][j/3]|=mask;
    //         }
    //     }
    // }

    // cout<<sudokusolutionsbitmasking(calls,board,0);
}

//PROGRAM 23
vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool can_place_word_vertical(string word, int r, int c)
{
    if (r == 0 && word.length() != board.size())
    {
        if (board[r + word.length()][c] != '+')
            return false;
    }

    else if (r + word.length() >= board.size() && word.length() != board.size())
    {
        if (board[r - 1][c] != '+')
            return false;
    }

    else
    {
        if (board[r - 1][c] != '+' || board[r + word.length()][c] != '+')
            return false;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (!(board[r + i][c] == '-' || board[r + i][c] == word[i]))
            return false;
    }

    return true;
}

vector<bool> place_word_vertical(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);

    for (int i = 0; i < word.length(); i++)
    {
        if (board[r + i][c] == '-')
        {
            board[r + i][c] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplace_word_vertical(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i] == true)
            board[r + i][c] = '-';
    }
}

bool can_place_word_horizontal(string word, int r, int c)
{
    if (c == 0 && word.length() != board[0].size())
    {
        if (board[r][c + word.length()] != '+')
            return false;
    }

    else if (c + word.length() >= board[0].size() && word.length() != board[0].size())
    {
        if (board[r][c - 1] != '+')
            return false;
    }

    else
    {
        if (board[r][c - 1] != '+' || board[r][c + word.length()] != '+')
            return false;
    }

    for (int i = 0; i < word.size(); i++)
    {
        if (!(board[r][c + i] == '-' || board[r][c + i] == word[i]))
            return false;
    }

    return true;
}

vector<bool> place_word_horizontal(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);

    for (int i = 0; i < word.length(); i++)
    {
        if (board[r][c + i] == '-')
        {
            board[r][c + i] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplace_word_horizontal(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i] == true)
            board[r][c + i] = '-';
    }
}

int crosswordsolutions(vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (vector<char> ar : board)
        {
            for (char ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        return 1;
    }

    string word = words[idx];
    int count = 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (can_place_word_horizontal(word, i, j))
            {
                vector<bool> pos = place_word_horizontal(word, i, j);
                count += crosswordsolutions(words, idx + 1);
                unplace_word_horizontal(i, j, pos);
            }

            if (can_place_word_vertical(word, i, j))
            {
                vector<bool> pos = place_word_vertical(word, i, j);
                count += crosswordsolutions(words, idx + 1);
                unplace_word_vertical(i, j, pos);
            }
        }
    }

    return count;
}

//SET 5
void crossword()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crosswordsolutions(words, 0);
}

// MAIN
int main(int argc, char **argv)
{
    coinchange();
    // nqueen();
    // crypto();
    // sudoku();
    // crossword();
}