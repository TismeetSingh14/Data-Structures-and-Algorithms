//lecture007
import java.util.Scanner;

public class lecture007
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    //TO TOGGLE Kth BIT i.e TO SET THE BIT IF UNSET AND VICE VERSA 
    public static int toggle_Kth_bit(int n,int k)
    {
        int mask=(1<<k);
        n=(n^mask);
        return n;
    }

    //PROGRAM 2
    //TO SET THE Kth BIT i.e IF UNSET SET IT ELSE LEAVE IT
    public static int set_Kth_bit(int n,int k)
    {
        int mask=(1<<k);
        n=(n|mask);
        return n;
    }

    //PROGRAM 3
    //TO DETERMINE ODD/EVEN USING BITS
    public static void odd_even(int n)
    {
        if((n&1)==0)
            System.out.println("even");
        
        if((n&1)!=0)
            System.out.println("odd");
    } 

    //PROGRAM 4
    //TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(1st METHOD)
    public static int no_of_set_bits_01(int n)
    {
        int count=0;

        for(int i=0;i<32;i++)
        {
            int mask=(1<<i);

            if((n&mask)!=0)
                count++;
        }

        return count;
    }

    //PROGRAM 5
    //TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(2nd METHOD)
    public static int no_of_set_bits_02(int n)
    {
        int count=0;

        while(n!=0)
        {
            if((n&1)==1)
                count++;

            n>>>=1;    
        }

        return count;
    }

    //PROGRAM 6
    //TO FIND NUMBER OF SET BITS IN THE BINARY REPRESENTATION OF A NUMBER(3rd METHOD)
    public static int no_of_set_bits_03(int n)
    {
        int count=0;
        while(n!=0)
        {
            n&=(n-1);
            count++;
        }

        return count;
    } 

    //PROGRAM 7
    //TO FIND UNIQUE NUMBER IN THE ARRAY i.e THE NUMBER OCCURING ONLY ONCE
    public static int unique_num(int[] arr)
    {
        int ans=0;
        for(int i=0;i<arr.length;i++)
        {
            ans=(ans^arr[i]);
        }

        return ans;
    }

    //PROGRAM 8
    //TO FIND UNIQUE NUMBER IN AN ARRAY WHERE EACH NUMBER IS REPEATED K TIMES
    public static int unique_num_k_times(int[] arr,int k)
    {
        int[] bits=new int[32];

        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<32;j++)
            {
                int mask=(1<<j);

                if((arr[i]&mask)!=0)
                    bits[j]++;
            }
        }

        int ans=0;

        for(int i=0;i<bits.length;i++)
        {
            if(bits[i]%k!=0)
            {
                int mask=(1<<i);
                ans|=mask;
            }
        }

        return ans;
    }

    //MAIN
    public static void main(String[] args)
    {
        //System.out.println(toggle_Kth_bit(2,2));
        //System.out.println(set_Kth_bit(2,3));
        //odd_even(4);
        //System.out.println(no_of_set_bits_01(6));
        //System.out.println(no_of_set_bits_02(-1));
        //System.out.println(no_of_set_bits_03(5));
        int[] arr={1,1,1,2,2,2,3,3,3,4,5,5,5};
        //System.out.println(unique_num(arr));
        //System.out.println(unique_num_k_times(arr,3));
    }
}