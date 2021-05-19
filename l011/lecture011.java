//lecture011
import java.util.Scanner;
public class lecture011
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    //TO PRINT ALL SUBSEQUENCES OF A STRING
    public static int subsequences(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        char ch=s.charAt(0);

        count+=subsequences(s.substring(1),ans+ch);
        count+=subsequences(s.substring(1),ans);

        return count;
    } 

    //PROGRAM 2
    //TO PRINT ALL SUBSEQUENCES OF A STRING WITH THEIR ASCII VALUES
    public static int ascii_subsequences(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        char ch=s.charAt(0);
        int n=(int)(ch);

        count+=ascii_subsequences(s.substring(1),ans+ch);
        count+=ascii_subsequences(s.substring(1),ans);
        count+=ascii_subsequences(s.substring(1),ans+n);

        return count;
    } 

    //SET 1
    public static void basic()
    {
        //System.out.println(subsequences("abc",""));
        //System.out.println(ascii_subsequences("abc",""));
    } 

    //PROGRAM 3
    //TO PRINT ALL PERMUTATIONS OF A STRING
    public static int permutation_with_repitition(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            count+=permutation_with_repitition(s.substring(0,i)+s.substring(i+1),ans+ch);
        }

        return count;
    }

    //PROGRAM 4
    //TO PRINT ALL PERMUTATIONS OF A STRING WITH NO REPITITION
    public static int permutation_without_repitition(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        
        int [] arr=new int[]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        int count=0;

        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);

            if(arr[ch-'a']==0)
            {
                arr[ch-'a']=1;
                count+=permutation_without_repitition(s.substring(0,i)+s.substring(i+1),ans+ch);
            }
        }

        return count;
    }

    //PROGRAM 5
    //TO PRINT ALL PERMUTATIONS OF A STRING WITH NO REPITITION (WITH BITMASKING)
    public static int permutation_without_repitition_bit_masking(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        int num=0;

        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            int mask=1<<(ch-'a');
            
            if((num & mask)==0)
            {
                num=(num|mask);
                count+=permutation_without_repitition(s.substring(0,i)+s.substring(i+1),ans+ch);
            }
        }

        return count;
    }

    //PROGRAM 6
    //NOKIA KEYPAD STRING DECODING VOID TYPE
    public static int nokia_keypad(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        String[] words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#"};
        char ch=s.charAt(0);
        String word=words[ch-'0'];

        for(int i=0;i<word.length();i++)
        {
            count+=nokia_keypad(s.substring(1),ans+word.charAt(i));
        }

        if(s.length()>1 && ch!='0')
        {
            int num=(ch-'0')*10 + s.charAt(1)-'0';
            String word1=words[num];

            if(num<12)
            {
                for(int i=0;i<word1.length();i++)
                {
                    count+=nokia_keypad(s.substring(2),ans+word1.charAt(i));
                }
            }
        }

        return count;
    }

    //PROGRAM 7
    //DECODING STRING WITH MAPPING A-1 B-2 C-3 ..... Y-25 Z-26
    public static int mapping(String s,String ans)
    {
        if(s.length()==0)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;
        int n1=s.charAt(0)-'0';
        
        if(n1==0)
            return mapping(s.substring(1),ans);

        char ch1=(char)(n1-1+'a');
        count+=mapping(s.substring(1),ans+ch1);

        if(s.length()>1 && s.charAt(0)!='0')
        {
            int n2=n1*10 + (s.charAt(1)-'0');
            
            if(n2<27)
            {
                char ch2=(char)(n2-1+'a');
                count+=mapping(s.substring(2),ans+ch2);
            }
        }

        return count;
    }

    //SET 2
    public static void permutation()
    {
        //System.out.println(permutation_with_repitition("123",""));
        //System.out.println(permutation_without_repitition("aaa",""));
        //System.out.println(permutation_without_repitition_bit_masking("aba",""));
        //System.out.println(nokia_keypad("101",""));
        //System.out.println(mapping("14",""));
    }

    //PROGRAM 8
    //TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL AND VERTICAL)
    public static int mazepath_2_direction(int sr,int sc,int er,int ec,String ans)
    {
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        if(sc+1<=ec)
        {
            count+=mazepath_2_direction(sr,sc+1,er,ec,ans+"h");
        }

        if(sr+1<=er)
        {
            count+=mazepath_2_direction(sr+1,sc,er,ec,ans+"v");
        }

        return count;
    }

    //PROGRAM 9
    //TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL, DIAGONAL AND VERTICAL)
    public static int mazepath_3_direction(int sr,int sc,int er,int ec,String ans)
    {
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        if(sc+1<=ec)
        {
            count+=mazepath_3_direction(sr,sc+1,er,ec,ans+"h");
        }

        if(sr+1<=er)
        {
            count+=mazepath_3_direction(sr+1,sc,er,ec,ans+"v");
        }

        if(sr+1<=er && sc+1<=ec)
        {
            count+=mazepath_3_direction(sr+1,sc+1,er,ec,ans+"d");
        }

        return count;
    }

    //PROGRAM 10
    //TO PRINT ALL PATHS FROM SOURCE TO DESTINATION(HORIZONTAL, DIAGONAL AND VERTICAL) MULTI MOVE
    public static int mazepath_3_direction_multimove(int sr,int sc,int er,int ec,String ans)
    {
        if(sr==er && sc==ec)
        {
            System.out.println(ans);
            return 1;
        }

        int count=0;

        for(int i=1;i<=ec;i++)
        {
            if(sc+i<=ec)
            {
                count+=mazepath_3_direction_multimove(sr,sc+i,er,ec,ans+"h"+i);
            }
        }

        for(int i=1;i<=er;i++)
        {
            if(sr+i<=er)
            {
                count+=mazepath_3_direction_multimove(sr+i,sc,er,ec,ans+"v"+i);
            }
        }

        for(int i=1;i<=Math.min(er,ec)+1;i++)
        {
            if(sc+i<=ec && sr+i<=er)
            {
                count+=mazepath_3_direction_multimove(sr+i,sc+i,er,ec,ans+"d"+i);
            }
        }

        return count;
    }

    //SET 3
    public static void mazepath()
    {
        //System.out.println(mazepath_2_direction(0,0,2,2,""));
        //System.out.println(mazepath_3_direction(0,0,2,2,""));
        //System.out.println(mazepath_3_direction_multimove(0,0,2,2,""));
    }

    //PROGRAM 11
    //TO PRINT ALL SUBSETS OF A SET THAT SUM UP TO THE TARGET
    public static int target_sum_allset(int[] arr,int target,int idx,String ans)
    {
        if(idx==arr.length || target==0)
        {   
            if(target==0)
            {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count=0;

        for(int i=idx;i<arr.length;i++)
        {
            if(target-arr[i]>=0)
            {
                count+=target_sum_allset(arr,target-arr[i],i+1,ans+arr[i]+" ");
            }
        }
        return count;
    }

    //PROGRAM 12
    //TO PRINT ALL SUBSETS OF A SET THAT SUM UP TO THE TARGET USING SUBSEQUENCES APPROACH
    public static int target_sum_allset_subsequences(int[] arr,int target,int idx,String ans)
    {
        if(idx==arr.length || target==0)
        {
            if(target==0)
            {
                System.out.println(ans);
                return 1;
            }
            return 0;
        }

        int count=0;

        if(target-arr[idx]>=0)
        {
            count+=target_sum_allset_subsequences(arr,target-arr[idx],idx+1,ans+arr[idx]+" ");
        }

        count+=target_sum_allset_subsequences(arr,target,idx+1,ans);

        return count;
    }

    //PROGRAM 13
    /*TO DIVIDE A SET INTO TWO SETS SUCH THAT THEIR SUM IS EQUAL,
    THEIR INTERSECTION IS A NULL SET AND THEIR UNION IS THE SET ITSELF*/
    public static int equiset(int[] arr,int idx,int set1,int set2,String ans1,String ans2)
    {
        if(arr.length==idx)
        {
            if(set1==set2)
            {
                System.out.println(ans1+"="+ans2);
                return 1;
            }
            return 0;
        }

        int count=0;

        count+=equiset(arr,idx+1,set1+arr[idx],set2,ans1+arr[idx]+" ",ans2);
        count+=equiset(arr,idx+1,set1,set2+arr[idx],ans1,ans2+arr[idx]+" ");

        return count;
    }

    //SET 4
    public static void sets()
    {
        //int[] arr={1,3,5,7,0};
        //System.out.println(target_sum_allset(arr,6,0,""));
        //System.out.println(target_sum_allset_subsequences(arr,100,0,""));
        //System.out.println(equiset(arr,1,10,0,"10 ",""));
    }

    //MAIN
    public static void main(String[] args)
    {
        //basic();
        //permutation();
        //mazepath();
        //sets();
    }
}