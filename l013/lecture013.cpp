//lecture013
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>
#define IF 9999

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }

    Edge()
    {
    }
};

//VECTOR OF VECTOR FOR CREATING GRAPH
vector<vector<Edge *>> graph(7, vector<Edge *>());
vector<vector<Edge *>> graph_transpose(7, vector<Edge *>());
vector<vector<Edge *>> dijkstra_graph(7, vector<Edge *>());
vector<vector<Edge *>> prims_graph(7, vector<Edge *>());

//PROGRAM 1
//FOR ADDING EDGES IN THE GRAPH AND DISPLAYING THE GRAPH
void addEdge(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    //TO MAKE A DIRECTED GRAPH COMMENT THE LINE GIVEN BELOW
    graph[v].push_back(new Edge(u, w));
}

//DISPLAY FOR GRAPH
void displayGraph()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "-> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << "," << e->w << "), ";
        }
        cout << endl;
    }
}

//PROGRAM 2
//TO REMOVE AN EDGE FROM THE GRAPH
void removeEdge(int u, int v)
{
    int i = -1;
    int j = -1;

    for (int k = 0; k < graph[u].size(); k++)
    {
        if (graph[u][k]->v == v)
        {
            i = k;
            break;
        }
    }

    for (int k = 0; k < graph[v].size(); k++)
    {
        if (graph[v][k]->v == u)
        {
            j = k;
            break;
        }
    }

    graph[u].erase(graph[u].begin() + i);
    graph[v].erase(graph[v].begin() + j);
}

//PROGRAM 3
//TO REMOVE A GIVEN VERTEX FROM THE GRAPH
void removeVertex(int u)
{
    for (int i = graph[u].size() - 1; i >= 0; i--)
    {
        removeEdge(graph[u][i]->v, u);
    }
}

//SET 1
void graphCreation()
{
    //GRAPH 1
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(2, 3, 40);
    addEdge(1, 2, 10);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 3);
    addEdge(5, 6, 8);

    //GRAPH 2
    /*addEdge(0,1,4); 
	addEdge(0,7,8); 
	addEdge(1,2,8); 
	addEdge(1,7,11); 
	addEdge(2,3,7); 
	addEdge(2,8,2); 
	addEdge(2,5,4); 
	addEdge(3,4,9); 
	addEdge(3,5,14); 
	addEdge(4,5,10); 
	addEdge(5,6,2); 
	addEdge(6,7,1); 
	addEdge(6,8,6); 
	addEdge(7,8,7);*/

    //SNAKES AND LADDERS GRAPH
    /*int board[30]={0};

    board[2]=6;
    board[6]=11;
    board[11]=7;
    board[24]=-10;
    board[7]=-4;

    for(int i=0;i<=25;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=board[j];

            if(j<=25)
                addEdge(i,j,1);
        }
    }
    addEdge(25,25,1);*/

    //DIRECTED ACYCLIC GRAPH
    /*addEdge(0,1,0);
    addEdge(0,5,0);
    addEdge(1,2,0);
    addEdge(2,3,0);
    addEdge(3,4,0);
    addEdge(6,5,0);
    addEdge(6,7,0);
    addEdge(7,8,0);
    addEdge(8,4,0);*/

    //DIRECTED CYCLIC GRAPH
    /*addEdge(0,1,0);
    addEdge(1,2,0);
    addEdge(2,3,0);
    addEdge(3,0,0);*/

    //removeEdge(3,4);
    //removeVertex(3);

    //displayGraph();
}

//========================================================================================

//PROGRAM 4
//TO FIND ONE PATH BETWEEN SOURCE AND DESTINATION
bool dfsOnePath(int src, int des, vector<bool> &vis, string ans)
{

    if (src == des)
    {
        cout << ans << des << endl;
        return true;
    }

    vis[src] = true;
    bool res = false;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            res = res || dfsOnePath(e->v, des, vis, ans + to_string(src) + "-> ");
    }

    vis[src] = false;
}

