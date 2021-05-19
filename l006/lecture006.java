//lecture006
import java.util.Scanner;

public class lecture006
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    //TO TAKE INPUT IN A 2D ARRAY
    public static void input(int [][]arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
            {
                arr[i][j]=scn.nextInt();
            }
        }
    }
    
    //TO DISPLAY A 2D ARRAY
    public static void display(int [][]arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            for(int j=0;j<arr[i].length;j++)
            {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }

    //PROGRAM 2
    //TO PRINT A 2D ARRAY IN A HORIZONTAL WAVE FASHION
    public static void wave_print_horizontal(int [][]arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<arr[i].length;j++)
                {
                    
                    System.out.print(arr[i][j]+" ");
                }
            }

            else
            {
                for(int j=arr[i].length-1;j>=0;j--)
                {
                    
                    System.out.print(arr[i][j]+" ");
                }
            }
        }
    }

    //PROGRAM 3
    //TO PRINT A 2D ARRAY IN A VERTICAL WAVE FASHION
    public static void wave_print_vertical(int [][]arr)
    {
        for(int i=0;i<arr[0].length;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<arr.length;j++)
                {
                    
                    System.out.print(arr[j][i]+" ");
                }
            }

            else
            {
                for(int j=arr.length-1;j>=0;j--)
                {
                    
                    System.out.print(arr[j][i]+" ");
                }
            }
        }
    }

    //PROGRAM 4
    //TO PRINT A 2D ARRAY BY MOVING IN A SPIRAL FASHION
    public static void spiral_print(int [][]arr)
    {
        int tne=arr.length*arr[0].length;
        int minr=0;
        int maxr=arr.length-1;
        int minc=0;
        int maxc=arr[0].length-1;

        while(tne>0)
        {
            for(int i=minc;i<=maxc && tne>0;i++)
            {
                System.out.print(arr[minr][i]+" ");
                tne--;
            }
            minr++;

            for(int i=minr;i<=maxr && tne>0;i++)
            {
                System.out.print(arr[i][maxc]+" ");
                tne--;
            }
            maxc--;

            for(int i=maxc;i>=minc && tne>0;i--)
            {
                System.out.print(arr[maxr][i]+" ");
                tne--;
            }
            maxr--;

            for(int i=maxr;i>=minr && tne>0;i--)
            {
                System.out.print(arr[i][minc]+" ");
                tne--;
            }
            minc++;
        }
    }

    //PROGRAM 5
    /*TO FIND THE EXITPOINT IN A MATRIX FILLED WITH 0s AND 1s
    WHENEVER YOU ENCOUNTER A 1 YOU HAVE TO TAKE A RIGHT TURN*/
    public static void exit_point(int [][]arr)
    {
        int dir=0;
        int r=0;
        int c=0;

        while(true)
        {
            dir=(dir+arr[r][c])%4;

            if(dir==0)
            {
                c++;
                if(c==arr[0].length)
                {
                    System.out.print("("+(r)+","+(c-1)+")");
                    break;
                }
            }

            if(dir==1)
            {
                r++;
                if(r==arr.length)
                {
                    System.out.print("("+(r-1)+","+(c)+")");
                    break;
                }
            }

            if(dir==2)
            {
                c--;
                if(c==-1)
                {
                    System.out.print("("+(r)+","+(c+1)+")");
                    break;
                }
            }

            if(dir==3)
            {
                r--;
                if(r==-1)
                {
                    System.out.print("("+(r+1)+","+(c)+")");
                    break;
                }
            }
        }
    }

    //PROGRAM 6
    //TO DETERMINE TRANSPOSE OF A MATRIX
    public static void transpose(int[][] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            for(int j=i;j<arr[0].length;j++)
            {
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }

    //TO SWAP ROWS OF A 2D MATRIX
    public static void swap_rows(int [][]arr)
    {
        int c1=0;
        int c2=arr[0].length-1;
        while(c1<c2)
        {
            for (int r=0;r<arr.length;r++)
            {
                int temp=arr[r][c1];
                arr[r][c1]=arr[r][c2];
                arr[r][c2]=temp;
            }
            c1++;
            c2--;
        }
    }

    //TO SWAP COLUMNS OF A 2D MATRIX
    public static void swap_columns(int [][]arr)
    {
        int r1=0;
        int r2=arr.length-1;
        while(r1<r2)
        {
            for(int c=0;c<arr[0].length;c++)
            {
                int temp=arr[r1][c];
                arr[r1][c]=arr[r2][c];
                arr[r2][c]=temp;
            }
            r1++;
            r2--;
        }
    }

    //TO ROTATE A MATRIX 90 DEGREES IN CLOCKWISE AND ANTICLOCKWISE DIRECTIONS
    public static void rotate_by_90_degrees(int [][] arr,boolean isCW)
    {
        transpose(arr);
        if(isCW==true)
        {
            swap_rows(arr);
        }

        else
        {
            swap_columns(arr);
        }

        display(arr);
    }

    //MAIN
    public static void main(String[] args)
    {
        //int[][] arr=new int[3][3];
        //input(arr);
        //display(arr);
        //wave_print_horizontal(arr);
        //wave_print_vertical(arr);
        //spiral_print(arr);
        //exit_point(arr);
        //rotate_by_90_degrees(arr,false);
    }
}