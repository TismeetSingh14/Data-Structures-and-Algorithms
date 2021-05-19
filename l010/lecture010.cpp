//lecture010
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TOOL PROGRAM
// HELPER PROGRAM TO DISPLAY VECTORS
void display(vector<string> &arr)
{
    for (string ele : arr)
    {
        cout << ele << " ";
    }
}

// PROGRAM 1
// REMOVES ALL INSTANCES OF "hi" FROM INPUT STRING
string removehi(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    if (s.length() > 1 && s.substr(0, 2) == "hi")
    {
        return removehi(s.substr(2));
    }

    else
    {
        return ch + removehi(s.substr(1));
    }
}

// PROGRAM 2
// REMOVES ALL INSTANCES OF "hi" FROM INPUT STRINGS BUT NOT HIT
string removehi_nothit(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];

    if (s.length() > 1 && s.substr(0, 2) == "hi" && s.substr(0, 3) != "hit")
    {
        return removehi_nothit(s.substr(2));
    }

    else
    {
        return ch + removehi_nothit(s.substr(1));
    }
}

// PROGRAM 3
// REMOVING ALL CONSECUTIVE DUPLICATES FROM THE STRING
string removeduplicates(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];

    if (ch == s[1] && s.length() > 1)
    {
        return removeduplicates(s.substr(1));
    }

    else
    {
        return ch + removeduplicates(s.substr(1));
    }
}

// PROGRAM 4
// RETURNING ALL SUBSEQUENCES(SUBSETS) OF A STRING IN A VECTOR
vector<string> subsequences(string s)
{
    if (s.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = s[0];
    vector<string> ans = subsequences(s.substr(1));
    vector<string> netans(ans);

    for (string ele : ans)
    {
        netans.push_back(ch + ele);
    }

    return netans;
}

// SET 1
void basic()
{
    // cout<<removehi("hihihihihihhii");
    // cout<<removehi_nothit("hithihithihhiitt");
    // cout<<removeduplicates("aaaabbbccdeeeeffghh");
    // vector<string>myans=subsequences("abbccdd");
    // display(myans);
}

// PROGRAM 5
// RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL MOVES)
vector<string> mazepath2dir(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> ans;

    if (sc + 1 <= ec)
    {
        vector<string> horizontal = mazepath2dir(sr, sc + 1, er, ec);
        for (string ele : horizontal)
        {
            ans.push_back('h' + ele);
        }
    }

    if (sr + 1 <= er)
    {
        vector<string> vertical = mazepath2dir(sr + 1, sc, er, ec);
        for (string ele : vertical)
        {
            ans.push_back('v' + ele);
        }
    }

    return ans;
}

// PROGRAM 6
// RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL,DIAGONAL MOVES)
vector<string> mazepath3dir(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> ans;

    if (sc + 1 <= ec)
    {
        vector<string> horizontal = mazepath3dir(sr, sc + 1, er, ec);
        for (string ele : horizontal)
        {
            ans.push_back('h' + ele);
        }
    }

    if (sr + 1 <= er)
    {
        vector<string> vertical = mazepath3dir(sr + 1, sc, er, ec);
        for (string ele : vertical)
        {
            ans.push_back('v' + ele);
        }
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        vector<string> diagonal = mazepath3dir(sr + 1, sc + 1, er, ec);
        for (string ele : diagonal)
        {
            ans.push_back('d' + ele);
        }
    }

    return ans;
}

// PROGRAM 7
// MAX HEIGHT OF RECURSION TREE FORMED IN THE ABOVE QUESTION
int maxheightmazepath3dir(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        return 0;
    }

    int horz = 0;
    int vert = 0;
    int diag = 0;

    if (sc + 1 <= ec)
    {
        horz = maxheightmazepath3dir(sr, sc + 1, er, ec);
    }

    if (sr + 1 <= er)
    {
        vert = maxheightmazepath3dir(sr + 1, sc, er, ec);
    }

    if (sc + 1 <= ec && sr + 1 <= er)
    {
        diag = maxheightmazepath3dir(sr + 1, sc + 1, er, ec);
    }

    return max(vert, max(horz, diag)) + 1;
}