//PROGRAM 5
//TO FIND ALL PATHS BETWEEN SOURCE AND DESTINATION
int dfsAllPath(int src, int des, vector<bool> &vis, string ans)
{
    if (src == des)
    {
        cout << ans << des << endl;
        return 1;
    }

    int count = 0;
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += dfsAllPath(e->v, des, vis, ans + to_string(src) + "-> ");
    }

    vis[src] = false;
    return count;
}

//PROGRAM 6
//TO FIND ALL PATHS BETWEEN SOURCE AND DESTINATION WITH WEIGHT
int dfsAllPathWithWeight(int src, int des, vector<bool> &vis, string ans, int wsf)
{
    if (src == des)
    {
        cout << ans << des << " with weight " << wsf << endl;
        return 1;
    }

    int count = 0;
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            count += dfsAllPathWithWeight(e->v, des, vis, ans + to_string(src) + "-> ", wsf + e->w);
    }

    vis[src] = false;
    return count;
}

//PROGRAM 7
//TO FIND THE PATH WITH THE LIGHEST WEIGHT FROM A GIVEN SOURCE
int minwght = INT_MAX;
string minans = "";
void lighestPath(int src, int des, vector<bool> &vis, int wsf, string ans)
{
    if (src == des)
    {
        if (wsf < minwght)
        {
            minwght = wsf;
            minans = ans + to_string(src);
        }
    }

    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            lighestPath(e->v, des, vis, wsf + e->w, ans + to_string(src) + "-> ");
    }

    vis[src] = false;
}

//PROGRAM 8
//TO FIND THE PATH WITH THE HEAVIEST WEIGHT FROM A GIVEN SOURCE
int maxwght = INT_MIN;
string maxans = "";
void heaviestPath(int src, int des, vector<bool> &vis, int wsf, string ans)
{
    if (src == des)
    {
        if (wsf > maxwght)
        {
            maxwght = wsf;
            maxans = ans + to_string(src);
        }
    }

    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            heaviestPath(e->v, des, vis, wsf + e->w, ans + to_string(src) + "-> ");
    }

    vis[src] = false;
}

//PROGRAM 9
//FUNCTION FOR BASIC DFS
int dfsBasic(int src, vector<bool> &vis)
{
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            dfsBasic(e->v, vis);
    }

    return 1;
}

//TO FIND THE CONNECTED COMPONENETS IN A GRAPH
int getConnectedComponents(vector<bool> &vis)
{
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == false)
        {
            count += dfsBasic(i, vis);
        }
    }

    return count;
}

//SET 2
void dfs()
{
    vector<bool> vis(7, false);
    //cout<<dfsOnePath(0,6,vis,"");
    //cout<<dfsAllPath(0,6,vis,"");
    //cout<<dfsAllPathWithWeight(0,6,vis,"",0);
    //lighestPath(0,6,vis,0,"");
    //cout<<minans<<" with weight "<<minwght;
    //heaviestPath(0,6,vis,0,"");
    //cout<<maxans<<" with weight "<<maxwght;
    //cout<<getConnectedComponents(vis);
}

//========================================================================================

//PROGRAM 10
//TO IMPLEMENT BFS IN A GRAPH
void bfsBasic_1(int src)
{
    queue<int> que;
    vector<bool> vis(7, false);

    que.push(src);
    que.push(-1);

    int cycle = 0;
    int level = 0;
    int des = 6;

    while (que.size() != 1)
    {
        if (que.front() == -1)
        {
            level++;
            que.pop();
            que.push(-1);
            continue;
        }

        int rvtx = que.front();
        que.pop();

        if (vis[rvtx] == true)
        {
            cout << "Cycle " << ++cycle << " @ " << rvtx << endl;
            continue;
        }

        if (rvtx == des)
            cout << "Destination found at level " << level << endl;

        vis[rvtx] = true;

        for (Edge *e : graph[rvtx])
        {
            if (!vis[e->v])
                que.push(e->v);
        }
    }
}

