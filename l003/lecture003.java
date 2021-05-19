//lecture003
import java.util.*;
public class lecture003
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    /*
    TO PRINT THE PATTERN
            *
           ** 
          *** 
         **** 
        ***** 
    */
    public static void mirror_triangle(int rows)
    {
        int nst=1;
        int nsp=rows-1;

        for(int i=1;i<=rows;i++)
        {
            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }

            for(int cst=1;cst<=nst;cst++)
            {
                System.out.print("*");
            }

            System.out.println();
            nst++;
            nsp--;
        }
    }

    //PROGRAM 2
    /*
    TO PRINT THE PATTERN
        *
        ** 
        *** 
        **** 
        ***** 
    */
    public static void triangle(int rows)
    {
        int nst=1;
        int nsp=0;

        for(int i=1;i<=rows;i++)
        {
            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }

            for(int cst=1;cst<=nst;cst++)
            {
                System.out.print("*");
            }

            System.out.println();
            nst++;
            nsp--;
        }
    }

    //PROGRAM 3
    /*
    TO PRINT THE PATTERN
            *
           *** 
          *****    
         ******* 
        ********* 
    */
    public static void pyramid(int rows)
    {
        int nst=1;
        int nsp=rows-1;

        for(int i=1;i<=rows;i++)
        {
            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }

            for(int cst=1;cst<=nst;cst++)
            {
                System.out.print("*");
            }

            System.out.println();
            nst+=2;
            nsp--;
        }
    }

    //PROGRAM 4
    /*
    TO PRINT THE PATTERN
            *
           *** 
          *****    
         ******* 
        ********* 
         *******
          *****
           ***
            *     
    */
    public static void star_diamond(int rows)
    {
        int nst=1;
        int nsp=rows-1;

        for(int i=1;i<=rows;i++)
        {
            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }

            for(int cst=1;cst<=nst;cst++)
            {
                System.out.print("*");
            }

            System.out.println();

            if(i<(rows+1)/2)
            {
                nst+=2;
                nsp--;
            }

            else
            {
                nst-=2;
                nsp++;
            }
        }
    }

    //PROGRAM 5
    /*
    TO PRINT THE PATTERN
            1   
           232
          34543
         4567654
        567898765
         4567654
          34543
           232
            1    
    */
    public static void diamond(int rows)
    {
        int nst=1;
        int nsp=rows-1;
        int val;

        for(int i=1;i<=rows;i++)
        {
            if(i<(rows+1)/2)
            {
                val=i;
            }

            else
            {
                val=rows-i+1;
            }

            for(int csp=1;csp<=nsp;csp++)
            {
                System.out.print(" ");
            }

            for(int cst=1;cst<=nst;cst++)
            {
                System.out.print(val);
                
                if(cst>=(nst+1)/2)
                {
                    val--;
                }

                else
                {
                    val++;
                }
            }

            System.out.println();

            if(i<(rows+1)/2)
            {
                nst+=2;
                nsp--;
            }

            else
            {
                nst-=2;
                nsp++;
            }
        }
    }

    //PROGRAM 6
    /*
    TO PRINT THE PATTERN
        0 1 1 2 3 5 8 13 21
    */
    public static void fibonacci(int n)
    {
        int a=0;
        int b=1;
        int c=a+b;
        System.out.print(a+" "+b+" ");

        for(int i=0;i<n-2;i++)
        {
            c=a+b;
            System.out.print(c+" ");
            a=b;
            b=c;
        }
    }

    //PROGRAM 7
    /*
    TO PRINT THE PATTERN
            1
          1  1
        1  2  1
      1  3  3  1
    1  4  6  4  1    
    */
    public static void pascal_triangle(int rows)
    {
        int nst=1;
        int nsp=rows-1;

        for(int r=0;r<rows;r++)
        {
            for(int csp=0;csp<nsp;csp++)
            {
                System.out.print(" ");
            }

            int val=1;
            for(int cst=0;cst<nst;cst++)
            {
                System.out.print(val+" ");
                val=(val*(r-cst))/(cst+1);
            }

            System.out.println();
            nst++;
            nsp--;
        }
    }

    //MAIN
    public static void main(String[] args)
    {
        //mirror_triangle(5);
        //triangle(5);
        //pyramid(5);
        //star_diamond(9);
        //diamond(7);
        //fibonacci(5);
        //pascal_triangle(5);
    }
}