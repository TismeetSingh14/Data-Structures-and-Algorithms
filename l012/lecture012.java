//lecture012
import java.util.ArrayList;
import java.util.Scanner;

public class lecture012
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    public static int permutation_infinite(int[] arr,int tar,String ans)
    {
        if(tar==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=0;i<arr.length;i++)
        {
            if(tar-arr[i]>=0)
                count+=permutation_infinite(arr,tar-arr[i],ans+arr[i]+" ");
        }

        return count;
    }

    //PROGRAM 2
    public static int combination_infinite(int[] arr,int idx,int tar,String ans)
    {
        if(tar==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=idx;i<arr.length;i++)
        {
            if(tar-arr[i]>=0)
                count+=combination_infinite(arr,i,tar-arr[i],ans+arr[i]+" ");
        }

        return count;
    }

    //PROGRAM 3
    public static int permutation(int[] arr,boolean[] vis,int tar,String ans)
    {
        if(tar==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=0;i<arr.length;i++)
        {
            if(tar-arr[i]>=0 && vis[i]==false)
            {
                vis[i]=true;
                count+=permutation(arr,vis,tar-arr[i],ans+arr[i]+" ");
                vis[i]=false;
            }
        }

        return count;
    }

    //PROGRAM 4
    public static int combination(int[] arr,int idx,int tar,String ans)
    {
        if(tar==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=idx;i<arr.length;i++)
        {
            if(tar-arr[i]>=0)
                count+=combination(arr,i+1,tar-arr[i],ans+arr[i]+" ");
        }

        return count;
    }

    //PROGRAM 5
    public static int permutation_infinite_subsequences(int[] arr,int idx,int tar,String ans)
    {
        if(tar==0 || idx==arr.length)
        {
            if(tar==0)
            {
                System.out.println(ans);
                return 1;
            }

            return 0;
        }

        int count=0;

        if(tar-arr[idx]>=0)
            count+=permutation_infinite_subsequences(arr,0,tar-arr[idx],ans+arr[idx]+" ");
        
        count+=permutation_infinite_subsequences(arr,idx+1,tar,ans);  
        
        return count;
    }

    //PROGRAM 6
    public static int combination_infinite_subsequences(int[] arr,int idx,int tar,String ans)
    {
        if(idx==arr.length || tar==0)
        {
            if(tar==0)
            {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count=0;

        if(tar-arr[idx]>=0)
            count+=combination_infinite_subsequences(arr,idx,tar-arr[idx],ans+arr[idx]+" ");

        count+=combination_infinite_subsequences(arr,idx+1,tar,ans); 
        
        return count;
    }

    //PROGRAM 7
    public static int permutation_subsequences(int[] arr,boolean[] vis,int idx,int tar,String ans)
    {
        if(tar==0 || idx==arr.length)
        {
            if(tar==0)
            {
                System.out.println(ans);
                return 1;
            }

            return 0;
        }

        int count=0;

        if(tar-arr[idx]>=0 && vis[idx]==false)
        {
            vis[idx]=true;
            count+=permutation_subsequences(arr,vis,0,tar-arr[idx],ans+arr[idx]+" ");
            vis[idx]=false;
        }
        
        count+=permutation_subsequences(arr,vis,idx+1,tar,ans);  
        
        return count;
    }

    //PROGRAM 8
    public static int combination_subsequences(int[] arr,int idx,int tar,String ans)
    {
        if(idx==arr.length || tar==0)
        {
            if(tar==0)
            {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count=0;

        if(tar-arr[idx]>=0)
            count+=combination_subsequences(arr,idx+1,tar-arr[idx],ans+arr[idx]+" ");

        count+=combination_subsequences(arr,idx+1,tar,ans); 
        
        return count;
    }

    //SET 1
    public static void coin_change()
    {
        int[] arr={2,3,5,7};
        boolean[] vis=new boolean[arr.length];
        //permutation_infinite(arr,10,"");
        //combination_infinite(arr,0,10,"");
        //permutation(arr,vis,10,"");
        //combination(arr,0,10,"");
        //permutation_infinite_subsequences(arr,0,10," ");
        //combination_infinite_subsequences(arr,0,10,"");
        //permutation_subsequences(arr,vis,0,10,"");
        //combination_subsequences(arr,0,10,"");
    }

    //PROGRAM 9
    public static int nqueens_permutation(boolean[] vis,String ans,int noq)
    {
        if(noq==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=0;i<vis.length;i++)
        {
            if(noq>=0 && vis[i]==false)
            {
                vis[i]=true;
                count+=nqueens_permutation(vis,ans+"q"+noq+" @ "+i+" ",noq-1);
                vis[i]=false;
            }
        }

        return count;
    }

    //PROGRAM 10
    public static int nqueens_combination(boolean[] vis,int idx,String ans,int noq)
    {
        if(noq==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=idx;i<vis.length;i++)
        {
            if(noq>=0)
            {
                count+=nqueens_combination(vis,i+1,ans+"q"+noq+" @ "+i+" ",noq-1);
            }
        }

        return count;
    }

    //PROGRAM 11
    public static int nqueens_permutation_subsequences(boolean[] vis,int idx,String ans,int noq)
    {
        if(noq==0 || idx==vis.length)
        {
            if(noq==0)
            {
                System.out.println(ans);
                return 1;
            }

            return 0;
        }

        int count=0;

        if(noq>=0 && vis[idx]==false)
        {
            vis[idx]=true;
            count+=nqueens_permutation_subsequences(vis,0,ans+"q"+noq+" @ "+idx+" ",noq-1);
            vis[idx]=false;
        }

        count+=nqueens_permutation_subsequences(vis,idx+1,ans,noq);

        return count;
    }

    //PROGRAM 12
    public static int nqueens_combination_subsequences(boolean[] vis,int idx,String ans,int noq)
    {
        if(noq==0 || idx==vis.length)
        {
            if(noq==0)
            {
                System.out.println(ans);
                return 1;
            }

            return 0;
        }

        int count=0;

        if(noq>=0)
        {
            count+=nqueens_combination_subsequences(vis,idx+1,ans+"q"+noq+" @ "+idx+" ",noq-1);
        }

        count+=nqueens_combination_subsequences(vis,idx+1,ans,noq);

        return count;
    }

    //PROGRAM 13
    public static int nqueens_2d_permutation(boolean[][] boxes,int noq,String ans)
    {
        if(noq==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=0;i<boxes.length*boxes[0].length;i++)
        {
            int x=i/boxes[0].length;
            int y=i%boxes[0].length;

            if(boxes[x][y]==false && noq>=0)
            {
                boxes[x][y]=true;
                count+=nqueens_2d_permutation(boxes,noq-1,ans+"q"+noq+" @ "+x+","+y);
                boxes[x][y]=false;
            }
        }

        return count;
    }

    //PROGRAM 14
    public static int nqueens_2d_combination(boolean[][] boxes,int idx,int noq,String ans)
    {
        if(noq==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=idx;i<boxes.length*boxes[0].length;i++)
        {
            int x=i/boxes[0].length;
            int y=i%boxes[0].length;

            if(noq>=0)
            {
                count+=nqueens_2d_combination(boxes,i+1,noq-1,ans+"q"+noq+" @ "+x+","+y);
            }
        }

        return count;
    }

    //PROGRAM 15
    public static boolean is_safe_to_place_queen(int x,int y,boolean[][] boxes)
    {
        int r=0;
        int c=0;
        int[] xdir={0,-1,-1,-1};
        int[] ydir={-1,-1,0,1};

        for(int rad=1;rad<Math.max(boxes.length,boxes[0].length);rad++)
        {
            for(int d=0;d<4;d++)
            {
                r=x+xdir[d]*rad;
                c=y+ydir[d]*rad;

                if(r>=0 && c>=0 && r<boxes.length && c<boxes[0].length && boxes[r][c])
                {
                    return false;
                }
            }
        }

        return true;
    }

    public static int nqueens_problem(boolean[][] boxes,int lqpsf,int noq,String ans)
    {
        if(noq==0)
        {
            System.out.println(ans);
            return 1;
        }
        
        int count=0;
        for(int i=lqpsf;i<boxes.length*boxes[0].length;i++)
        {
            int x=i/boxes[0].length;
            int y=i%boxes[0].length;

            if(is_safe_to_place_queen(x,y,boxes))
            {
                boxes[x][y]=true;
                count+=nqueens_problem(boxes,i+1,noq-1,ans+"("+x+","+y+") ");
                boxes[x][y]=false;
            }
        }

        return count;
    }

    //PROGRAM 16
    public static int nqueens_problem_subsequences(boolean[][] boxes,int lqpsf,int noq,String ans)
    {
        if(noq==0 || lqpsf==boxes.length*boxes[0].length)
        {
            if(noq==0)
            {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int x=lqpsf/boxes[0].length;
        int y=lqpsf%boxes[0].length;
        int count=0;

        if(is_safe_to_place_queen(x,y,boxes))
        {
            boxes[x][y]=true;
            count+=nqueens_problem(boxes,lqpsf+1,noq-1,ans+"("+x+","+y+") ");
            boxes[x][y]=false;
        }

        count+=nqueens_problem(boxes,lqpsf+1,noq,ans);

        return count;
    }

    //PROGRAM 17
    public static boolean is_safe_to_place_knight(int x,int y,boolean[][] boxes)
    {
        int r=0;
        int c=0;
        int[] xdir={-1,1,2,2,1,-1,-2,-2};
        int[] ydir={2,2,1,-1,-2,-2,-1,1};

        for(int d=0;d<8;d++)
        {
            r=x+xdir[d];
            c=y+ydir[d];

            if(r>=0 && c>=0 && r<boxes.length && c<boxes[0].length && boxes[r][c])
            {
                return false;
            }
        }

        return true;
    }

    public static int nknights_problem(boolean[][] boxes,int lkpsf,int nok,String ans)
    {
        if(nok==0)
        {
            System.out.println(ans);
            return 1;
        }
        
        int count=0;
        for(int i=lkpsf;i<boxes.length*boxes[0].length;i++)
        {
            int x=i/boxes[0].length;
            int y=i%boxes[0].length;

            if(is_safe_to_place_knight(x,y,boxes))
            {
                boxes[x][y]=true;
                count+=nknights_problem(boxes,i+1,nok-1,ans+"("+x+","+y+") ");
                boxes[x][y]=false;
            }
        }

        return count;
    }

    //SET 2
    public static void nqueen()
    {
        boolean[] vis=new boolean[6];
        boolean[][] boxes=new boolean[4][4];
        //nqueens_permutation(vis,"",3);
        //nqueens_combination(vis,0,"",3);
        //nqueens_permutation_subsequences(vis,0,"",3);
        //nqueens_combination_subsequences(vis,0,"",3);
        //nqueens_2d_permutation(boxes,4,"");
        //nqueens_2d_combination(boxes,0,4,"");
        //nqueens_problem(boxes,0,4,"");
        //nqueens_problem_subsequences(boxes,0,4,"");
        //nknights_problem(boxes,0,9,"");
    }

    //PROGRAM 18
    static String s1="send";
    static String s2="more";
    static String s3="money";
    static int[] map_chartonum=new int[26];
    static boolean[] check=new boolean[10];

    public static String generate_string()
    {
        String s=s1+s2+s3;
        int[] freqmap=new int[26];

        for(int i=0;i<s.length();i++)
        {
            freqmap[s.charAt(i)-'a']++;
        }

        String ans="";

        for(int i=0;i<26;i++)
        {
            if(freqmap[i]>0)
            {
                ans=ans+(char)(i+'a');
            }
        }

        return ans;
    }

    public static int string_to_number(String s)
    {
        int ans=0;

        for(int i=0;i<s.length();i++)
        {
            ans=ans*10 + map_chartonum[s.charAt(i)-'a'];
        }

        return ans;
    }

    public static int crypto_simple(String s,int idx)
    {
        if(idx==s.length())
        {
            int n1=string_to_number(s1);
            int n2=string_to_number(s2);
            int n3=string_to_number(s3);

            if(n1+n2==n3 && map_chartonum[s1.charAt(0)-'a']!=0 && map_chartonum[s2.charAt(0)-'a']!=0 && map_chartonum[s3.charAt(0)-'a']!=0)
            {
                System.out.println(n1+" + "+n2+" = "+n3);
                return 1;
            }

            return 0;
        }

        int count=0;

        for(int num=9;num>=0;num--)
        {
            if(check[num]==false)
            {
                check[num]=true;
                map_chartonum[s.charAt(idx)-'a']=num;
                count+=crypto_simple(s,idx+1);
                check[num]=false;
            }
        }

        return count;
    }

    //PROGRAM 19
    public static int crypto_subsequences(String s,int idx,int num)
    {
        if(idx==s.length() || num==-1)
        {
            if(num==-1)
            {
                int n1=string_to_number(s1);
                int n2=string_to_number(s2);
                int n3=string_to_number(s3);
    
                if(n1+n2==n3 && map_chartonum[s1.charAt(0)-'a']!=0 && map_chartonum[s2.charAt(0)-'a']!=0 && map_chartonum[s3.charAt(0)-'a']!=0)
                {
                    System.out.println(n1+" + "+n2+" = "+n3);
                    return 1;
                }
            }

            return 0;
        }

        int count=0;

        if(check[num]==false)
        {
            check[num]=true;
            map_chartonum[s.charAt(idx)-'a']=num;
            count+=crypto_subsequences(s,idx+1,9);
            check[num]=false;
        }

        count+=crypto_subsequences(s,idx,num-1);

        return count;
    }

    //SET 3
    public static void crypto()
    {
        //String s0=generate_string();
        //crypto_simple(s0,0);
        //crypto_subsequences(s0,0,9);
    }

    //PROGRAM 20
    static int[][] boards={{1, 0, 0, 0, 0, 7, 0, 6, 0},
                           {6, 0, 0, 0, 3, 4, 0, 0, 0},
                           {0, 0, 0, 0, 8, 0, 1, 0, 9},
                           {8, 6, 0, 0, 0, 0, 3, 0, 0},
                           {0, 4, 0, 0, 0, 0, 0, 2, 0},
                           {0, 0, 1, 0, 0, 0, 0, 4, 5},
                           {2, 0, 8, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 2, 7, 0, 0, 0, 8},
                           {0, 7, 0, 6, 0, 0, 0, 0, 4}};

    public static boolean is_safe_to_place_number(int x,int y,int data)
    {
        for(int i=0;i<9;i++)
        {
            if(boards[i][y]==data)
                return false;
        }

        for(int i=0;i<9;i++)
        {
            if(boards[x][i]==data)
                return false;
        }

        x=(x/3)*3;
        y=(y/3)*3;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(boards[x+i][y+j]==data)
                    return false;
            }
        }

        return true;
    }

    public static int sudoku_solutions(int idx)
    {
        if(idx==boards.length*boards[0].length)
        {
            for(int i=0;i<boards.length;i++)
            {
                for(int j=0;j<boards[0].length;j++)
                {
                    System.out.print(boards[i][j]+" ");
                }
                System.out.println();
            }
            return 1;
        }
    
        int count=0;
        int x=idx/boards[0].length;
        int y=idx%boards[0].length;
    
        if(boards[x][y]==0)
        {
            for(int i=1;i<=9;i++)
            {
                if(is_safe_to_place_number(x,y,i))
                {
                    boards[x][y]=i;
                    count+=sudoku_solutions(idx+1);
                    boards[x][y]=0;
                }
            }
        }
    
        else
            count+=sudoku_solutions(idx+1);
    
        return count;    
    }

    //PROGRAM 21
    public static int sudoku_solutions_lesscalls()
    {
        int count=0;
        return count;
    }

    //PROGRAM 22
    public static int sudoku_solutions_subsequences(int idx,int num)
    {
        if(idx==board.length*board[0].length || num==10)
        {
            if(idx==board.length*board[0].length)
            {
                for(int i=0;i<board.length;i++)
                {
                    for(int j=0;j<board[0].length;j++)
                    {
                        System.out.print(boards[i][j]+" ");
                    }
                    System.out.println();
                }
                return 1;
            }
            return 0;
        }
    
        int count=0;
        int x=idx/board[0].length;
        int y=idx%board[0].length;
    
        if(board[x][y]==0)
        {
            if(is_safe_to_place_number(x,y,num))
            {
                board[x][y]=num;
                count+=sudoku_solutions_subsequences(idx+1,1);
                board[x][y]=0;
            }
        }
    
        else
            count+=sudoku_solutions_subsequences(idx+1,num);
    
        return count;
    }

    //PROGRAM 23
    public static int sudoku_solutions_bitmasking()
    {
        int count=0;
        return count;
    }

    //SET 4
    public static void sudoku()
    {
        //sudoku_solutions(0);
        sudoku_solutions_subsequences(0,1);
    }

    //PROGRAM 24
    static char[][] board= {
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
    
    public static boolean can_place_word_vertical(String word,int r,int c)
    {
        if(r==0 && word.length()!=board.length)
        {
            if(board[r+word.length()][c]!='+')
                return false;
        }
    
        else if(r+word.length()>=board.length && word.length()!=board.length)
        {
            if(board[r-1][c]!='+')
                return false;
        }
    
        else
        {
            if(board[r-1][c]!='+' || board[r+word.length()][c]!='+')
                return false;
        }
    
        for(int i=0;i<word.length();i++)
        {
            if(!(board[r+i][c]=='-' || board[r+i][c]==word.charAt(i)))
                return false;
        }
    
        return true;
    }
    
    public static boolean can_place_word_horizontal(String word,int r,int c)
    {
        if(c==0 && word.length()!=board[0].length)
        {
            if(board[r][c+word.length()]!='+')
                return false;
        }

        else if(c+word.length()>=board[0].length && word.length()!=board[0].length)
        {
            if(board[r][c-1]!='+')
                return false;
        }

        else
        {
            if(board[r][c-1]!='+' || board[r][c+word.length()]!='+')
                return false;
        }

        for(int i=0;i<word.length();i++)
        {
            if(!(board[r][c+i]=='-' || board[r][c+i]==word.charAt(i)))
                return false;
        }

        return true;
    }

    public static boolean[] place_word_vertical(String word,int r,int c)
    {
        boolean[] pos=new boolean[word.length()];

        for(int i=0;i<word.length();i++)
        {
            if(board[r+i][c]=='-')
            {
                board[r+i][c]=word.charAt(i);
                pos[i]=true;
            }
        }

        return pos;
    }

    public static boolean[] place_word_horizontal(String word,int r,int c)
    {
        boolean[] pos=new boolean[word.length()];

        for(int i=0;i<word.length();i++)
        {
            if(board[r][c+i]=='-')
            {
                board[r][c+i]=word.charAt(i);
                pos[i]=true;
            }
        }

        return pos;
    }

    public static void unplace_word_vertical(boolean[] pos,int r,int c)
    {
        for(int i=0;i<pos.length;i++)
        {
            if(pos[i]==true)
                board[r+i][c]='-';
        }
    }

    public static void unplace_word_horizontal(boolean[] pos,int r,int c)
    {
        for(int i=0;i<pos.length;i++)
        {
            if(pos[i]==true)
                board[r][c+i]='-';
        }
    }

    public static int crossword_solutions(String[] words,int idx)
    {
        if(idx==words.length)
        {
            for(int i=0;i<board.length;i++)
            {
                for(int j=0;j<board[0].length;j++)
                {
                    System.out.print(board[i][j]+" ");
                }
                System.out.println();
            }

            return 1;
        }

        int count=0;
        String word=words[idx];

        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board[0].length;j++)
            {
                int c=j;
                int r=i;

                if(can_place_word_vertical(word,r,c))
                {
                    boolean[] pos=place_word_vertical(word,r,c);
                    count+=crossword_solutions(words,idx+1);
                    unplace_word_vertical(pos,r,c);
                }

                if(can_place_word_horizontal(word,r,c))
                {
                    boolean[] pos=place_word_horizontal(word,r,c);
                    count+=crossword_solutions(words,idx+1);
                    unplace_word_horizontal(pos,r,c);
                }
            }
        }

        return count;
    }

    //SET 5
    public static void crossword()
    {
        String[] words={"agra","norway","england","gwalior"};
        crossword_solutions(words,0);
    }

    //MAIN
    public static void main(String[] args)
    {
        //coin_change();
        //nqueen();
        //crypto();
        //sudoku();
        //crossword();
    }
}