//PROGRAM 11
//TO IMPLEMENT BFS IN A GRAPH (ANOTHER METHOD)
void bfsBasic_2(int src)
{
    queue<int> que;
    vector<bool> vis(7, false);

    que.push(src);

    int cycle = 0;
    int level = 0;
    int des = 6;

    while (que.size() != 0)
    {
        int size = que.size();

        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            if (vis[rvtx] == true)
            {
                cout << "Cycle " << ++cycle << " @ " << rvtx << endl;
                continue;
            }

            if (rvtx == des)
                cout << "Destination found at level " << level << endl;

            vis[rvtx] = true;

            for (Edge *e : graph[rvtx])
            {
                if (!vis[e->v])
                    que.push(e->v);
            }
        }

        level++;
    }
}

//PROGRAM 12
//TO IMPLEMENT SNAKES AND LADDER SHORTEST PATH USING BFS
//ANOTHER METHOD FOR BFS
void snakesAndLadder_bfsBasic_3(int src, int des)
{
    queue<int> que;
    vector<int> dis(26, INT_MAX);
    vector<int> par(26, -1);

    que.push(src);
    par[src] = src;
    dis[src] = 0;

    while (que.size() != 0)
    {
        int rvtx = que.front();
        que.pop();

        for (Edge *e : graph[rvtx])
        {
            if (dis[e->v] == INT_MAX)
            {
                que.push(e->v);
                dis[e->v] = dis[rvtx] + 1;
                par[e->v] = rvtx;
            }
        }
    }

    cout << "Won the game in dice throw number:" << dis[des] << endl;
    cout << "Path followed for the game is:";
    int i = des;
    while (i != src)
    {
        cout << i << " <- ";
        i = par[i];
    }
    cout << src << endl;
}

//SET 3
void bfs()
{
    //bfsBasic_1(0);
    //bfsBasic_2(0);
    //bfsFunction(0,25);
}

//========================================================================================

//PROGRAM 13
//TO FIND ALL HAMILTONIAN PATH AND CYCLES IN A GRAPH
int hamiltonianPathCycle(int osrc, int src, vector<bool> &vis, string ans, int VCount)
{
    if (VCount == graph.size() - 1) //HERE WE ARE COUNTING EDGES RATHER THAN VERTICES
    {                               //(IF COUNT = 0 WE COUNT EDGES) , (IF COUNT = 1 WE COUNT VERTICES)
        bool flag = false;
        for (Edge *e : graph[src])
        {
            if (e->v == osrc)
            {
                cout << "Cycle: " << ans << to_string(src) + "-> " + to_string(osrc) << endl;
                flag = true;
            }
        }

        if (flag == false)
            cout << "Path: " << ans << src << endl;

        return 1;
    }

    vis[src] = true;
    int count = 0;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            count += hamiltonianPathCycle(osrc, e->v, vis, ans + to_string(src) + "-> ", VCount + 1);
        }
    }

    vis[src] = false;
    return count;
}

//PROGRAM 14
//TO CHECK WHETHER THE GIVEN GRAPH IS BIPARTITE OR NOT (USING BFS)
class Bipar
{
public:
    int vtx = -1;
    int cl = -1;

    Bipar(int vtx, int cl)
    {
        this->vtx = vtx;
        this->cl = cl;
    }

    Bipar()
    {
    }
};

bool checkBipartiteBfs(int src)
{
    queue<Bipar *> que;
    vector<int> vis(7, -1);
    bool res = true;

    for (int i = 0; i < graph.size(); i++)
    {
        if (vis[i] == -1)
        {
            que.push(new Bipar(src, 0));

            while (que.size() != 0)
            {
                Bipar *rpair = que.front();
                que.pop();

                if (vis[rpair->vtx] != -1)
                {
                    if (vis[rpair->vtx] != rpair->cl)
                    {
                        cout << "Not Bipartite at " << rpair->vtx << endl;
                        res = false;
                    }

                    else
                    {
                        cout << "Bipartite " << rpair->vtx << endl;
                        res = true;
                    }

                    continue;
                }

                vis[rpair->vtx] = rpair->cl;

                for (Edge *e : graph[rpair->vtx])
                {
                    if (vis[e->v] == -1)
                        que.push(new Bipar(e->v, (rpair->cl + 1) % 2));
                }
            }
        }
    }

    return res;
}

