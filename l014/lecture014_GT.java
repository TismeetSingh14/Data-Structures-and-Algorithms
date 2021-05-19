import java.io.*;
import java.util.*;

public class lecture014_GT {

    public static class Node {
        int data;
        ArrayList<Node> children = new ArrayList<>();
    }

    public static void displayTree(Node node) {
        String str = node.data + "-> ";
        for(Node child: node.children) {
            str += child.data + ", ";
        }
        str += ".";
        System.out.println(str);

        for(Node child: node.children) {
            displayTree(child);
        }
    }

    public static int size(Node node) {
        int count = 0;

        for(Node child:node.children) {
            count += size(child);
        }

        return count + 1;
    }

    public static int maxVal(Node node) {
        int max = Integer.MIN_VALUE;

        for(Node child:node.children) {
            max = Math.max(max,maxVal(child));
        }

        return Math.max(node.data, max);
    }

    public static int height(Node node) {
        int maxH = -1;

        for(Node child:node.children) {
            maxH = Math.max(maxH,height(child));
        }

        return maxH + 1;
    }

    public static void traversals(Node node) {
        
        System.out.println("PreOrder " + node.data);
        for(Node child:node.children) {
            System.out.println("Edge Pre " + node.data + "--" + child.data);    
            traversals(child);
            System.out.println("Edge Post " + node.data + "--" + child.data);
        }
        System.out.println("PostOrder " + node.data);
    }

    public static void levelOrderTraversal(Node node) {
        Queue<Node> que = new ArrayDeque<>();
        que.add(node);

        while(que.size() != 0) {
            int level = que.size();
            while(level-->0) {
                node = que.remove();
                System.out.print(node.data + " ");

                for(Node child:node.children) {
                    que.add(child);
                }
            }
            System.out.println();
        }
    }

    public static void levelOrderZigZag(Node node) {
        Stack<Node> ms = new Stack<>();
        ms.add(node);
        Stack<Node> cs = new Stack<>();
        int level = 1;
        
        while(ms.size() != 0) {
            node = ms.pop();
            System.out.print(node.data + " ");

            if(level % 2 == 1) {
                for(int i = 0; i < node.children.size(); i++) {
                    Node child = node.children.get(i);
                    cs.push(child);
                }
            }

            else {
                for(int i = node.children.size() - 1; i >= 0; i--) {
                    Node child = node.children.get(i);
                    cs.push(child);
                }
            }

            if(ms.size() == 0) {
                ms = cs;
                cs = new Stack<>();
                level++;
                System.out.println();
            }
        }
    }

    public static void mirrorOfTree(Node node) {

        for(Node child:node.children) {
            mirrorOfTree(child);
        }

        Collections.reverse(node.children);
    }

    public static void removeLeaves(Node node) {

        for(int i = node.children.size() - 1; i >=0; i--) {
            Node child = node.children.get(i);
            if(child.children.size() == 0)
                node.children.remove(child);
        }

        for(Node child:node.children) {
            removeLeaves(child);
        }
    }

    private static Node getTail(Node node) {
        while(node.children.size() == 1)
            node = node.children.get(0);
        
        return node;
    }

    public static void linearizeTree(Node node) {

        for(Node child:node.children) {
            linearizeTree(child);
        }

        while(node.children.size() > 1) {
            Node last = node.children.remove(node.children.size() - 1);
            Node secondLast = node.children.get(node.children.size() - 1);
            Node tailSecondLast = getTail(secondLast);
            tailSecondLast.children.add(last);
        }
    }

    public static Node linearizeTreeEfficient(Node node) {
        if(node.children.size() == 0)
            return node;

        Node lastTail = linearizeTreeEfficient(node.children.get(node.children.size() - 1));
        while(node.children.size() > 1) {
            Node last = node.children.remove(node.children.size() - 1);
            Node secondLast = node.children.get(node.children.size() - 1);
            Node tailSecondLast = linearizeTreeEfficient(secondLast);
            tailSecondLast.children.add(last);
        }

        return lastTail;
    }

    public static boolean find(Node node, int data) {
        if(node.data == data)
            return true;
        
        for(Node child:node.children) {
            boolean ans = find(child, data);
            if(ans)
                return true;
        }

        return false;
    }

    public static ArrayList<Node> nodeToRootPath(Node node, int data) {
        if(node.data == data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }

        for(Node child:node.children) {
            ArrayList<Node> ans = nodeToRootPath(child, data);

            if(ans.size() != 0) {
                ans.add(node);
                return ans;
            }
        }

        ArrayList<Node> a = new ArrayList<>();
        return a;
    }

    public static int LCA(Node node, int data1, int data2) {
        ArrayList<Node> list1 = nodeToRootPath(node, data1);
        ArrayList<Node> list2 = nodeToRootPath(node, data2);

        int ans=-1;
        int i=list1.size()-1;
        int j=list2.size()-1;

        while(i>=0 && j>=0) {
            if(list1.get(i)!=list2.get(j))
                break;

            ans=list1.get(i).data;
            i--;
            j--;    
        }

        return ans;
    }

