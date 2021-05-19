//lecture004
import java.util.Scanner;
public class lecture004
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    //CONVERTING DECIMAL NUMBER TO BINARY
    public static int decimal_to_binary(int n)
    {
        int pow=1;
        int ans=0;

        while(n!=0)
        {
            int res=n%2;
            ans=ans+res*pow;
            n=n/2;
            pow*=10;
        }

        return ans;
    }

    //PROGRAM 2
    //CONVERTING BINARY TO DECIMAL
    public static int binary_to_decimal(int n)
    {
        int ans=0;
        int pow=1;

        while(n!=0)
        {
            int res=n%10;
            ans=ans+res*pow;
            n=n/10;
            pow*=2;
        }

        return ans;
    }

    //PROGRAM 3
    //CONVERTING DECIMAL TO ANY BASE
    public static int decimal_to_any(int n,int base)
    {
        int ans=0;
        int pow=1;

        while(n!=0)
        {
            int res=n%base;
            ans+=res*pow;
            pow*=10;
            n/=base;
        }

        return ans;
    }

    //PROGRAM 4
    //CONVERTING ANY BASE TO DECIMAL
    public static int any_to_decimal(int n,int base)
    {
        int ans=0;
        int pow=1;

        while(n!=0)
        {
            int res=n%10;
            ans+=res*pow;
            pow*=base;
            n/=10;
        }

        return ans; 
    }

    //PROGRAM 5
    //ADDING TWO OCTAL NUMBERS
    public static int octal_addition(int n1,int n2)
    {
        int sum,down,ans=0;
        int carry=0;
        int pow=1;

        while(n1>0 || n2>0 || carry>0)
        {
            sum=n1%10+n2%10+carry;
            carry=sum/8;
            down=sum%8;
            ans=ans+down*pow;
            pow*=10;
            n1/=10;
            n2/=10;
        }

        return ans;
    }

    //PROGRAM 6
    //SUBTRACTING TWO OCTAL NUMBERS
    public static int octal_subtraction(int n1,int n2)
    {
        int a,b;
        int ans=0;
        int pow=1;

        if(n1>n2)
        {
            a=n1;
            b=n2;
        }

        else
        {
            a=n2;
            b=n1;
        }

        while(a!=0 || b!=0)
        {
            int sub=a%10-b%10;
            a/=10;
            b/=10;
            
            if(sub<0)
            {
                sub=sub+8;
                a=a-1;
            }

            ans=ans+sub*pow;
            pow*=10;
        }

        return ans;
    }

    //MAIN
    public static void main(String[] args)
    {
        //System.out.print(decimal_to_binary(2));
        //System.out.print(binary_to_decimal(1000));
        //System.out.print(decimal_to_any(8,2));
        //System.out.print(any_to_decimal(1000,2));
        //System.out.print(octal_addition(265,34));
        //System.out.print(octal_subtraction(265,36));
    }
}