//PROGRAM 15
//TO CHECK WHETHER THE GIVEN GRAPH IS BIPARTITE OR NOT (USING DFS)
//ALSO DETECTS WHETHER CYLCE OF ODD LENGTH IS PRESENT OR NOT
bool oddLengthCycle = false;
void checkBipartiteDfs(int src, vector<int> &vis, int parent, int colour)
{
    vis[src] = colour;

    for (Edge *e : graph[src])
    {
        if (vis[e->v] == 0)
            checkBipartiteDfs(e->v, vis, src, 3 - colour);
        else if (vis[e->v] != 0 && vis[e->v] == colour && e->v != parent)
            oddLengthCycle = true;
    }
}

//PROGRAM 16
//DETECTING CYCLE IN AN UNDIRECTED GRAPH USING DFS
bool cycleDetectUndirectedGraphDfs(int src, vector<bool> &vis, int parent)
{
    vis[src] = true;
    bool res = false;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            res = res || cycleDetectUndirectedGraphDfs(e->v, vis, src);
        else if (e->v != parent && vis[e->v] == true)
            return true;
    }

    return false;
}

//PROGRAM 17
//CYCLE OF SHORTEST LENGTH

//SET 4
void applicationDfsAndBfs()
{
    vector<bool> vis(7, false);
    vector<int> col(7, 0);
    bool res = false;
    //cout<<hamiltonianPathCycle(0,0,vis,"",0);
    //cout<<boolalpha<<"Overall Bipartite Nature: "<<checkBipartiteBfs(0);

    /*for(int i=0;i<graph.size();i++)
    {
        if(col[i]==0)
            checkBipartiteDfs(i,col,-1,1);
    }

    if(oddLengthCycle==true)
        cout<<"NOT BIPARTITE";
    else
        cout<<"BIPARTITE";*/

    /*for(int i=0;i<graph.size();i++)
    {
        if(vis[i]==false)
            res=res||cycleDetectUndirectedGraphDfs(i,vis,-1);
    }
    cout<<boolalpha<<res;*/
}

//========================================================================================
//BEFORE THIS SECTION MAKE THE GRAPH DIRECTED (REFER addEdge FUNCTION)

//PROGRAM 18
//IMPLEMENTING TOPOLOGICAL SORT IN A DIRECTED GRAPH
void topologicalSortDfs(int src, vector<bool> &vis, vector<int> &AnsStack)
{
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            topologicalSortDfs(e->v, vis, AnsStack);
    }

    AnsStack.push_back(src);
}

void topologicalSort()
{
    vector<bool> vis(graph.size(), false);
    vector<int> AnsStack;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            topologicalSortDfs(i, vis, AnsStack);
    }

    while (AnsStack.size() != 0)
    {
        cout << AnsStack.back() << " ";
        AnsStack.pop_back();
    }
}

//PROGRAM 19
//USING TOPOLOGICAL SORT TO DETECT CYCLE IN A DIRECTED GRAPH
bool topologicalSortDfsCycle(int src, vector<bool> &vis, vector<bool> &cycle, vector<int> &AnsStack)
{
    vis[src] = true;
    cycle[src] = true;
    bool res = false;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            res = res || topologicalSortDfsCycle(e->v, vis, cycle, AnsStack);

        else if (cycle[e->v])
            return true;
    }

    cycle[src] = false;
    AnsStack.push_back(src);
    return res;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ]]]]]]]]
}

void topologicalSortCycle()
{
    vector<bool> vis(graph.size(), false);
    vector<bool> cycle(graph.size(), false);
    vector<int> AnsStack;
    bool res = false;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            res = res || topologicalSortDfsCycle(i, vis, cycle, AnsStack);
    }

    if (res == false)
    {
        while (AnsStack.size() != 0)
        {
            cout << AnsStack.back() << " ";
            AnsStack.pop_back();
        }
    }

    else
        cout << "Cycle Detected";
}

