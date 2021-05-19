//lecture014
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Stack;
public class lecture014
{
    public static Scanner scn=new Scanner(System.in);
    
    public static class Tree
    {
        int data=0;
        Tree left=null;
        Tree right=null;

        public Tree()
        {

        }

        public Tree(int data)
        {
            this.data=data;
        }

        public Tree(int data,Tree left,Tree right)
        {
            this.data=data;
            this.left=left;
            this.right=right;
        }

        @Override
        public String toString()
        {
            String str="";
            str+=left!=null?left.data:".";
            str+=("->"+data+"<-");
            str+=(right!=null?right.data:".");
            str+="\n";

            if(left!=null)
            {
                str+=left.toString();
            }

            if(right!=null)
            {
                str+=right.toString();
            }

            return str;
        }
    }

    //PROGRAM 1
    static int idx=0;
    public static Tree tree_creation(int[] arr)
    {
        if(idx==arr.length || arr[idx]==-1)
        {
            if(arr[idx]==-1)
                idx++;

            return null;    
        }

        Tree node=new Tree(arr[idx]);
        idx++;    

        node.left=tree_creation(arr);
        node.right=tree_creation(arr);

        return node;
    }

    //PROGRAM 2
    public static void display_tree(Tree node)
    {
        if(node==null)
            return;

        System.out.print(node.left!=null?node.left.data:".");
        System.out.print("->"+node.data+"<-");
        System.out.println(node.right!=null?node.right.data:".");
        
        display_tree(node.left);
        display_tree(node.right);
    }

    //PROGRAM 3
    public static int size(Tree node)
    {
        if(node==null)
        {
            return 0;
        }

        int ls=size(node.left);
        int rs=size(node.right);

        return ls+rs+1;
    }

    //PROGRAM 4
    public static int max_height(Tree node)
    {
        if(node==null)
        {
            return -1;
        }

        int lh=max_height(node.left);
        int rh=max_height(node.right);

        return Math.max(lh,rh)+1;
    }

    //PROGRAM 5
    public static int min_height(Tree node)
    {
        if(node==null)
            return 0;

        if(node.right==null)
            return min_height(node.left)+1;
            
        if(node.left==null)
            return min_height(node.right)+1;
            
        return Math.min(min_height(node.right),min_height(node.left))+1;    
    }

    //PROGRAM 6
    public static boolean find(Tree node,int data)
    {
        if(node==null)
        {
            return false;
        }
        
        if(node.data==data)
            return true;

        boolean ans=false;    
        ans=ans||find(node.left,data);
        ans=ans||find(node.right,data);

        return ans;
    }

    //PROGRAM 7
    public static ArrayList<Tree> root_to_node_path(Tree node,int data)
    {
        if(node==null)
        {
            ArrayList<Tree> base=new ArrayList<>();
            return base;
        }

        if(node.data==data)
        {
            ArrayList<Tree> base=new ArrayList<>();
            base.add(node);
            return base;
        }

        ArrayList<Tree> left=root_to_node_path(node.left,data);
        if(left.size()!=0)
        {
            left.add(node);
            return left;
        }
        
        ArrayList<Tree> right=root_to_node_path(node.right,data);
        if(right.size()!=0)
        {
            right.add(node);
            return right;
        }

        return new ArrayList<>();   
    }

    public static int lowest_common_ancestor(Tree node,int data1,int data2)
    {
        ArrayList<Tree> list1=root_to_node_path(node,data1);
        ArrayList<Tree> list2=root_to_node_path(node,data2);

        int ans=-1;
        int i=list1.size()-1;
        int j=list2.size()-1;

        while(i>=0 && j>=0)
        {
            if(list1.get(i)!=list2.get(j))
                break;

            ans=list1.get(i).data;
            i--;
            j--;    
        }

        return ans;
    }

    //PROGRAM 8
    public static void k_down(Tree node,Tree prev_node,int k)
    {
        if(node==null)
            return;

        if(prev_node!=null && prev_node==node)
            return;    

        if(k==0)
            System.out.print(node.data+" ");
        
        k_down(node.left,prev_node,k-1);             
        k_down(node.right,prev_node,k-1);   
    }

    public static void k_distance_nodes(Tree node,int k,int data)
    {
        ArrayList<Tree> arli=root_to_node_path(node,data);
        Tree prev_node=null;

        for(int i=0;i<arli.size();i++)
        {
            k_down(arli.get(i),prev_node,k-i);
            prev_node=arli.get(i);
        }
    }

    //PROGRAM 9
    public static int k_distance_nodes_better(Tree node,int k,int data)
    {
        if(node==null)
            return -1;

        if(node.data==data)
        {
            k_down(node,null,k);
            return 1; 
        }   

        int ld=k_distance_nodes_better(node.left,k,data);
        if(ld!=-1)
        {
            k_down(node.right,node.left,k-ld);
            return ld+1;
        } 

        int rd=k_distance_nodes_better(node.right,k,data);

        if(rd!=-1)
        {
            k_down(node.left,node.right,k-rd);
            return rd+1;
        }

        return -1;
    }

