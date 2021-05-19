//lecture010
import java.util.Scanner;
import java.util.ArrayList;
public class lecture010
{
    public static Scanner scn=new Scanner(System.in);

    //TOOL PROGRAM
    //HELPER PROGRAM TO DISPLAY VECTORS
    public static void display(ArrayList<String> arrlst)
    {
        for(int i=0;i<arrlst.size();i++)
        {
            System.out.println(arrlst.get(i));
        }
    }

    //PROGRAM 1
    //REMOVES ALL INSTANCES OF "hi" FROM INPUT STRING
    public static String remove_hi(String s)
    {
        if(s.length()==0)
        {
            return "";
        }

        char ch=s.charAt(0);

        if(s.charAt(0)=='h' && s.length()>1 && s.charAt(1)=='i')
        {
            return remove_hi(s.substring(2));
        }

        else
        {
            return ch+remove_hi(s.substring(1));
        }
    }

    //PROGRAM 2
    //REMOVES ALL INSTANCES OF "hi" FROM INPUT STRINGS BUT NOT HIT
    public static String remove_hi_not_hit(String s)
    {
        if(s.length()==0)
        {
            return "";
        }

        char ch=s.charAt(0);

        if(s.length()>1 && s.substring(0,2).equals("hi"))
        {
            if(s.length()>2 && s.substring(0,3).equals("hit"))
            {
                return "hit" +remove_hi_not_hit(s.substring(3));
            }

            else
            {
                return remove_hi_not_hit(s.substring(2));
            }
        }

        else
        {
            return ch+remove_hi_not_hit(s.substring(1));
        }
    }

    //PROGRAM 3
    //REMOVING ALL CONSECUTIVE DUPLICATES FROM THE STRING
    public static String remove_duplicates(String s)
    {
        if(s.length()==1)
        {
            return s;
        }

        char ch=s.charAt(0);

        if(ch==s.charAt(1))
        {
            return remove_duplicates(s.substring(1));
        }

        else
        {
            return ch+ remove_duplicates(s.substring(1));
        }
    }

    //PROGRAM 4
    //RETURNING ALL SUBSEQUENCES(SUBSETS) OF A STRING IN AN ARRAYLIST
    public static ArrayList<String> subsequences(String s)
    {
        if(s.length()==0)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        char ch=s.charAt(0);
        ArrayList<String> ans=subsequences(s.substring(1));
        ArrayList<String> netans=new ArrayList<>();
        //netans.addAll(ans);

        for(String ele:ans)
        {
            netans.add(ele);
        }

        for(String ele:ans)
        {
            netans.add(ch+ele);
        }

        return netans;
    }

    //SET 1
    public static void basic()
    {
        //String s;
        //s=remove_hi("hiihihiihiihi");
        //s=remove_hi_not_hit("hiihihitihiihi");
        //s=remove_duplicates("aaaabbccddeeffggtt");
        //System.out.println(subsequences("abc"));
    }

    //PROGRAM 5
    //RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL MOVES)
    public static ArrayList<String> mazepath_2_directions(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        
        ArrayList<String> ans=new ArrayList<>();
        
        if(sr+1<=er)
        {
            ArrayList<String> vertical=mazepath_2_directions(sr+1,sc,er,ec);
            for(String s:vertical)
            {
                ans.add("v"+s);
            }
        }

        if(sc+1<=ec)
        {
            ArrayList<String> horizontal=mazepath_2_directions(sr,sc+1,er,ec);
            for(String s:horizontal)
            {
                ans.add("h"+s);
            }
        }

        return ans;
    }

    //PROGRAM 6
    //RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL,DIAGONAL MOVES)
    public static ArrayList<String> mazepath_3_directions(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }
        
        ArrayList<String> ans=new ArrayList<>();
        
        if(sr+1<=er)
        {
            ArrayList<String> vertical=mazepath_3_directions(sr+1,sc,er,ec);
            for(String s:vertical)
            {
                ans.add("v"+s);
            }
        }

        if(sc+1<=ec)
        {
            ArrayList<String> horizontal=mazepath_3_directions(sr,sc+1,er,ec);
            for(String s:horizontal)
            {
                ans.add("h"+s);
            }
        }