//PROGRAM 20
//IMPLEMENTING KAHN'S ALGORITHM (GIVES TOPOLOGICAL ORDER, CYCLE DETECTION IN DIRECTED GRAPH USING BFS)
void kahnsAlgorithm()
{
    queue<int> que;
    vector<int> InDegrees(graph.size(), 0);
    vector<int> AnsStack;

    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
            InDegrees[e->v]++;
    }

    for (int i = 0; i < graph.size(); i++)
    {
        if (InDegrees[i] == 0)
            que.push(i);
    }

    while (que.size() != 0)
    {
        int rvtx = que.front();
        que.pop();
        AnsStack.push_back(rvtx);

        for (Edge *e : graph[rvtx])
        {
            InDegrees[e->v]--;

            if (InDegrees[e->v] == 0)
                que.push(e->v);
        }
    }

    if (AnsStack.size() == graph.size())
    {
        while (AnsStack.size() != 0)
        {
            cout << AnsStack.back() << " ";
            AnsStack.pop_back();
        }
    }

    else if (AnsStack.size() < graph.size())
        cout << "Cycle Detected";
}

//PROGRAM 21
//IMPLEMENTING KOSARAJU'S ALGORITHM (HELPS TO FIND STRONGLY CONNECTED COMPONENETS IN A GRAPH)
void graphTranspose()
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
            graph_transpose[e->v].push_back(new Edge(i, e->w));
    }
}

void topologicalSortDfsFunction(int src, vector<bool> &vis, vector<int> &AnsStack)
{
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
            topologicalSortDfsFunction(e->v, vis, AnsStack);
    }

    AnsStack.push_back(src);
}

vector<int> topologicalSortFunction()
{
    vector<bool> vis(graph.size(), false);
    vector<int> AnsStack;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            topologicalSortDfsFunction(i, vis, AnsStack);
    }

    return AnsStack;
}

void DfsFunction(int src, vector<bool> &vis)
{
    vis[src] = true;
    cout << src << " ";

    for (Edge *e : graph_transpose[src])
    {
        if (!vis[e->v])
            DfsFunction(e->v, vis);
    }
}

int kosarajusAlgorithm()
{
    vector<int> stack = topologicalSortFunction();
    vector<bool> vis(graph.size(), 0);

    //REVERSING THE GRAPH
    graphTranspose();
    int count = 0;

    while (stack.size() != 0)
    {
        int src = stack.back();
        stack.pop_back();

        if (vis[src] == false)
        {
            DfsFunction(src, vis);
            count++;
            cout << endl;
        }
    }

    return count;
}

//SET 5
void directedGraph()
{
    // topologicalSort();
    // topologicalSortCycle();
    // kahnsAlgorithm();
    // cout<<"No. of Strongly Connected Components are "<<kosarajusAlgorithm();
}

//========================================================================================

//PROGRAM 22
//TO IMPLEMENT DIJKSTRA ALGORITHM
class Djkpair
{
public:
    int vtx = -1;
    int pvtx = -1;
    int wt = 0;
    int wsf = 0;
    string psf = "";

    Djkpair(int vtx, int pvtx, int wt, int wsf, string psf)
    {
        this->vtx = vtx;
        this->pvtx = pvtx;
        this->wt = wt;
        this->wsf = wsf;
        this->psf = psf;
    } 

    Djkpair()
    {
    }

    bool operator<(Djkpair const &o) const
    {
        return this->wsf > o.wsf;
    }
};

void addEdgeDjk(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= dijkstra_graph.size() || v >= dijkstra_graph.size())
        return;

    dijkstra_graph[u].push_back(new Edge(v, w));
    dijkstra_graph[v].push_back(new Edge(u, w));
}

