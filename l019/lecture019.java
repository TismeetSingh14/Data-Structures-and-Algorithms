// lecture 19
import java.util.*;

public class lecture019 {
    public static Scanner scn = new Scanner(System.in);

    // PROGRAM 1
    // WILDCARD MATCHING REFER LEETCODE 
    public static int wildCardMatching(String s, String p, int i, int j, int[][] dp) {
        if (i == s.length() && j == p.length())
            return dp[i][j] = 1;
        if (i == s.length() || j == p.length()) {
            if (i != s.length())
                return dp[i][j] = 0;

            return dp[i][j] = (p.charAt(j) == '*' && p.length() - j == 1) ? 1 : 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        char ch1 = s.charAt(i);
        char ch2 = p.charAt(j);
        boolean res = false;
        if (ch1 == ch2 || ch2 == '?')
            res = wildCardMatching(s, p, i + 1, j + 1, dp) == 1;
        else if (ch2 == '*') {
            res = res || wildCardMatching(s, p, i, j + 1, dp) == 1; // as a empty string mapping ('*' treated as a "").
            res = res || wildCardMatching(s, p, i + 1, j, dp) == 1; // sequence mapping.("*" treated as a substring).
        }

        return dp[i][j] = res ? 1 : 0;
    }

    public static String removeStar(String str) {
        StringBuilder sb = new StringBuilder();
        boolean firstStar = false;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '*') {
                if (!firstStar)
                    sb.append(ch);
                firstStar = true;
            } else {
                sb.append(ch);
                firstStar = false;
            }
        }

        return sb.toString();
    }

    public static int isMatch(String s, String p) {

        p = removeStar(p);
        int[][] dp = new int[s.length() + 1][p.length() + 1];
        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < p.length(); j++)
                dp[i][j] = -1;
        return wildCardMatching(s, p, 0, 0, dp);
    }

    public static void main(String[] args) {
        String s = scn.nextLine();
        String p = scn.nextLine();
        System.out.println(isMatch(s, p) == 1);
    }
}