// PROGRAM 8
// BRANCH WITH MAX HEIGHT IN THE ABOVE QUESTION
int maxheighttreemazepath3dir(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans;
        return 0;
    }

    int horz = 0;
    int vert = 0;
    int diag = 0;

    if (sc + 1 <= ec)
    {
        horz = maxheighttreemazepath3dir(sr, sc + 1, er, ec, ans + "h");
    }

    if (sr + 1 <= er)
    {
        vert = maxheighttreemazepath3dir(sr + 1, sc, er, ec, "v");
    }

    if (sc + 1 <= ec && sr + 1 <= er)
    {
        diag = maxheighttreemazepath3dir(sr + 1, sc + 1, er, ec, "d");
    }

    return max(vert, max(horz, diag)) + 1;
}

// PROGRAM 9
// RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL,DIAGONAL MOVES) WITH MULTI MOVES
vector<string> mazepathmulti3dir(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> ans;

    for (int i = 1; i <= er + 1; i++)
    {
        if (sr + i <= er)
        {
            vector<string> vertical = mazepathmulti3dir(sr + i, sc, er, ec);
            for (string ele : vertical)
            {
                ans.push_back('v' + to_string(i) + ele);
            }
        }
    }

    for (int i = 1; i <= ec + 1; i++)
    {
        if (sc + i <= ec)
        {
            vector<string> horizontal = mazepathmulti3dir(sr, sc + i, er, ec);
            for (string ele : horizontal)
            {
                ans.push_back('h' + to_string(i) + ele);
            }
        }
    }

    for (int i = 1; i <= min(er, ec) + 1; i++)
    {
        if (sc + i <= ec && sr + i <= er)
        {
            vector<string> diagonal = mazepathmulti3dir(sr + i, sc + i, er, ec);
            for (string ele : diagonal)
            {
                ans.push_back('d' + to_string(i) + ele);
            }
        }
    }

    return ans;
}

//SET 2
void mazepath()
{
    // vector<string>myans=mazepath2dir(0,0,3,3);
    // vector<string>myans=mazepath3dir(0,0,3,3);
    // vector<string> myans = mazepathmulti3dir(0, 0, 2, 2);
    // display(myans);
    // cout<<maxheightmazepath3dir(0,0,1,1);
    // cout<<maxheighttreemazepath3dir(0,0,2,2,"");
}

// PROGRAM 10
// TO CHECK WHETHER IT IS SAFE TO MAKE THE FUNCTION CALL
bool issafe(int x, int y, int er, int ec, vector<vector<bool>> &board)
{
    if (x < 0 || y < 0 || x > er || y > ec || board[x][y])
    {
        return false;
    }

    else
    {
        return true;
    }
}

// FLOODFILL(MAZEPATH WITH 8 DIRECTION CALL)
int alldirectionmaze(int sr, int sc, int er, int ec, vector<vector<bool>> &board, string ans)
{
    vector<vector<int>> dir = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    vector<string> direc = {"r", "1", "u", "2", "l", "3", "d", "4"};

    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    board[sr][sc] = true;

    for (int i = 0; i < 8; i++)
    {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];

        if (issafe(x, y, er, ec, board))
        {
            count = count + alldirectionmaze(x, y, er, ec, board, ans + direc[i]);
        }
    }
    board[sr][sc] = false;
    return count;
}

// PROGRAM 11
// TO CHECK WHETHER IT IS SAFE TO MAKE THE FUNCTION CALL
bool issafe_(int x, int y, vector<vector<bool>> &board)
{
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y])
    {
        return false;
    }

    else
    {
        return true;
    }
}

//TO FIND A WAY FOR RAT TO COME OUT OF THE MAZE WITH OBSTACLES
int ratinmaze(int sr, int sc, int er, int ec, vector<vector<bool>> &board, string ans)
{
    vector<vector<int>> dir = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}};
    vector<string> direc = {"r", "1", "u", "2", "l", "3", "d", "4"};

    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    board[sr][sc] = true;

    for (int i = 0; i < 8; i++)
    {
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];

        if (issafe_(x, y, board))
        {
            count = count + ratinmaze(x, y, er, ec, board, ans + direc[i]);
        }
    }

    board[sr][sc] = false;
    return count;
}