void displayDijkstraGraph()
{
    for (int i = 0; i < dijkstra_graph.size(); i++)
    {
        cout << i << "-> ";
        for (Edge *e : dijkstra_graph[i])
        {
            cout << "(" << e->v << "," << e->w << "), ";
        }
        cout << endl;
    }
}

vector<int> djkShortestPath(dijkstra_graph.size(), 0);
void dijkstraAlgorithm(int src)
{
    vector<bool> vis(graph.size(), false);
    priority_queue<Djkpair> pq;

    pq.push(Djkpair(src, -1, 0, 0, "" + to_string(src)));

    while (pq.size() != 0)
    {
        Djkpair rpair = pq.top();
        pq.pop();

        if (vis[rpair.vtx] == true) //CYCLE
            continue;

        if (rpair.pvtx != -1) //ADDING EDGES IN THE NEW GRAPH
        {
            addEdgeDjk(rpair.vtx, rpair.pvtx, rpair.wt);
            djkShortestPath[rpair.vtx] = rpair.wsf;
        }

        vis[rpair.vtx] = true;

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
                pq.push(Djkpair(e->v, rpair.vtx, e->w, rpair.wsf + e->w, rpair.psf + to_string(e->v)));
        }
    }
}

//PROGRAM 23
//TO IMPLEMENT PRIM'S ALGORITHM
class Prmpair
{
public:
    int vtx = -1;
    int pvtx = -1;
    int wt = 0;
    int wsf = 0;
    string psf = "";

    Prmpair(int vtx, int pvtx, int wt, int wsf, string psf)
    {
        this->vtx = vtx;
        this->pvtx = pvtx;
        this->wt = wt;
        this->wsf = wsf;
        this->psf = psf;
    }

    Prmpair()
    {
    }

    bool operator<(Prmpair const &o) const
    {
        return this->wt > o.wt;
    }
};

void addEdgePrm(int u, int v, int w)
{
    if (u < 0 || v < 0 || u >= prims_graph.size() || v >= prims_graph.size())
        return;

    prims_graph[u].push_back(new Edge(v, w));
    prims_graph[v].push_back(new Edge(u, w));
}

void displayPrimsGraph()
{
    for (int i = 0; i < prims_graph.size(); i++)
    {
        cout << i << "-> ";
        for (Edge *e : prims_graph[i])
        {
            cout << "(" << e->v << "," << e->w << "), ";
        }
        cout << endl;
    }
}

void primsAlgorithm(int src)
{
    vector<bool> vis(graph.size(), false);
    priority_queue<Prmpair> pq;

    pq.push(Prmpair(src, -1, 0, 0, "" + to_string(src)));

    while (pq.size() != 0)
    {
        Prmpair rpair = pq.top();
        pq.pop();

        if (vis[rpair.vtx] == true) //CYCLE
            continue;

        if (rpair.pvtx != -1) //ADDING EDGES IN THE NEW GRAPH
            addEdgePrm(rpair.vtx, rpair.pvtx, rpair.wt);

        vis[rpair.vtx] = true;

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
                pq.push(Prmpair(e->v, rpair.vtx, e->w, rpair.wsf + e->w, rpair.psf + to_string(e->v)));
        }
    }
}

//PROGRAM 24
//ALGORITHM FOR DISJOINT SET UNION (DSU)
//TO FIND THE EDGE WHICH MAKES THE GRAPH WITH A CYCLE (REFER REDUNDANT CONNECTIONS)
void merge(int p1, int p2, vector<int> &size, vector<int> &par)
{
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }

    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

int findParent(int vtx, vector<int> &par)
{
    if (par[vtx] == vtx)
        return vtx;

    par[vtx] = findParent(par[vtx], par); //PATH COMPRESSION
    return par[vtx];
}

vector<int> redundandantConnection(vector<vector<int>> &edges)
{
    vector<int> parent, size;

    for (int i = 0; i < edges.size(); i++)
    {
        parent.push_back(i);
        size.push_back(1);
    }

    for (vector<int> ar : edges)
    {
        int p1 = findParent(ar[0], parent);
        int p2 = findParent(ar[1], parent);

        if (p1 != p2)
            merge(p1, p2, size, parent);

        else
            return ar;
    }

    return {};
}