    public static int distanceBetweenNodes(Node node, int data1, int data2) {
        ArrayList<Node> list1 = nodeToRootPath(node, data1);
        ArrayList<Node> list2 = nodeToRootPath(node, data2);

        int i=list1.size()-1;
        int j=list2.size()-1;

        while(i>=0 && j>=0) {
            if(list1.get(i)!=list2.get(j))
                break;
            i--;
            j--;    
        }

        i++;
        j++;

        return i + j;
    }

    public static boolean areSimilar(Node n1, Node n2) {
        if(n1.children.size() != n2.children.size())
            return false;
        
        for(int i = 0; i < n1.children.size(); i++) {
            Node c1 = n1.children.get(i);
            Node c2 = n2.children.get(i);

            if(areSimilar(c1, c2) == false)
                return false;
        }

        return true;
    }

    public static boolean areTreesMirror(Node n1, Node n2) {
        if(n1.children.size() != n2.children.size())
            return false;
        
        for(int i = 0; i < n1.children.size(); i++) {
            int j = n1.children.size() - i - 1;
            Node c1 = n1.children.get(i);
            Node c2 = n2.children.get(j);

            if(areTreesMirror(c1, c2) == false)
                return false;
        }

        return true;
    }

    public static boolean isSymmetric(Node node) {
        return areTreesMirror(node, node);
    }

    static int size;
    static int max;
    static int min;
    static int height;
    public static void multiSolver(Node node, int depth) {

        size += 1;
        min = Math.min(min, node.data);
        max = Math.max(max, node.data);
        height = Math.max(depth, height);
        for(Node child:node.children) {
            multiSolver(child, depth + 1);
        }
    }

    static Node pred;
    static Node succ;
    static int state = 0;
    public static void predAndSucc(Node node, int data) {
        if(state == 0) {
            if(node.data == data){
                state = 1;
            }

            else {
                pred = node;
            }
        }

        else if(state == 1) {
            succ = node;
            state = 2;
        }

        for(Node child:node.children) {
            predAndSucc(child, data);
        }
    }

    static int ceil;
    static int floor;
    public static void ceilAndFloor(Node node, int data) {

        if(node.data > data) {
            if(node.data < ceil) {
                ceil = node.data;
            }
        }

        if(node.data < data) {
            if(node.data > floor) {
                floor = node.data;
            }
        }

        for(Node child:node.children) {
            ceilAndFloor(child, data);
        }
    }

    public static void kthLargestElement(Node node, int k) {
        floor = Integer.MIN_VALUE;
        int factor = Integer.MAX_VALUE;
        for(int i = 0; i < k; i++) {
            ceilAndFloor(node, factor);
            factor = floor;
            floor = Integer.MIN_VALUE;
        }
    }

    static Node maxNode;
    static int maxSum = Integer.MIN_VALUE;
    public static int maximumSumSubtree(Node node) {

        int sum = 0;
        for(Node child:node.children) {
            sum += maximumSumSubtree(child);
        }

        sum += node.data;
        if(sum > maxSum) {
            maxSum = sum;
            maxNode = node;
        }

        return sum;
    }

    static int dia = 0;
    public static int diameter(Node node) {

        int dch = -1;
        int sdch = -1;
        for(Node child:node.children) {
            int ch =  maximumSumSubtree(child);
            if(ch > dch) {
                sdch = dch;
                dch = ch;
            }

            else if(ch > sdch) {
                sdch = ch;
            }
        }

        if(dch + sdch + 2 > dia) {
            dia = dch + sdch + 2;
        }

        dch += 1;

        return dch;
    }

    

    public static void main(String[] args ) {
        Integer[] arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
        Stack<Node> st = new Stack<>();
        Node root = null;

        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == -1) {
                st.pop();
            }

            else {
                Node t = new Node();
                t.data = arr[i];

                if(st.size() > 0) {
                    st.peek().children.add(t);
                }

                else {
                    root = t;
                }

                st.push(t);
            }
        }

        displayTree(root);
        // System.out.println(size(root));
        // System.out.println(maxVal(root));
        // System.out.println(height(root));
        // traversals(root);
        // levelOrderTraversal(root);
        // levelOrderZigZag(root);
        // System.out.println(LCA(root, 80, 120));
        // System.out.println(distanceBetweenNodes(root, 110, 120));
        // System.out.println(isSymmetric(root));
        // max = Integer.MIN_VALUE;
        // min = Integer.MAX_VALUE;
        // size = 0;
        // height = 0;
        // multiSolver(root, 0);
        // System.out.println(size + " " + min + " " + max + " " + height);
    }
}