        if(sc+1<=ec && sr+1<=er)
        {
            ArrayList<String> diagonal=mazepath_3_directions(sr+1,sc+1,er,ec);
            for(String s:diagonal)
            {
                ans.add("d"+s);
            }
        }

        return ans;
    }

    //PROGRAM 7
    //MAX HEIGHT OF RECURSION TREE FORMED IN THE ABOVE QUESTION
    public static int height_of_tree_max_mazepath3dir(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            return 0;
        }

        int horz=0;
        int vert=0;
        int diag=0;

        if(sr+1<=er)
        {
            vert=height_of_tree_max_mazepath3dir(sr+1,sc,er,ec);
        }

        if(sc+1<=ec)
        {
            horz=height_of_tree_max_mazepath3dir(sr,sc+1,er,ec);
        }

        if(sc+1<=ec && sr+1<=er)
        {
            diag=height_of_tree_max_mazepath3dir(sr+1,sc+1,er,ec);
        }

        return Math.max(horz,Math.max(vert,diag))+1;
    }

    //PROGRAM 8
    //RETURNING ALL PATHS BETWEEN TWO POINTS IN A 2D GRID (HORIZONTAL,VERTICAL,DIAGONAL MOVES) WITH MULTI MOVES
    public static ArrayList<String> mazepath_multi_move_3_directions(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        ArrayList<String> ans=new ArrayList<>();

        for(int i=1;i<=ec;i++)
        {
            if(sc+i<=ec)
            {
                ArrayList<String> horizontal=mazepath_multi_move_3_directions(sr,sc+i,er,ec);
                for(String s:horizontal)
                {
                    ans.add("h"+i+s);
                }
            }
        }

        for(int i=1;i<=er;i++)
        {
            if(sr+i<=er)
            {
                ArrayList<String> vertical=mazepath_multi_move_3_directions(sr+i,sc,er,ec);
                for(String s:vertical)
                {
                    ans.add("v"+i+s);
                }
            }
        }

        for(int i=1;i<=Math.min(er,ec);i++)
        {
            if(sr+i<=er && sc+i<=ec)
            {
                ArrayList<String> diagonal=mazepath_multi_move_3_directions(sr+i,sc+i,er,ec);
                for(String s:diagonal)
                {
                    ans.add("d"+i+s);
                }
            }
        }

        return ans;
    }

    //SET 2
    public static void mazepath()
    {
        //System.out.print(mazepath_2_directions(0,0,3,3));
        //System.out.print(mazepath_3_directions(0,0,3,3));
        //System.out.print(height_of_tree_max_mazepath3dir(0,0,3,3));
        //System.out.print(mazepath_multi_move_3_directions(0,0,3,3));
    }

    //PROGRAM 9
    //TO CHECK WHETHER IT IS SAFE TO MAKE THE FUNCTION CALL
    public static boolean is_safe_to_visit(int x,int y,boolean[][] board) 
    {
        if(x>0 && y>0 && x<board.length && y<board[0].length && !board[x][y])
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    //FLOODFILL(MAZEPATH WITH 8 DIRECTION CALL)
    public static ArrayList<String> all_direction_mazepath(int sr,int sc,int er,int ec,boolean[][] board)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        int[][] dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        String[] direc={"D","R","U","L","1","3","4","2"};

        ArrayList<String> netans=new ArrayList<>();
        
        board[sr][sc]=true;
        for(int d=0;d<dir.length;d++)
        {
            int x=sr+dir[d][0];
            int y=sc+dir[d][1];
             
            if(is_safe_to_visit(x,y,board))
            {
                ArrayList<String> ans=all_direction_mazepath(x,y,er,ec,board);
                for(String s:ans)
                {
                    netans.add(direc[d] + s);
                }  
            }
        }

        board[sr][sc]=false;

        return netans;
    }

    //PROGRAM 10
    //TO CHECK WHETHER IT IS SAFE TO MAKE THE FUNCTION CALL
    public static boolean is_safe_for_rat(int x,int y,int er,int ec,boolean[][] board)
    {
        if(x>0 && y>0 && x<=er && y<=ec && !board[x][y])
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    //TO FIND A WAY FOR RAT TO COME OUT OF THE MAZE WITH OBSTACLES
    public static ArrayList<String> rat_in_maze(int sr,int sc,int er,int ec,boolean[][] board)
    {
        if(sr==er && sc==ec)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        int[][] dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        String[] direc={"D","R","U","L","1","3","4","2"};

        ArrayList<String> netans=new ArrayList<>();
        
        board[sr][sc]=true;
        for(int d=0;d<dir.length;d++)
        {
            int x=sr+dir[d][0];
            int y=sc+dir[d][1];
             
            if(is_safe_for_rat(x,y,er,ec,board))
            {
                ArrayList<String> ans=rat_in_maze(x,y,er,ec,board);
                for(String s:ans)
                {
                    netans.add(direc[d] + s);
                }  
            }
        }

        board[sr][sc]=false;

        return netans;
    }

    //SET 3
    public static void floodfill()
    {
        boolean[][] board={{true,false,false,true,false,false},
                           {false,false,true,false,false,true},
                           {false,false,false,false,true,false},
                           {false,true,false,false,true,false},
                           {false,true,false,false,false,false}
                          };  
        //System.out.print(all_direction_mazepath(0,0,3,3,board));
        System.out.print(rat_in_maze(0,1,4,3,board));
    }

    //PROGRAM 11
    //TO RETURN PERMUTATIONS OF A STRING IN AN ARRAYLIST
    public static ArrayList<String> permutation_string(String s)
    {
        if(s.length()==1)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add(s);
            return base;
        }

        char ch=s.charAt(0);
        ArrayList<String> netans=new ArrayList<>();
        ArrayList<String> ans=permutation_string(s.substring(1));

        for(String ele:ans)
        {
            for(int i=0;i<=ele.length();i++)
            {
                netans.add(ele.substring(0,i)+ch+ele.substring(i));
            }
        }

        return netans;
    }

    //PROGRAM 12
    //NOKIA KEYPAD STRING DECODING
    public static ArrayList<String> nokia_keypad(String s)
    {
        if(s.length()==0)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        String[] words={"_","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","&()%","#@$"};
        char ch=s.charAt(0);
        int n=ch-'0';
        String word=words[n];

        ArrayList<String> netans=new ArrayList<>();
        ArrayList<String> ans=nokia_keypad(s.substring(1));
        
        for(String ele:ans)
        {
            for(int i=0;i<word.length();i++)
            {
                netans.add(word.charAt(i)+ele);
            }
        }

        if(s.length()>1 && ch!='0')
        {
            int num=n*10+(s.charAt(1)-'0');
            if(num<12)
            {
                String word1=words[num];
                ArrayList<String> ans1=nokia_keypad(s.substring(2));

                for(String ele:ans1)
                {
                    for(int i=0;i<word1.length();i++)
                    {
                        netans.add(word1.charAt(i)+ele);
                    }
                }
            }
        }

        return netans;
    }

    //PROGRAM 13
    //DECODING STRING MAPPED 1-A 2-B 3-C ....... 25-Y 26-Z
    public static ArrayList<String> mapping(String s)
    {
        if(s.length()==0)
        {
            ArrayList<String> base=new ArrayList<>();
            base.add("");
            return base;
        }

        char ch=s.charAt(0);
        char ch1=(char)('a'+ch-'1');

        if(ch=='0')
        {
            return mapping(s.substring(1));
        }

        ArrayList<String> netans=new ArrayList<>();
        ArrayList<String> ans=mapping(s.substring(1));

        for(String ele:ans)
        {
            netans.add(ch1+ele);
        }

        if(s.length()>1 && ch!='0')
        {
            int num=(ch-'0')*10+s.charAt(1)-'0';
            //int num=Integer.parseInt(s.substring(0,2));

            if(num<27)
            {
                char ch2=(char)('a'+num-1);
                ArrayList<String> ans1=mapping(s.substring(2));

                for(String ele:ans1)
                {
                    netans.add(ch2+ele);
                } 
            }
        }

        return netans;
    }

    //SET 4
    public static void permutation()
    {
        //System.out.print(permutation_string("abc"));
        //System.out.print(nokia_keypad("101"));
        //System.out.print(mapping("123"));
    }

    //MAIN
    public static void main(String[] args)
    {
        //basic();
        //mazepath();
        //floodfill();
        //permutation();
    }
}