    //PROGRAM 10
    public static void level_order_traversal(Tree node)
    {
        int k=max_height(node);
        Tree pnode=null;

        for(int i=0;i<k;i++)
        {
            k_down(node.left,pnode,i);
            k_down(node.right,pnode,i);
        }
    }

    //PROGRAM 11
    public static int diameter_01(Tree node)
    {
        if(node==null)
            return 0;
        
        int ldia=diameter_01(node.left);
        int rdia=diameter_01(node.right);

        int lh=max_height(node.left);
        int rh=max_height(node.right);
        
        return Math.max(Math.max(ldia,rdia),lh+rh+2);
    }

    //PROGRAM 12
    public static int[] diameter_02(Tree node)
    {
        if(node==null)
            return new int[] {0,-1};
            
        int[] ld=diameter_02(node.left); 
        int[] rd=diameter_02(node.right);
        
        int[] myans=new int[2];
        myans[0]=Math.max(Math.max(ld[0],rd[0]),ld[1]+rd[1]+2);
        myans[1]=Math.max(ld[1],rd[1])+1;

        return myans;
    }

    //PROGRAM 12
    static int maxsum=Integer.MIN_VALUE;
    public static int max_sum_path_leaf_to_leaf(Tree node)
    {
        if(node==null)
            return Integer.MIN_VALUE;

        if(node.right==null && node.left==null)
            return node.data;

        int lfsum=max_sum_path_leaf_to_leaf(node.left);
        int rgsum=max_sum_path_leaf_to_leaf(node.right);

        if(node.left!=null && node.right!=null)
        maxsum=Math.max(lfsum+rgsum+node.data,maxsum);

        return Math.max(lfsum,rgsum)+node.data;
    }

    //PROGRAM 13
    static int maxsum1=Integer.MIN_VALUE;
    public static int max_sum_path_node_to_node(Tree node)
    {
        if(node==null)
            return 0;
            
        int lfsum=max_sum_path_node_to_node(node.left);
        int rgsum=max_sum_path_node_to_node(node.right);
        int maxbranch=Math.max(lfsum,rgsum);

        maxsum1=Math.max(Math.max(maxsum1,maxbranch+node.data),Math.max(lfsum+rgsum+node.data,node.data));
        
        return Math.max(maxbranch+node.data,node.data);
    }

    //PROGRAM 14
    // -1   i want a camera
    //  0   i am covered
    //  1   i am a camera
    static int cameras=0;
    public static int min_cameras(Tree node)
    {
        if(node==null)
            return 0;

        int lc=min_cameras(node.left);
        int rc=min_cameras(node.right);  
        
        if(lc==-1 || rc==-1)
        {
            cameras++;
            return 1;
        }

        if(lc==1 || rc==1)
        {
            return 0;
        }

        return -1;
    }

    public static int min_cameras_root(Tree node)
    {
        int val=min_cameras(node);

        if(val==-1)
            cameras++;

        return cameras;    
    }
    
    //PROGRAM 15
    public static class All_sol
    {
        int height=-1;
        int size=0;
        boolean find=false;
        Tree pred=null;
        Tree succ=null;
        Tree prev=null;
        int ceil=Integer.MAX_VALUE;
        int floor=Integer.MIN_VALUE;
    }

    public static void all_solutions(Tree node,int data,int level,All_sol pair)
    {
        if(node==null)
            return; 
            
        pair.height=Math.max(pair.height,level);
        pair.size++;
        pair.find=pair.find|| node.data==data;
        
        if(node.data>data && pair.ceil>node.data)
            pair.ceil=node.data;

        if(node.data<data && pair.floor<node.data)
            pair.floor=node.data;

        all_solutions(node.left,data,level+1,pair);

        if(node.data==data && pair.pred==null)
            pair.pred=pair.prev;

        if(pair.prev!=null && pair.prev.data==data && pair.succ==null)
            pair.succ=node; 
            
        pair.prev=node;    

        all_solutions(node.right,data,level+1,pair); 
    }

