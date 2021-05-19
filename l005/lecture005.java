//lecture005
import java.util.Scanner;

public class lecture005
{
    public static Scanner scn=new Scanner(System.in);

    //PROGRAM 1
    //TAKING INPUT IN AN ARRAY
    public static void input(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            arr[i]=scn.nextInt();
        }
    }

    //DISPLAY ELEMENTS IN AN ARRAY
    public static void display(int[] arr)
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }

    //PROGRAM 2
    public static int find_element(int[] arr,int data)
    {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==data)
            {
                return i;
            }
        }

        return -1;
    }

    //PROGRAM 3
    //FINDING MAXIMUM ELEMENT IN AN ARRAY
    public static int maximum_element(int[] arr)
    {
        int m=Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++)
        {
            m=arr[i]>m?arr[i]:m;
        }

        return m;
    }

    //PROGRAM 4
    //FINDING MINIMUM ELEMENT IN AN ARRAY
    public static int minimum_element(int[] arr)
    {
        int m=Integer.MAX_VALUE;
        for(int i=0;i<arr.length;i++)
        {
            m=arr[i]<m?arr[i]:m;
        }

        return m;
    }

    //PROGRAM 5
    //ROTATING AN ARRAY BY r
    //ROTATE 1 2 3 4 5 BY 2
    //OUTPUT-> 3 4 5 1 2
    public static void reverse_array(int []arr,int start,int end)
    {
        for(int i=start,j=end;i<=j;i++,j--)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    public static void rotate_array(int []arr,int r)
    {
        r=r%arr.length;
        r=r<0?r+arr.length:r;
        reverse_array(arr,0,r-1);
        reverse_array(arr,r,arr.length-1);
        reverse_array(arr,0,arr.length-1);
        display(arr);
    }

    //PROGRAM 6
    //GIVEN AN ARRAY REPRESENTING LINES.FIND TWO LINES WHICH CAN TRAP THE MAXIMUM AMOUNT OF WATER
    public static int maximum_rainwater(int[] arr)
    {
        int i=0;
        int j=arr.length-1;
        int maxwater=0;
        while(i<j)
        {
            if(arr[i]>arr[j])
            {
                maxwater=Math.max((j-i)*arr[j],maxwater);
                j--;
            }
    
            else
            {
                maxwater=Math.max(arr[i]*(j-i),maxwater);
                i++;
            }
        }
    
        return maxwater;
    }


    //PROGRAM 7
    //IMPLEMENTING BINARY SEARCH
    public static int binary_search(int []arr,int data)
    {
        int lwr=0;
        int upr=arr.length-1;

        while(lwr<=upr)
        {
            int mid=(lwr+upr)/2;

            if(arr[mid]<data)
            {
                lwr=mid+1;
            }

            else if(arr[mid]==data)
            {
                return mid;
            }

            else
            {
                upr=mid-1;
            }
        }

        return -1;
    }

    //PROGRAM 8
    //FINDING LOWERBOUND INDEX
    public static int lower_index(int []arr,int data)
    {
        int lwr=0;
        int upr=arr.length-1;

        while(lwr<=upr)
        {
            int mid=(lwr+upr)/2;

            if(arr[mid]<data)
            {
                lwr=mid+1;
            }

            else if(arr[mid]==data)
            {
                if(arr[mid-1]==data)
                {
                    upr=mid-1;
                }

                else
                {
                    return mid;
                }
            }

            else
            {
                upr=mid-1;
            }
        }

        return -1;
    }
    
    //PROGRAM 9
    //FINDING UPPERBOUND INDEX
    public static int upper_index(int []arr,int data)
    {
        int lwr=0;
        int upr=arr.length-1;

        while(lwr<=upr)
        {
            int mid=(lwr+upr)/2;

            if(arr[mid]<data)
            {
                lwr=mid+1;
            }

            else if(arr[mid]==data)
            {
                if(arr[mid+1]==data)
                {
                    lwr=mid+1;;
                }

                else
                {
                    return mid;
                }
            }

            else
            {
                upr=mid-1;
            }
        }

        return -1;
    }

    //PROGRAM 10
    //FINDING ELEMENT WHICH IS CLOSEST TO THE GIVEN DATA
    public static int closest_element(int []arr,int data)
    {
        int lwr=0;
        int upr=arr.length-1;

        if(arr[lwr]>data)
        {
            return arr[lwr];
        }

        if(arr[upr]<data)
        {
            return arr[upr];
        }

        while(lwr<=upr)
        {
            int mid=(lwr+upr)/2;
            if(arr[mid]>data)
            {
                upr=mid-1;
            }
            else if(arr[mid]<data)
            {
                lwr=mid+1;
            }
            else if(arr[mid]==data)
            {
                return mid;
            } 
        }

        if(data-arr[upr]>arr[lwr]-data)
        {
            return arr[lwr];
        }

        else if(data-arr[upr]<=arr[lwr]-data)
        {
            return arr[upr];
        }

        return -1;
    }

    //PROGRAM 11
    //TO FIND TWO NUMBERS WHOSE SUM EQUALS TARGET
    public static void target_sum_doublet(int [] arr,int target)
    {
        int lwr=0;
        int upr=arr.length-1;

        while(lwr<=upr)
        {
            int sum=arr[lwr]+arr[upr];

            if(sum<target)
            {
                lwr+=1;
            }

            else if(sum==target)
            {
                System.out.println("("+arr[lwr]+","+arr[upr]+")");
                lwr+=1;
                upr-=1;
            }

            else
            {
                upr-=1;
            }
        }
    }

    //PROGRAM 12
    //TO FIND THREE NUMBERS WHOSE SUM EQUALS TARGET
    public static void target_sum_triplet(int []arr,int target,int lwr,int upr,int i)
    {
        while(lwr<upr)
        {
            int sum=arr[lwr]+arr[upr];
            if(sum==target)
            {
                System.out.println("("+arr[i]+","+arr[lwr]+","+arr[upr]+")");
                lwr++;
                upr--;
            }

            else if(sum<target)
            {
                lwr++;
            }

            else
            {
                upr--;
            }
        }
    }

    //PROGRAM 13
    //GIVEN A ROW OF SHOES IN PAIRS FIND THE INDEX AND THE SHOE THAT IS MISSING(i.e NOT IN PAIR)
    public static void missing_shoe(int []arr)
    {
        int lwr=0;
        int upr=arr.length-1;

        while(lwr<upr)
        {
            int mid=(lwr+upr)/2;
            
            if(mid%2==0)
            {
                if(arr[mid+1]==arr[mid])
                {
                    lwr=mid+2;
                }

                else
                {
                    upr=mid;
                }
            }

            if(mid%2!=0)
            {
                if(arr[mid-1]==arr[mid])
                {
                    lwr=mid+1;
                }

                else
                {
                    upr=mid-1;
                }
            }
        }

        System.out.print(arr[lwr]+" at index "+lwr);
    }
    
    //PROGRAM 14
    //FIND THE PIVOT POINT IN THE ARRAY
    public static int pivot_point(int[] arr)
    {
        int li=0;
        int ri=arr.length-1;

        while(li<ri)
        {
            int mid=(li+ri)/2;
            boolean leftset=arr[mid]>arr[li]?true:false;
            boolean rightset=arr[mid]<arr[ri]?true:false;

            if((!leftset && rightset) || (!leftset && !rightset))
            {
                ri=mid;
            }

            else if((leftset && !rightset) || (leftset && rightset))
            {
                li=mid;
            }
        }

        return li;
    }

    //MAIN
    public static void main(String[] args)
    {
        int[] arr=new int[9];
        input(arr);
        //display(arr);
        //System.out.print(find_element(arr,0));
        //System.out.print(maximum_element(arr));
        //System.out.print(minimum_element(arr));
        //rotate_array(arr,3);
        //System.out.print(binary_search(arr,11));
        //System.out.print(lower_index(arr,2));
        //System.out.print(upper_index(arr,2));
        //System.out.print(closest_element(arr,6));
        //target_sum_doublet(arr,10);
        /*for(int i=0;i<arr.length;i++)
        {
            target_sum_triplet(arr,10-arr[i],i+1,arr.length-1,i);
        }*/
        //missing_shoe(arr);
    }
}