import java.util.PriorityQueue;
import java.util.HashMap;
public class lecture017
{
    static HashMap<String,String> decode=new HashMap<>();
    static HashMap<String,String> encode=new HashMap<>();
    public static class Node implements Comparable<Node>
    {
        String data="";
        int freq=0;
        Node left=null;
        Node right=null;

        Node(String data,int freq,Node left,Node right)
        {
            this.data=data;
            this.freq=freq;
            this.left=left;
            this.right=right;
        }

        @Override
        public int compareTo(Node o)
        {
            return this.freq-o.freq;
        }
    }

    public static void huffman_tree(String s)
    {
        PriorityQueue<Node> pq=new PriorityQueue<>();
        int[] freq=new int[26];

        for(int i=0;i<s.length();i++)     // TO FIND THE FREQUENCY OF EACH CHARACTER
        {
            char ch=s.charAt(i);
            freq[ch-'a']++;
        }

        for(int i=0;i<freq.length;i++)     //PUSHING ALL THE ELEMENTS IN THE PRIORITY QUEUE
        {
            if(freq[i]>0)
                pq.add(new Node((char)(i+'a')+"",freq[i],null,null));
        }

        while(pq.size()!=1)                //CREATING TREE BY REMOVING TWO NODES OF LOWEST FREQUENCY
        {                                  //ADDING THE MERGED NODE TO THE QUEUE
            Node p1=pq.poll();             //APPENDING THE REMOVED  NODES TO  THE LEFT AND RIGHT OF THE MERGED NODES
            Node p2=pq.poll();

            pq.add(new Node("",p1.freq+p2.freq,p1,p2));
        }

        huffman_traversal(pq.remove(),"");;
    }

    public static void huffman_traversal(Node node,String ans)
    {
        if(node.left==null && node.right==null)
        {
            encode.put(node.data,ans);
            decode.put(ans,node.data);
            return;
        }

        huffman_traversal(node.left,ans+"0");
        huffman_traversal(node.right,ans+"1");
    }

    public static String encode_str(String str)
    {
        StringBuilder sb=new StringBuilder();

        for(int i=0;i<str.length();i++)
        {
            String s=str.charAt(i)+"";
            sb.append(encode.get(s));
        }

        return sb.toString();
    }

    public static String decode_str(String str)
    {
        StringBuilder sb=new StringBuilder();

        int i=0;
        for(int j=1;j<=str.length();j++)
        {
            String s=str.substring(i,j);
            if(decode.containsKey(s))
            {
                i=j;
                sb.append(decode.get(s));
            }
        }

        return sb.toString();
    }

    public static void main(String[] args)
    {
        huffman_tree("aabcbfbcddsidhbiufghfbugvfhguvdgvudyvfgebudvgffpuifhbdutrfnutyriyu");
        System.out.println(encode);
        System.out.println(decode);
        String str=encode_str("aabbcd");
        System.out.println(str);
        String str1=decode_str(str);
        System.out.println(str1);
    }
}