    //SET 1
    public static void binary_tree()
    {
        int[] arr={8,10,1,-1,-1,6,9,-1,-1,7,-1,-1,3,-1,14,13,-1,-1,-1};
        Tree root=tree_creation(arr);
        System.out.println(root);
        //display_tree(root);
        //System.out.println(size(root));
        //System.out.println(max_height(root));
        //System.out.println(min_height(root));
        //System.out.println(find(root,70));
        //System.out.print(lowest_common_ancestor(root,50,60));
        //k_distance_nodes(root,2,60);
        //level_order_traversal(root);
        //k_distance_nodes_better(root,2,60);
        //System.out.print(diameter_01(root));
        /*int[] ans=diameter_02(root);
        System.out.print(ans[0]+" "+ans[1]);*/
        /*max_sum_path_leaf_to_leaf(root);
        System.out.println(maxsum);*/
        /*max_sum_path_node_to_node(root);
        System.out.println(maxsum1);*/
        /*min_cameras_root(root);
        System.out.println(cameras);*/
        /*All_sol pair=new All_sol();
        all_solutions(root,20,0,pair);
        System.out.println(pair.height+" "+pair.size+" "+pair.pred.data+" 
        "+pair.succ.data+" "+pair.ceil+" "+pair.floor+" "+pair.find);*/
    }

    //PROGRAM 16
    public static Tree bst_creation(int[] arr,int si,int ei)
    {
        if(si>ei)
            return null;

        int mid=si+(ei-si)/2;  
        Tree node=new Tree(arr[mid]);

        node.left=bst_creation(arr,si,mid-1);
        node.right=bst_creation(arr,mid+1,ei);

        return node;
    }

    //PROGRAM 17
    public static boolean find_bst_01(Tree node,int data)
    {
        if(node==null)
            return false;

        if(node.data==data)
            return true;
            
        if(node.data<data)
            return find_bst_01(node.right,data);   
            
        else
            return find_bst_01(node.left,data);    
    }

    //PROGRAM 18
    public static boolean find_bst_02(Tree node,int data)
    {
        while(node!=null)
        {
            if(node.data==data)
                return true;
            
            if(node.data<data)
                node=node.right; 
            
            else
                node=node.left;    
        }

        return false;
    }

    //PROGRAM 19
    public static Tree add_data(Tree node,int data)
    {
        if(node==null)
            return new Tree(data);

        else if(data<node.data)
            node.left=add_data(node.left,data);

        else
            node.right=add_data(node.right,data); 

        return node;    
    }

    //PROGRAM 20
    public static void successor_predecessor_bst(Tree node,int data)
    {
        Tree succ=null;
        Tree pred=null;

        while(node!=null)
        {
            if(node.data==data)
            {
                if(node.right!=null)
                {
                    succ=node.right;
                    while(succ.left!=null)
                    {
                        succ=succ.left;
                    }
                }

                if(node.left!=null)
                {
                    pred=node.left;
                    while(pred.right!=null)
                    {
                        pred=pred.right;
                    }
                }

                System.out.println(succ!=null?succ.data:-1);
                System.out.println(pred!=null?pred.data:-1);
                return;
            }

            if(node.data>data)
            {
                succ=node;
                node=node.left;
            }

            else
            {
                pred=node;
                node=node.right;
            }
        }
    }

    //PROGRAM 21
    public static int minimum_in_tree(Tree node)
    {
        if(node==null)
            return Integer.MAX_VALUE;

        Tree rnode=node;

        while(rnode.right!=null)
        {
            rnode=rnode.left;
        }

        return rnode.data;
    }

    //PROGRAM 22
    public static int  maximum_in_tree(Tree node)
    {
        if(node==null)
            return Integer.MIN_VALUE;

        Tree rnode=node;
        while(rnode.left!=null)
        {
            rnode.right=node;
        }

        return rnode.data;
    }

    //PROGRAM 23
    public static Tree delete_data(Tree node,int data)
    {
        if(node==null)
            return null;
        
        if(node.data==data)
        {
            if(node.left==null || node.right==null)
            {
                return node.left==null?node.right:node.left;
            }

            /*int max_data=maximum_in_tree(node.left);
            node.data=max_data;
            node.left=delete_node(node.left,max_data);*/

            int min_data=minimum_in_tree(node.right);
            node.data=min_data;
            node.right=delete_data(node.right,min_data);
        }

        if(node.data>data)
        {
            node.left=delete_data(node.left,data);
        }    

        if(node.data<data)
        {
            node.right=delete_data(node.right,data);
        }

        return node;
    }

    //PROGRAM 24
    public static Tree rightmost_of_left(Tree leftnode,Tree curr)
    {
        while(leftnode.right!=null && leftnode.right!=curr)
        {
            leftnode=leftnode.right;
        }

        return leftnode;
    }

    public static void morris_traversal_inorder(Tree node)
    {
        Tree curr=node;

        while(curr!=null)
        {
            Tree leftnext=curr.left;

            if(leftnext==null)
            {
                System.out.print(curr.data+" ");
                curr=curr.right;
            }

            else
            {
                Tree rightmost=rightmost_of_left(leftnext,curr);

                if(rightmost.right==null)
                {
                    rightmost.right=curr;
                    curr=curr.left;
                }

                else
                {
                    System.out.print(curr.data+" ");
                    rightmost.right=null;
                    curr=curr.right;
                }
            }
        }
    }

