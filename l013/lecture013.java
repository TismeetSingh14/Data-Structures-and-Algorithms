//lecture013
import java.util.ArrayList;
import java.util.Scanner;
public class lecture013
{
    public static Scanner scn=new Scanner (System.in);

    //CLASS 1
    public static class Edge
    {
        int v=0;
        int w=0;

        Edge(int v,int w)
        {
            this.v=v;
            this.w=w;
        }

        Edge()
        { }
    }

    //ARRAYLIST OF ARRAYLIST FOR CREATING GRAPH
    static ArrayList<ArrayList<Edge>> graph=new ArrayList<>();

    //PROGRAM 1
    //FOR ADDING EDGES IN THE GRAPH AND DISPLAYING THE GRAPH
    public static void addEdge(int u,int v,int w)
    {
        if(u<0 || v<0 || u>=graph.size() || v>=graph.size())
            return;
        
        graph.get(u).add(new Edge(v,w));  
        graph.get(v).add(new Edge(u,w));   
    }

    public static void displayGraph()
    {
        for(int i=0;i<graph.size();i++)
        {
            System.out.print(i + "-> ");
            for(Edge e:graph.get(i))
            {
                System.out.print("(" + e.v + "," + e.w + "), ");
            }
            System.out.println();
        }
    }

    //PROGRAM 2
    //TO REMOVE AN EDGE FROM THE GRAPH
    public static void removeEdge(int u,int v)
    {
        int i=-1;
        int j=-1;

        for(int k=0;k<graph.get(u).size();k++)
        {
            if(graph.get(u).get(k).v==v)
            {
                i=k;
                break;
            }
        }

        for(int k=0;k<graph.get(v).size();k++)
        {
            if(graph.get(v).get(k).v==u)
            {
                j=k;
                break;
            }
        }

        graph.get(u).remove(i);
        graph.get(v).remove(j);
    }

    //PROGRAM 3
    //TO REMOVE A GIVEN VERTEX FROM THE GRAPH
    public static void removeVertex(int u)
    {
        for(int i=graph.get(u).size()-1;i>=0;i--)
        {
            removeEdge(graph.get(u).get(i).v,u);
        }
    }

    //SET 1
    public static void graphCreation()
    {
        //INITIALIZING THE ARRAYLIST WITH EMPTY ARRAYLISTS
        for(int i=0;i<7;i++)
            graph.add(new ArrayList<Edge>());

        addEdge(0,1,10);
        addEdge(0,3,10);
        addEdge(2,3,40);
        addEdge(1,2,10);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);

        removeEdge(3,4);
        removeVertex(3);

        displayGraph();
    }
    
    //MAIN
    public static void main(String[] args)
    {
        graphCreation();
    }
}