//SET 3
void floodfill()
{
    string ans = "";
    vector<vector<bool>> board(5, vector<bool>(5, false));
    board[0][0] = true;
    board[1][2] = true;
    board[2][1] = true;
    board[2][2] = true;
    board[2][4] = true;
    board[3][1] = true;
    board[4][2] = true;
    //alldirectionmaze(0,0,2,2,board,ans);
    ratinmaze(0, 1, 4, 3, board, ans);

    //MISCELLANOUS -> FLOODFILL SHORTEST PATH
    /* public static pair floodfill_ShortestPath(int sr, int sc, int er, int ec, int[][] board) {
		if (sr == er && sc == ec) {
			return new pair(0, ""); //c++ -> INT_MAX;
		}

		board[sr][sc] = 2;

		pair mypair = new pair((int) 1e7, "");

		for (int d = 0; d < dir.length; d++) {
			int r = sr + dir[d][0];
			int c = sc + dir[d][1];
			if (r >= 0 && c >= 0 && r < board.length && c < board[0].length && board[r][c] == 0) {
				pair recP = floodfill_ShortestPath(r, c, er, ec, board);

				if (recP.len + 1 < mypair.len) {
					mypair.len = recP.len + 1;
					mypair.str = dirN[d] + recP.str;
				}
			}
		}

		board[sr][sc] = 0;
		return mypair;
	}*/
}

// PROGRAM 12
// TO RETURN PERMUTATIONS OF A STRING IN A VECTOR
vector<string> permutationstring(string s)
{
    if (s.length() == 1)
    {
        vector<string> base;
        base.push_back(s);
        return base;
    }

    vector<string> myans;
    char ch = s[0];
    vector<string> ans = permutationstring(s.substr(1));

    for (string ele : ans)
    {
        for (int i = 0; i <= ele.length(); i++)
        {
            myans.push_back(ele.substr(0, i) + ch + ele.substr(i));
        }
    }
    return myans;
}

// PROGRAM 13
// NOKIA KEYPAD STRING DECODING
vector<string> chars = {"_", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz", "&()%", "#@$"};
vector<string> nokiakeypad(string s)
{
    if (s.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = s[0];
    string word = chars[ch - '0'];

    vector<string> netans;
    vector<string> ans = nokiakeypad(s.substr(1));

    for (string ele : ans)
    {
        for (int i = 0; i < word.length(); i++)
        {
            netans.push_back(word[i] + ele);
        }
    }

    if (s.length() > 1 && ch != '0')
    {
        int num = (ch - '0') * 10 + s[1] - '0';

        if (num < 12)
        {
            string word1 = chars[num];
            vector<string> ans1 = nokiakeypad(s.substr(2));

            for (string ele : ans1)
            {
                for (int i = 0; i < word1.length(); i++)
                {
                    netans.push_back(word1[i] + ele);
                }
            }
        }
    }

    return netans;
}

// PROGRAM 14
// DECODING STRING MAPPED 1-A 2-B 3-C ....... 25-Y 26-Z
vector<string> mapping(string s)
{
    if (s.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    char ch = s[0];
    vector<string> netans;

    if (ch == '0')
    {
        return mapping(s.substr(1));
    }

    char ch1 = (char)('a' + ch - '1');
    vector<string> ans = mapping(s.substr(1));

    for (string ele : ans)
    {
        netans.push_back(ch1 + ele);
    }

    if (s.length() > 1 && ch != '0')
    {
        int num = (ch - '0') * 10 + (s[1] - '0');

        if (num < 27)
        {
            char ch2 = (char)('a' + (num - 1));
            vector<string> ans1 = mapping(s.substr(2));

            for (string ele : ans1)
            {
                netans.push_back(ch2 + ele);
            }
        }
    }

    return netans;
}

//SET 4
void permutation()
{
    // vector<string>myans=permutationstring("abc");
    // vector<string>myans=nokiakeypad("11");
    // vector<string>myans=mapping("123");
    // display(myans);
}

//MAIN
int main(int argc, char **argv)
{
    // basic();
    // mazepath();
    // floodfill();
    // permutation();
}