//PROGRAM 25
//TO IMPLEMENT KRUSKAL'S ALGORITHM FOR MST
void displayKruskalGraph(vector<vector<pii>> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i << "-> ";
        for (pii e : g[i])
        {
            cout << "(" << e.first << "," << e.second << "), ";
        }
        cout << endl;
    }
}

int findParentKruskal(int vtx, vector<int> &par)
{
    if (par[vtx] == vtx)
        return vtx;

    par[vtx] = findParentKruskal(par[vtx], par);
    return par[vtx];
}

void mergeKruskal(int p1, int p2, vector<int> &size, vector<int> &par)
{
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }

    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

void kruskalMST(vector<piii> &arr, int n, vector<int> &par, vector<int> &size)
{
    vector<vector<pii>> MST(n, vector<pii>());

    for (int i = 0; i < arr.size(); i++)
    {
        piii rp = arr[i];

        int p1 = findParentKruskal(rp.second.first, par);
        int p2 = findParentKruskal(rp.second.second, par);

        if (p1 != p2)
        {
            mergeKruskal(p1, p2, size, par);
            //ADDING EDGES TO THE NEW GRAPH
            MST[rp.second.first].push_back({rp.second.second, rp.first});
            MST[rp.second.second].push_back({rp.second.first, rp.first});
        }
    }

    displayKruskalGraph(MST);
}

void kruskalsAlgorithmMST()
{
    vector<piii> arr;
    int n = 7;

    arr.push_back({10, {0, 1}});
    arr.push_back({10, {0, 3}});
    arr.push_back({10, {1, 2}});
    arr.push_back({40, {2, 3}});
    arr.push_back({2, {3, 4}});
    arr.push_back({2, {4, 5}});
    arr.push_back({3, {4, 6}});
    arr.push_back({8, {5, 6}});

    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        return a.first < b.first;
    });

    vector<int> par(n, 0);
    vector<int> size(n, 1);
    for (int i = 0; i < n; i++)
        par[i] = i;

    kruskalMST(arr, n, par, size);
}

//PROGRAM 26
//TO IMPLEMENT BELLMAN-FORD ALGORITHM
void bellmanFordAlgorithm(int src)
{
    vector<int> dis(graph.size(), INT_MAX);
    dis[src] = 0;

    for (int i = 0; i < graph.size() - 1; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            for (Edge *e : graph[j])
            {
                int x = j;
                int y = e->v;
                int wgt = e->w;
                if (dis[x] != INT_MAX && dis[x] + wgt < dis[y])
                    dis[y] = dis[x] + wgt;
            }
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        for (Edge *e : graph[i])
        {
            int x = i;
            int y = e->v;
            int wgt = e->w;
            if (dis[x] != INT_MAX && dis[x] + wgt < dis[y])
            {
                cout << "NEGATIVE CYCLE DETECTED" << endl;
                break;
            }
        }
    }

    cout << "DISTANCES FROM SOURCE:";
    for (int i = 0; i < graph.size(); i++)
        cout << dis[i] << " ";
}

