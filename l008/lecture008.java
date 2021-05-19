//lecture008
import java.util.Scanner;
public class lecture008
{
    public static Scanner scn=new Scanner(System.in);
    
    //PROGRAM 1
    //BASIC RECURSION TO PRINT NUMBERS TILL N IN INCREASING ORDER
    public static void increasing_order(int n)
    {
        if(n==0)
        {
            return;
        }

        increasing_order(n-1);
        System.out.println(n);
    }

    //PROGRAM 2
    //BASIC RECURSION TO PRINT NUMBERS UPTO N IN DECREASING ORDER
    public static void decreasing_order(int n)
    {
        if(n==0)
        {
            return;
        }

        System.out.println(n);
        decreasing_order(n-1);
    }

    //PORGRAM 3
    //TO PRINT FIRST N/2 EVEN NUMBERS AND THEN N/2 ODD NUMBERS USING RECURSION
    public static void odd_even(int n)
    {
        if(n==0)
        {
            System.out.println(0);
            return;
        }

        if(n%2==0)
        {
            System.out.println(n);
        }

        odd_even(n-1);

        if(n%2!=0)
        {
            System.out.println(n);
        }
    }

    //PROGRAM 4
    //TO FIND FACTORIAL OF A NUMBER USING RECURSION
    public static int factorial(int n)
    {
        if(n==0)
        {
            return 1;
        }

        return factorial(n-1)*n;
    }

    //PROGRAM 5
    //TO FIND Nth FIBONACCI NUMBER USING RECURSION
    public static int fibonacci(int n)
    {
        if(n==0)
        {
            return 0;
        }

        if(n==1)
        {
            return 1;
        }

        return fibonacci(n-2)+fibonacci(n-1);
    }

    //PROGRAM 6
    //TO FIND A RAISED TO THE POWER B O(n) METHOD
    public static int power(int a,int b)
    {
        if(b==0)
        {
            return 1;
        }

        return a*power(a,b-1);
    }

    //PROGRAM 7
    //TO FIND A RAISED TO THE POWER B O(log(n)) METHOD
    public static int power_better(int a,int b)
    {
        if(b==0)
        {
            return 1;
        }

        int ans=power(a,b/2)*power(a,b/2);
        return ans=b%2>0?ans*a:ans;
    }

    //MAIN
    public static void main(String args[])
    {
        //increasing_order(8);
        //decreasing_order(8);
        //odd_even(8);
        //System.out.println(factorial(4));
        //System.out.println(fibonacci(4));
        //System.out.println(power(2,3));
        //System.out.println(power_better(2,3));
    }
} 