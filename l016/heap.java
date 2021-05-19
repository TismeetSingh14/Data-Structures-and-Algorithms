import java.util.ArrayList;
public class heap
{
    ArrayList<Integer> arr=new ArrayList<>();
    private boolean ismax=false;
    public heap()
    {
        this.arr=new ArrayList<>();
    }

    public heap(boolean ismax)
    {
        this.arr=new ArrayList<>();
        this.ismax=ismax;
    }

    public void create_heap(int[] ar)
    {
        this.arr=new ArrayList<>();
        for(int ele:ar)
        {
            this.arr.add(ele);
        }

        for(int i=arr.size()-1;i>=0;i--)
        {
            down_heapify(i);
        }
    }

    public heap(int[] ar)
    {
        create_heap(ar);
    }

    public heap(int[] ar,boolean ismax)
    {
        this.ismax=ismax;
        create_heap(ar);
    }

    //======================================API

    public int top()
    {
        return arr.get(0);
    }

    public void push(int ele)
    {
        arr.add(ele);
        up_heapify(arr.size()-1);
    }

    public void pop(int idx)
    {
        swap(0,arr.size()-1);
        arr.remove(arr.size()-1);
        down_heapify(0);
    }

    public int size()
    {
        return arr.size();
    }

    public boolean isempty()
    {
        if(arr.size()==0)
            return true;

        return false;    
    }

    public void update(int prev_ele,int ele)
    {
        int idx=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr.get(i)==prev_ele)
            {
                idx=i;
                break;
            }
        }

        if(idx==-1)
            return;

        arr.set(idx,ele);    

        /*int lcidx=2*idx+1;
        int rcidx=2*idx+2;
        int pidx=(idx-1)/2;

        if(arr.get(idx)<arr.get(lcidx) || arr.get(idx)<arr.get(rcidx))
            down_heapify(idx);;

        if(arr.get(idx)>arr.get(pidx))
            up_heapify(idx);*/

        up_heapify(idx);
        down_heapify(idx);    
    }

    //==========================================================util

    public void swap(int idx1,int idx2)
    {
        int val1=arr.get(idx1);
        int val2=arr.get(idx2);

        arr.set(idx1,val2);
        arr.set(idx2,val1);
    }

    public int compare_to(int chd,int par)
    {
        if(ismax)
        {
            return arr.get(chd)-arr.get(par);
        }

        else
        {
            return arr.get(par)-arr.get(chd);
        }
    }

    public void up_heapify(int cidx)
    {
        int pidx=(cidx-1)/2;

        if(pidx>=0 && compare_to(cidx,pidx)>0)
        {
            swap(cidx,pidx);
            up_heapify(pidx);
        }
    }

    public void down_heapify(int idx)
    {
        int max_idx=idx;
        int lci=2*idx+1;
        int rci=2*idx+2;
        
        if(lci<arr.size() && compare_to(lci,max_idx)>0)
        {
            max_idx=lci;
        }

        if(rci<arr.size() && compare_to(rci,max_idx)>0)
        {
            max_idx=rci;
        }

        if(max_idx!=idx)
        {
            swap(max_idx,idx);
            down_heapify(max_idx);
        }
    }
}