// PROGRAM 27
// TO IMPLEMENT FLOYD WARSHALL ALGORITHM
void floydWarshallAlgorithm(vector<piii> &arr)
{
    vector<vector<int>> dist(arr.size(),vector<int>(arr.size(),IF));

    for(int i = 0; i < dist.size(); i++)
        dist[i][i] = 0;

    for(piii e:arr)
    {
        dist[e.second.first][e.second.second] = e.first;
        dist[e.second.second][e.second.first] = e.first;
    } 

    for(int k = 0; k < dist.size(); k++)
    {
        for(int i = 0; i < dist.size(); i++)
        {
            for(int j = 0; j < dist.size(); j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    } 

    for(int i = 0; i < dist.size(); i++)
    {
        for(int j = 0; j < dist.size(); j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }  
}

void floydWarshallAlgorithm()
{
    vector<piii> arr;
    arr.push_back({10, {0, 1}});
    arr.push_back({10, {0, 3}});
    arr.push_back({10, {1, 2}});
    arr.push_back({40, {2, 3}});
    floydWarshallAlgorithm(arr);
}

// PROGRAM 28
// TO IMPLEMENT SPLITWISE ALGORITHM
int splitwiseAlgorithm() // nof -> NO. OF FRIENDS,  not -> NO. OF TRANSACTIONS
{
    int noF, noT;
    cin >> noF >> noT;

    map<string, int> net;

    string x, y;
    int amount, transaction_count = 0;
    for (int i = 0; i < noT; i++)
    {
        cin >> x >> y >> amount;

        if (net.count(x) == 0)
            net[x] = 0;
        if (net.count(y) == 0)
            net[y] = 0;

        net[x] -= amount;
        net[y] += amount;
    }

    multiset<pair<int, string>> m;

    for (auto p : net)
    {
        string person = p.first;
        int amt = p.second;

        if (net[person] != 0)
            m.insert(make_pair(amt, person));
    }

    while (!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end()); // prev operator gives second from last as m.end() gives pointer after the last pointer

        auto credit = *high;
        auto debit = *low;

        // erasing the elements from the multiset
        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit.first, credit.first);
        cout << debit.second << " owes " << credit.second << " Rs." << settlement_amount << endl;
        transaction_count++;
        debit.first += settlement_amount;
        credit.first -= settlement_amount; // one of them will become 0

        if (debit.first != 0)
            m.insert(debit);

        if (credit.first != 0)
            m.insert(credit);
    }

    return transaction_count;
}

//SET 6
void graphAlgorithms()
{
    // dijkstraAlgorithm(0);
    // displayDijkstraGraph();
    // for(int i=0;i<djkShortestPath.size();i++)
    //     cout<<djkShortestPath[i]<<" ";

    // primsAlgorithm(0);
    // displayPrimsGraph();

    // vector<vector<int>> arr={{1,2},{1,3},{2,3}};
    // vector<int> ans=redundandantConnection(arr);
    // cout<<"["<<ans[0]<<","<<ans[1]<<"]";

    // kruskalsAlgorithmMST();

    // bellmanFordAlgorithm(0);

    // floydWarshallAlgorithm();

    // cout<<splitwiseAlgorithm();
}

//========================================================================================

//PROGRAM 29

//SET 7
void networkFlow()
{
}

//========================================================================================

//PROGRAM 29
//IMPLEMENTING A GRAPH USING HASHMAPS
class EdgeMap
{
public:
    string v = "";
    int w = 0;

    EdgeMap(string v, int w)
    {
        this->v = v;
        this->w = w;
    }

    EdgeMap()
    {
    }
};

unordered_map<string, vector<EdgeMap *>> graphMap;

void addEdgeMap(string u, string v, int w)
{
    graphMap[u].push_back(new EdgeMap(v, w));
    //TO MAKE THE GRAPH DIRECTED COMMENT THE LINE BELOW
    graphMap[v].push_back(new EdgeMap(u, w));
}

void displayGraphMap()
{
    for (auto key : graphMap)
    {
        cout << key.first << "-> ";
        for (auto e : key.second)
        {
            cout << "(" << e->v << "," << e->w << "), ";
        }
        cout << endl;
    }
}

//SET 7
void graphCreationMap()
{
    // addEdgeMap("A","B",20);
    // addEdgeMap("A","C",10);
    // addEdgeMap("B","D",40);
    // addEdgeMap("C","D",10);
    // addEdgeMap("A","D",50);

    // displayGraphMap();
}

//========================================================================================

//MAIN
int main(int argc, char **argv)
{
    graphCreation();
    dfs();
    bfs();
    applicationDfsAndBfs();
    directedGraph();
    graphAlgorithms();
    networkFlow();
    graphCreationMap();
}