    //PROGRAM 25
    public static void morris_traversal_preorder(Tree node)
    {
        Tree curr=node;

        while(curr!=null)
        {
            Tree leftnext=curr.left;

            if(leftnext==null)
            {
                System.out.print(curr.data+" ");
                curr=curr.right;
            }

            else
            {
                Tree rightmost=rightmost_of_left(leftnext,curr);

                if(rightmost.right==null)
                {
                    System.out.print(curr.data+" ");
                    rightmost.right=curr;
                    curr=curr.left;
                }

                else
                {
                    rightmost.right=null;
                    curr=curr.right;
                }
            }
        }
    }

    //PROGRAM 26
    public static class Order
    {
        Tree node=null;
        boolean sd=false;
        boolean ld=false;
        boolean rd=false;

        Order(Tree node)
        {
            this.node=node;
        }
    }

    public static void pre_order(Tree node)
    {
        Stack<Order> st=new Stack<>();
        st.add(new Order(node));

        while(st.size()!=0)
        {
            Order pair=st.peek();

            if(!pair.sd)
            {
                pair.sd=true;
                System.out.print(pair.node.data+" ");
            }

            else if(!pair.ld)
            {
                pair.ld=true;
                if(pair.node.left!=null)
                    st.add(new Order(pair.node.left));
            }

            else if(!pair.rd)
            {
                pair.rd=true;
                if(pair.node.right!=null)
                    st.add(new Order(pair.node.right));
            }

            else
            {
                st.pop();
            }
        }
    }

    //PROGRAM 27
    public static void in_order(Tree node)
    {
        Stack<Order> st=new Stack<>();
        st.add(new Order(node));

        while(st.size()!=0)
        {
            Order pair=st.peek();

            if(!pair.ld)
            {
                pair.ld=true;
                if(pair.node.left!=null)
                    st.add(new Order(pair.node.left));
            }

            else if(!pair.sd)
            {
                pair.sd=true;
                System.out.print(pair.node.data+" ");
            }

            else if(!pair.rd)
            {
                pair.rd=true;
                if(pair.node.right!=null)
                    st.add(new Order(pair.node.right));
            }

            else
            {
                st.pop();
            }
        }
    }

    //PROGRAM 28
    public static void post_order(Tree node)
    {
        Stack<Order> st=new Stack<>();
        st.add(new Order(node));

        while(st.size()!=0)
        {
            Order pair=st.peek();

            if(!pair.ld)
            {
                pair.ld=true;
                if(pair.node.left!=null)
                    st.add(new Order(pair.node.left));
            }

            else if(!pair.rd)
            {
                pair.rd=true;
                if(pair.node.right!=null)
                    st.add(new Order(pair.node.right));
            }

            else if(!pair.sd)
            {
                pair.sd=true;
                System.out.print(pair.node.data+" ");
            }

            else
            {
                st.pop();
            }
        }
    }

    //SET 2
    public static void binary_search_tree()
    {
        /*int[] arr={10,20,30,40,50,60,70,80,90,100,110,120,130,140};
        Tree root=bst_creation(arr,0,arr.length-1);*/
        //add_data(root,65);
        //delete_data(root,110);
        //System.out.println(root);
        //System.out.println(find_bst_01(root,10));
        //System.out.println(find_bst_02(root,10));
        //successor_predecessor_bst(root,90);
        //morris_traversal_inorder(root);
        //morris_traversal_preorder(root);
        //pre_order(root);
        //in_order(root);
        //post_order(root);
    }

    //MAIN
    public static void main(String[] args)
    {
        binary_tree();
        //binary_search_tree();
    }
}

