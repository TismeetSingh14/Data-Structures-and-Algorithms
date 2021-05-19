//lecture009
import java.util.ArrayList;
import java.util.Scanner;

public class lecture009
{
    public static Scanner scn=new Scanner(System.in);
    
    //PROGRAM 1
    //TO TAKE INPUT IN AN ARRAY USING RECURSION
    public static void input(int[] arr,int i)
    {
        if(i==arr.length)
        {
            return; 
        }

        arr[i]=scn.nextInt();
        input(arr,i+1);
    }

    //TO DISPLAY ELEMENTS IN AN ARRAY USING RECURSION
    public static void display(int[] arr,int i)
    {
        if(i==arr.length)
        {
            return; 
        }

        System.out.print(arr[i]+" ");
        display(arr,i+1);
    }

    //PROGRAM 2
    //TO FIND MAXIMUM ELEMENT IN AN ARRAY USING RECURSION
    public static int maximum_element(int[] arr,int i)
    {
        if(i==arr.length)
        {
            return Integer.MIN_VALUE;
        }

        int recans=maximum_element(arr,i+1);
        return recans=recans>arr[i]?recans:arr[i];
    }

    //PROGRAM 3
    //TO FIND MINIMUM ELEMENT IN ARRAY USING RECURSION
    public static int minimum_element(int[] arr,int i)
    {
        if(i==arr.length)
        {
            return Integer.MAX_VALUE;
        }

        int recans=minimum_element(arr,i+1);
        return recans=recans<arr[i]?recans:arr[i];
    }

    //PROGRAM 4
    //TO FIND INDEX OF ELEMENT IN AN ARRAY USING RECURSION
    public static int find_element(int [] arr,int i,int data)
    {
        if(i==arr.length)
        {
            return -1;
        }

        if(arr[i]==data)
        {
            return i;
        }

        return find_element(arr,i+1,data);
    }

    //PROGRAM 5
    //TO RETURN ARRAYLIST CONTAINING ALL THE INDICES OF A GIVEN ELEMENT IN AN ARRAY
    public static ArrayList<Integer> all_index(int[] arr,int i,int data,int count)
    {
        if(i==arr.length)
        {
            ArrayList<Integer> base=new ArrayList<Integer>(count);
            return base;
        }

        if(arr[i]==data)
        {
            count++;
        }

        ArrayList<Integer> arrli=new ArrayList<Integer>(count);
        arrli=all_index(arr,i+1,data,count);

        if(arr[i]==data) 
        {
            arrli.set(count-1,i);
        }

        return arrli;
    }

    //PROGRAM 6
    //TO FIND THE INVERSE OF AN ARRAY
    public static void inverse(int [] arr,int i)
    {
        if(i==arr.length)
        {
            return;
        }

        int val=arr[i];
        inverse(arr,i+1);
        arr[val]=i;
    }

    //MAIN 
    public static void main(String[] args)
    {
        int[] arr=new int[5];
        input(arr,0);
        //display(arr,0);
        //System.out.println(maximum_element(arr,0));
        //System.out.println(minimum_element(arr,0));
        //System.out.println(find_element(arr,0,5));
        /*ArrayList<Integer> arrlst=new ArrayList<Integer>();
        arrlst=all_index(arr,0,5,0);
        for(int i=0;i<arrlst.size();i++)
        {
            System.out.print(arrlst.get(i)+" ");
        }*/
        //inverse(arr,0);
        //display(arr,0);
    }
}