/*

//lecture014
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Stack;
import java.util.LinkedList;
import java.util.HashMap;

public class question {
    public static Scanner scn = new Scanner(System.in);

    //CLASS
    public static class Node {
        int val = 0;
        Node left = null;
        Node right = null;

        Node(int val) {
            this.val = val;
        }

        Node(int val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {
            String str = "";
            str += left != null ? left.val : ".";
            str += ("->" + val + "<-");
            str += (right != null ? right.val : ".");
            str += "\n";

            if (left != null) {
                str += left.toString();
            }

            if (right != null) {
                str += right.toString();
            }

            return str;
        }
    }

    // PROGRAM 1
    // TO CREATE A BINARY TREE
    static int idx = 0;

    public static Node createTree(int[] arr) {

        if (idx == arr.length || arr[idx] == -1) {
            if (arr[idx] == -1)
                idx++;
            return null;
        }

        Node root = new Node(arr[idx]);
        idx++;
        root.left = createTree(arr);
        root.right = createTree(arr);

        return root;
    }

    // PROGRAM 2
    // TO DISPLAY THE BINARY TREE
    public static void displayTree(Node root) {
        if (root == null)
            return;

        System.out.print(root.left != null ? root.left.val : -1);
        System.out.print(" -> " + root.val + " <- ");
        System.out.println(root.right != null ? root.right.val : -1);

        displayTree(root.left);
        displayTree(root.right);
    }

    // PROGRAM 3
    // TO FIND THE SIZE OF BINARY TREE
    public static int sizeOfTree(Node root) {
        if (root == null)
            return 0;

        return sizeOfTree(root.left) + 1 + sizeOfTree(root.right);
    }

    // PROGRAM 4
    // TO FIND THE HEIGHT/DEPTH OF BINARY TREE
    public static int heightOfTree(Node root) {
        if (root == null)
            return -1;

        int leftHeight = heightOfTree(root.left);
        int rightHeight = heightOfTree(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    // PROGRAM 5
    // TO FIND A PARTICULAR DATA IN A BINARY TREE
    public static boolean findInTree(int data, Node root) {
        if (root == null)
            return false;
        if (root.val == data)
            return true;

        boolean res = false;
        res = res || findInTree(data, root.left);
        res = res || findInTree(data, root.right);

        return res;
    }

    // PROGRAM 6
    // TO FIND MINIMUM HEIGHT IN A BINARY TREE
    public static int minHeightOfTree(Node root) {
        if (root == null)
            return -1;

        if (root.left == null)
            return minHeightOfTree(root.right) + 1;

        if (root.right == null)
            return minHeightOfTree(root.left) + 1;

        int leftHeight = minHeightOfTree(root.left);
        int rightHeight = minHeightOfTree(root.right);
        return Math.min(leftHeight, rightHeight) + 1;
    }

    // PROGRAM 7
    // TO FIND MAXIMUM DATA IN BINARY TREE
    public static int maximumInTree(Node root) {
        if (root == null)
            return -1;

        int leftMax = maximumInTree(root.left);
        int rightMax = maximumInTree(root.right);

        return Math.max(root.val, Math.max(leftMax, rightMax));
    }

    // SET 1
    public static void basicBT(Node root) {
        // displayTree(root);
        // System.out.println(sizeOfTree(root));
        // System.out.println(heightOfTree(root));
        // System.out.println(findInTree(15,root));
        // System.out.println(minHeightOfTree(root));
        // System.out.println(maximumInTree(root));
    }

    // PROGRAM 8
    // TO FIND A PATH FROM ROOT TO A NODE IN BINARY TREE
    public static ArrayList<Node> rootToNodePath(Node root, int nodeData) {
        if (root == null) {
            ArrayList<Node> base = new ArrayList<>();
            return base;
        }

        if (root.val == nodeData) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(root);
            return base;
        }

        ArrayList<Node> leftPath = rootToNodePath(root.left, nodeData);
        if (leftPath.size() != 0) {
            leftPath.add(root);
            return leftPath;
        }

        ArrayList<Node> rightPath = rootToNodePath(root.right, nodeData);
        if (rightPath.size() != 0) {
            rightPath.add(root);
            return rightPath;
        }

        return new ArrayList<>();
    }

    // PROGRAM 9
    // TO FIND LOWEST COMMON ANCESTOR OF TWO NODES IN BINARY TREE
    public static int lowestCommonAncestor(int d1, int d2, Node root) {
        ArrayList<Node> rootTod1 = rootToNodePath(root, d1);
        ArrayList<Node> rootTod2 = rootToNodePath(root, d2);

        int i = rootTod1.size() - 1;
        int j = rootTod2.size() - 1;
        int ans = -1;

        while (i >= 0 && j >= 0) {
            if (rootTod1.get(i) != rootTod2.get(j))
                break;

            ans = rootTod1.get(i).val;
            i--;
            j--;
        }

        return ans;
    }

    // PROGRAM 10
    // TO FIND NODES THAT ARE K DISTANCE AWAY FROM THE GIVEN NODE
    public static void kDown(Node curr, Node prev, int k) {
        if (curr == null)
            return;

        if(prev != null && prev == curr) 
            return;

        if (k == 0) {
            System.out.print(curr.val + " ");
            return;
        }

        kDown(curr.left, prev, k - 1);
        kDown(curr.right, prev, k - 1);
    }

    public static void kDistanceAway_1(int d, int k, Node root) {
        ArrayList<Node> path = rootToNodePath(root, d);
        Node prev = null;

        for (int i = 0; i < path.size(); i++) {
            kDown(path.get(i), prev, k - i);
            prev = path.get(i);
        }
    }

    // PROGRAM 11
    // TO FIND NODES THAT ARE K DISTANCE AWAY FROM THE GIVEN NODE(OPTIMIZED) 
    public static int kDistanceAway_2(int d, int k, Node root) {
        
        if(root == null) 
            return -1;
        
        if(root.val == d) {
            kDown(root, null, k);
            return 1; 
        } 
        
        int leftDistance = kDistanceAway_2(d, k, root.left);
        if(leftDistance != -1) {
            if(leftDistance == k) {
                System.out.print(root.val + " ");
            }
            else {
                kDown(root,root.left,k-leftDistance);
            }
            return leftDistance+1;
        }

        int rightDistance = kDistanceAway_2(d, k, root.right);
        if(rightDistance != -1) {
            if(rightDistance == k) {
                System.out.print(root.val + " ");
            }
            else {
                kDown(root,root.right,k-rightDistance);
            }
            return rightDistance+1;
        }

        return -1;
    }

    // PROGRAM 12
    // TO FIND THE DIAMETER OF BINARY TREE
    public static int diameterOfTree_1(Node root) {
        if(root == null) 
            return 0;
        
        int leftDiameter = diameterOfTree_1(root.left);
        int rightDiameter = diameterOfTree_1(root.right);
        
        int leftHeight = heightOfTree(root.left);
        int rightHeight = heightOfTree(root.right);

        return Math.max(leftHeight+rightHeight+2,Math.max(leftDiameter,rightDiameter));
    }

    // PROGRAM 13
    // TO FIND THE DIAMETER OF BINARY TREE (OPTIMIZED)
    public static int[] diameterOfTree_2(Node root) {
        if(root == null) 
            return new int[] {0,-1};
        
        int[] leftAnswer = diameterOfTree_2(root.left);
        int[] rightAnswer = diameterOfTree_2(root.right);
        
        int diameter = Math.max(leftAnswer[1] + rightAnswer[1] + 2,(Math.max(leftAnswer[0],rightAnswer[0]))); 
        int height = Math.max(leftAnswer[1],rightAnswer[1]) + 1;
        
        return new int[] {diameter,height};
    }

    // SET 2
    public static void traversalDepth(Node root) {
        // System.out.println(lowestCommonAncestor(10,4,root));
        // kDistanceAway_1(2,2,root);
        // kDistanceAway_2(2,2,root);
        // System.out.println(diameterOfTree_1(root));
        // int[] ans = diameterOfTree_2(root);
        // System.out.println(ans[0] +" "+ ans[1]); 
    }

    // PROGRAM 14
    // LEVEL ORDER TRAVERSAL OF BINARY TREE
    public static void levelOrder_1(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        int level = 0;

        while (que.size() != 0) {
            System.out.print(level + " -> ");
            int size = que.size();

            while (size-- > 0) {
                Node rnode = que.removeFirst();

                System.out.print(rnode.val + ",");

                if (rnode.left != null)
                    que.addLast(rnode.left);

                if (rnode.right != null)
                    que.addLast(rnode.right);
            }
            level++;
            System.out.println();
        }
    }

    // PROGRAM 15
    // LEVEL ORDER TRAVERSAL OF BINARY TREE (ANOTHER METHOD)
    public static void levelOrder_2(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);
        que.addLast(null);
        int level = 0;
        System.out.print(level + " -> ");
        while (que.size() != 1) {

            Node rnode = que.removeFirst();
            System.out.print(rnode.val + ",");

            if (rnode.left != null)
                que.addLast(rnode.left);

            if (rnode.right != null)
                que.addLast(rnode.right);

            if (que.getFirst() == null) {
                que.removeFirst();
                que.addLast(null);
                level++;
                System.out.println();
                System.out.print(level + " -> ");
            }
        }
    }

    // PROGRAM 16
    // TO DISPLAY LEFT VIEW OF A BINARY TREE
    public static void leftView(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);

        while(que.size() != 0) {
            int size = que.size();
            System.out.print(que.getFirst().val + " ");

            while(size-->0) {
                Node rnode = que.removeFirst();

                if (rnode.left != null)
                    que.addLast(rnode.left);

                if (rnode.right != null)
                    que.addLast(rnode.right);
            }
        }
    }

    // PROGRAM 17
    // TO DISPLAY RIGHT VIEW OF A BINARY TREE 
    public static void rightView(Node root) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(root);

        while(que.size() != 0) {
            int size = que.size();
            Node prev = null;

            while(size-->0) {
                Node rnode = que.removeFirst();

                if (rnode.left != null)
                    que.addLast(rnode.left);

                if (rnode.right != null)
                    que.addLast(rnode.right);
                
                prev = rnode;    
            }
            System.out.print(prev.val + " ");
        }
    }

    // SET 3
    public static void traversalBreadth(Node root) {
        // levelOrder_1(root);
        // levelOrder_2(root);
        // leftView(root);
        rightView(root);
    }

    //CLASS
    public static class AllSolution {
        int height = -1;    // height of tree
        int size = 0;       // size of tree
        boolean find = false; // find in tree
        Node pred = null;   // predecessor of element
        Node succ = null;   // successor of element
        Node prev = null;   // storing previous node
        int ceil=Integer.MAX_VALUE;  // ceiling of element 
        int floor=Integer.MIN_VALUE; // flooring of element
    }

    // PROGRAM 16
    // TO COMPUTE ALL PARAMETERS IN A BINARY TREE
    public static void computeAllParameters(Node root, int data, AllSolution p, int level) {
        if(root == null)
            return ;
        
        p.height = Math.max(p.height,level);
        p.size++; 
        p.find = p.find || root.val == data;

        if(root.val > data && root.val < p.ceil) 
            p.ceil = root.val;
        
        if(root.val < data && root.val > p.floor) 
            p.floor = root.val;    

        computeAllParameters(root.left, data, p, level + 1);

        if(root.val == data && p.pred == null)
            p.pred = p.prev;
        
        if(p.prev != null && p.prev.val == data && p.succ == null) 
            p.succ = root;
        
        p.prev = root;       
            
        computeAllParameters(root.right, data, p, level + 1);
    }

    // PROGRAM 17
    // TO CHECK WHETHER GIVEN TREE IS A BINARY SEARCH TREE OR NOT
    static int prev = (int) -1e8;
    public static boolean isBST(Node root) {
        if (root == null)
            return true;

        if (!isBST(root.left))
            return false;

        if (prev > root.val) {
            return false;
        }
        prev = root.val;

        if (!isBST(root.right))
            return false;

        return true;
    }

    // PROGRAM 18
    // TO FIND
    // LARGEST BST
    // COUNT OF BST IN A BT
    // ROOT OF LARGEST BST 
    // IS BST
    //CLASS
    public static class BstSolutions {
        
        int bstCount = 0;
        Node largestBST = null;
        boolean isBST = true;
        int sizeOfBST = 0;

        int minVal = (int)1e8;
        int maxVal = (int)-1e8;
    }

    public static BstSolutions bstQuestions(Node root) {

        if(root == null) {
            return new BstSolutions();
        }

        BstSolutions leftPair = bstQuestions(root.left);        
        BstSolutions rightPair = bstQuestions(root.right);

        BstSolutions ansPair = new BstSolutions();

        if(leftPair.isBST && rightPair.isBST && leftPair.maxVal < root.val && rightPair.minVal >= root.val) {
            ansPair.isBST = true;
            ansPair.bstCount = leftPair.bstCount + rightPair.bstCount + 1;
            ansPair.sizeOfBST = ansPair.bstCount;
            ansPair.largestBST = root;
        }

        else {
            ansPair.isBST = false;
            ansPair.bstCount = leftPair.bstCount + rightPair.bstCount;

            if(leftPair.sizeOfBST > rightPair.sizeOfBST) {
                ansPair.sizeOfBST = leftPair.sizeOfBST;
                ansPair.largestBST = leftPair.largestBST;
            }

            else {
                ansPair.sizeOfBST = rightPair.sizeOfBST;
                ansPair.largestBST = rightPair.largestBST;
            }
        }

        ansPair.maxVal = Math.max(root.val,Math.max(leftPair.maxVal,rightPair.maxVal)); 
        ansPair.minVal = Math.min(root.val,Math.min(leftPair.minVal,rightPair.minVal));
        
        return ansPair;
    }

    // PROGRAM 19
    // TO LINAERIZE A BINARY TREE
    public static Node linearizeTree(Node root) {
        if(root == null)
            return null;
        
        if(root.left == null && root.right == null)
            return root;    
        
        Node leftEnd = linearizeTree(root.left);
        Node rightEnd = linearizeTree(root.right);

        if(leftEnd == null)
            root.left = root.right;
        
        else
            leftEnd.left = root.right;

        root.right = null;

        
        return rightEnd != null ? rightEnd:leftEnd;  
    }

    // PROGRAM 20
    // TO CONVERT A BINARY TREE TO A DOUBLY LINKED LIST
    static Node prevNode = null;
    static Node headNode = null;
    public static void treeToDLL(Node root) {
        if (root == null)
            return;

        treeToDLL(root.left);

        if(prevNode == null)
            headNode = root;
        else {
            root.left = prevNode;
            prevNode.right = root;
        }    

        prevNode = root;
        treeToDLL(root.right);
    }

    // SET 4
    public static void solutionsAndBST(Node root) {
        // AllSolution ans = new AllSolution();
        // computeAllParameters(root, 10, ans, 0);
        // System.out.println(ans.height + " " + ans.size + " " + ans.ceil + " " + ans.floor
        // + " " + ans.find + " " + ans.pred.val + " " + ans.succ.val + " ");
        // System.out.println(isBST(root));
        // BstSolutions ansPair = bstQuestions(root);
        // System.out.println(ansPair.bstCount + " " + ansPair.isBST + " " + ansPair.sizeOfBST
        //  + " " + ansPair.largestBST.val);
        // linearizeTree(root);
        // System.out.println(root);
        // treeToDLL(root);
        // while(headNode !=null) {
        //     System.out.print(headNode.val+ "->");
        //     headNode = headNode.right;
        // }
    }

    // PROGRAM 21
    // ROOT TO NODE PATH WITH TARGET SUM ONE PATH
    public static boolean pathSumI(Node root, int tar, String ans) {
        if(root == null)
            return false;
        
        if(root.left == null && root.right == null && tar - root.val == 0) {

            System.out.println(ans + root.val);
            return true;
        }

        boolean res = false;
        res = res || pathSumI(root.left, tar - root.val, ans + root.val +" ");
        res = res || pathSumI(root.right, tar - root.val, ans + root.val +" ");

        return res;
    }

    // PROGRAM 22
    // ROOT TO NODE PATH WITH TARGET SUM ALL PATH
    public static ArrayList<ArrayList<Integer>> pathSumII(Node root, int tar) {

        if(root == null) {
            return new ArrayList<>();
        }

        if(root.left == null && root.right == null && tar-root.val == 0) {
            ArrayList<ArrayList<Integer>> base = new ArrayList<>();
            ArrayList<Integer> base1= new ArrayList<>();
            base1.add(root.val);
            base.add(base1);
            return base;
        }

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<ArrayList<Integer>> leftPath = pathSumII(root.left, tar-root.val);

        if(leftPath != null) {

            for (ArrayList<Integer> e : leftPath) {
                e.add(0, root.val);
                ans.add(e);
            }
        }

        ArrayList<ArrayList<Integer>> rightPath = pathSumII(root.right, tar-root.val);
        if(rightPath != null) {

            for (ArrayList<Integer> e : leftPath) {
                e.add(0, root.val);
                ans.add(e);
            }
        }

        return ans;
    }

    // PROGRAM 23
    // ROOT TO NODE PATH WITH TARGET SUM ALL PATH (BETTER)
    public static void pathSumIIBetter(Node root, int tar, ArrayList<Integer> ans1,ArrayList<ArrayList<Integer>> ans) {
        if(root == null) {
            return;
        }

        if(root.left == null && root.right == null && tar-root.val == 0) {
            ArrayList<Integer> base=new ArrayList<>(ans1);
            base.add(root.val);
            ans.add(base);
            return;
        }

        ans1.add(root.val);
        pathSumIIBetter(root.left,tar-root.val, ans1, ans);
        pathSumIIBetter(root.right,tar-root.val, ans1, ans);
        ans1.remove(ans1.size()-1);
    }

    // PROGRAM 24
    // TO COUNT ALL PATHS FROM NODE TO NODE(CAN BE LEAF AS WELL) WITH TARGET SUM
    // public static int PathSumIII(Node root, int tar, int prefixSum, HashMap<Integer,Integer> map) {

    // }

    // PROGRAM 25
    // TO FIND MAXIMUM SUM FROM LEAF TO LEAF
    static int maxSum = Integer.MIN_VALUE;
    public static int maxSumLeafToLeaf(Node root) {
        if(root == null) {
            return Integer.MIN_VALUE;
        }

        if(root.left == null && root.right == null) {
            return root.val;
        }

        int leftSum = maxSumLeafToLeaf(root.left);
        int rightSum = maxSumLeafToLeaf(root.right);
        int sum = leftSum + rightSum + root.val;

        if(root.left != null && root.right !=null) {
            maxSum = Math.max(sum,maxSum);
        }

        return Math.max(leftSum,rightSum) + root.val;
    }

    // PROGRAM 26
    // TO FIND MAXIMUM SUM FROM NODE TO NODE
    static int maximumSum = Integer.MIN_VALUE;
    public static int maxSumNodeToNode(Node root) {
        if(root == null) {
            return Integer.MIN_VALUE;
        }

        if(root.left == null && root.right == null) {
            return root.val;
        }

        int leftSum = maxSumNodeToNode(root.left);
        int rightSum = maxSumNodeToNode(root.right);
        int sum = leftSum + rightSum + root.val;
        int maxBranchSum = Math.max(leftSum,rightSum);

        maximumSum = Math.max(Math.max(sum,maxBranchSum + root.val),Math.max(root.val, maximumSum));

        return Math.max(maxBranchSum + root.val, root.val);
    }

    // SET 5
    public static void sumBasedQuestions(Node root) {
        // pathSumI(5, 2, "");
        // pathSumII(root, 3);
        // ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        // ArrayList<Integer> ans = new ArrayList<>();
        // pathSumIIBetter(root,3,ans1,ans);
    }

    // SUPERSET 1
    public static void binaryTree() {
        int[] arr = {5,7,6,-1,11,-1,-1,8,-1,-1,9,3,-1,-1,10,-1,-1};
        Node root = createTree(arr);
        System.out.println(root);

        basicBT(root);
        traversalDepth(root);
        traversalBreadth(root);
        solutionsAndBST(root);
        sumBasedQuestions(root);
    }

    public static void main(String[] args) {
        binaryTree();
    }
}
*/