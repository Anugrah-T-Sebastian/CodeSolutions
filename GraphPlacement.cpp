#include<bits/stdc++.h>

using namespace std;

struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/
void buildUndirectedGraph(int E, vector<int> adj[])
{
    for(int i=0;i<E;i++)
    {
        int u, v;
        cout<<"\nEnter the edge for (u-v):";
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void buildDirectedGraph(int E, vector<int> adj[])
{
    for(int i=0;i<E;i++)
    {
        int u, v;
        cout<<"\nEnter the edge for (u->v):";
        cin>>u>>v;

        adj[u].push_back(v);
    }
}

void buildDirectedWeightedGraph(int E, vector<pair<int,int>> adj[])
{
    for(int i=0;i<E;i++)
    {
        int u, v, wt;
        cout<<"\nEnter the edge for (u->{v,wt}):";
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
    }
}

void buildUndirectedWeightedGraph(int E, vector<pair<int,int>> adj[])
{
    for(int i=0;i<E;i++)
    {
        int u, v, wt;
        cout<<"\nEnter the edge for (u->{v,wt}):";
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Print functions

void pritntAdjList(int V, vector<int> adj[])
{
    for(int node=0;node<V;node++)
    {
        cout<<"\nVertex"<<node<<"->";
        for(int nbr:adj[node])
        {
            cout<<nbr<<",";
        }
    }
}

void printVector(vector<int> v)
{
    cout<<"\n[";
    for(auto i:v)
        cout<<i<<",";
    cout<<"]";
}

void pritntAdjListWeighted(int V, vector<pair<int, int>> adjW[])
{
    for(int node=0;node<V;node++)
    {
        cout<<"\nVertex"<<node<<"->";
        for(auto nbr:adjW[node])
        {
            cout<<"{"<<nbr.first<<","<<nbr.second<<"}, ";
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    map<int, bool> visited;
    vector<int> bfs;
    queue<int> q;

    cout<<"\nBreadth First Search:";

    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(int nbr:adj[node])
        {
            if(!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
    
    return bfs;

}

void dfs(int Node, map<int, bool> &visited, vector<int> adj[], vector<int> &storeDFS)
{
    storeDFS.push_back(Node);
    visited[Node] = true;

    for(auto nbr:adj[Node])
    {
        if(!visited[nbr])
        {
            dfs(nbr,visited,adj,storeDFS);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> storeDFS;
    map<int, bool> visited;

    for(int i=0;i<V;i++)
        visited[i] = false;

    cout<<"\nDepth First Search";

    dfs(0,visited,adj,storeDFS);

    return storeDFS;
}
/*---------------------------------------------------------------------------------------------------------------------------------*/
//Cycle Detection

bool checkForCycleBFS(int src, int V, vector<int> adj[], map<int, bool> &visited)
{
    //Create q queue for BFS
    queue<pair<int, int>> q;

    visited[src] = true;
    q.push({src, -1});

    while ((!q.empty()))
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto nbr:adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push({nbr, node});
            }
            else if(parent != nbr)  //If parent of the already visited node is not equal to it's neighbour node(previous)
                return true;
        }
    }
    return false;
    
}

bool isCycleBFS(int V, vector<int> adj[])
{
    map<int, bool> visited;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(checkForCycleBFS(i,V,adj,visited))
                return true;
        }
    }
    return false;
}

bool checkForCycleDFS(int node, int parent, map<int, bool> &visited, vector<int> adj[])
{
    visited[node] = true;
    for(auto nbr:adj[node])
    {
        //Case 1: nbr is not visited
        if(visited[nbr] == false)
        {
            //Go and recursivel visit the nbr
            if(checkForCycleDFS(nbr,node,visited,adj))
                return true;
        }

        //Case 2: nbr is visited but nbr should not be equal to the parent
        else if(nbr != parent)
            return true;
    }
    return false;
}


bool isCycleDFS(int V, vector<int> adj[])
{
    map<int, bool> visited;
    
    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(checkForCycleDFS(i,-1,visited,adj))
                return true;
        }
    }
    return false;
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/
//Bipartite Detection
bool isBipartiteBFS(int V, vector<int> adj[])
{
    map<int, bool> visited;
    map<int, int> color;
    queue<int> q;

    for(int i;i<V;i++)
    {
        visited[i] = false;
        color[i] = -1;
    }

    int count=0;
    q.push(0);
    visited[0] = true;
    color[0] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout<<"\nCount"<<count++;
        for(auto nbr:adj[node])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                q.push(nbr);
                if(color[node] == 0)
                    color[nbr] = 1;
                else if(color[node] == 1)
                    color[nbr] = 0;
            }
            else
            {
                if(color[node] == color[nbr])
                    return false;
            }
        }
    }
    return true;
}

bool checkForBipartiteDFS(int node,int color, map<int, int> & colored, vector<int> adj[], map<int, bool> &visited)
{
    visited[node] =  true;
    colored[node] = color;

    for(auto nbr:adj[node])
    {
        if(!visited[nbr])
        {
            if(colored[node] == 0)
                checkForBipartiteDFS(nbr,1,colored,adj,visited);
            else if(colored[node] == 1)
                checkForBipartiteDFS(nbr,0,colored,adj,visited);
        }
        else
        {
            if(colored[node] != colored[nbr])
                return true;
            else
                return false;
        }
    }
    return true;
     
}

bool isBipartiteDFS(int V, vector<int> adj[])
{
    map<int, bool> visited;
    map<int, int> colored;

    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        colored[i] = -1;
    }

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(checkForBipartiteDFS(i,0,colored,adj,visited))
                return true;
        }
    }
    return false;
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
//Directed Graph Cycle Detection

bool checkCycleForDirectedGraphDFS(int node, vector<int> adj[], map<int, bool> &visited, map<int, bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto nbr:adj[node])
    {
        //If the neighbour has never been visited, then pass to on for the check
        if(!visited[nbr])
        {
            if(checkCycleForDirectedGraphDFS(nbr,adj,visited,dfsVisited))
                return true;
        }

        //If the neighbour has been visited in this DFS recursion itself, then it is the neighnour repeating itself i.e. there is a cycle
        else if(dfsVisited[nbr])
            return true;
    }

    //If it's an end node, then mark it as unvisited for new DFS pass, and do the same for rest for the node in the current DFS path
    dfsVisited[node] = false;
    return false;
}

bool isCyclicDirectedGraphDFS(int V, vector<int> adj[])
{
    map<int, bool> visited, dfsVisited;
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        dfsVisited[i] = false;
    }
    
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(checkCycleForDirectedGraphDFS(i,adj,visited,dfsVisited))
                return true;
        }
    }
    return false;
}

bool isCyclicDirectedGraphBFS(int V, vector<int> adj[])
{
    //Generate a Topological sort & check if topological sort is generated thent the graph is acyclic
    queue<int> q;
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto nbr:adj[i])
            indegree[nbr]++;
    }

    for(int i=0;i<V;i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    int count = 0;      //To count the number of vertices generated in the topological sort
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for(auto nbr:adj[node])
        {
            indegree[nbr]--;
            if(indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    if(count == V)      //If the graph is acyclic then the no. of vertices generated in topological sort is equal to number of vertices in the graph
        return false;
    else
        return true;
    
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Topological Sort

void dfsTopoSort(int node, vector<int> adj[], map<int, bool> &visited, stack<int> &sorted)
{
    visited[node] = true;

    for(auto nbr:adj[node])
    {
        if(!visited[nbr])
        {
            dfsTopoSort(nbr,adj,visited,sorted);
        }
    }
    //After traversing all the adjacent nodes, push the node into the stack
    sorted.push(node);
}

vector<int> topologicalSortDFS(int V, vector<int> adj[])
{
    map<int, bool> visited;
    stack<int> sorted;

    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsTopoSort(i,adj,visited,sorted);
        }
    }

    vector<int> v;
    while(!sorted.empty())
    {
        v.push_back(sorted.top());
        sorted.pop();
    }

    cout<<"\nTopological Sort using DFS:";
    return v;
}

vector<int> topologicalSortBFS(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(V, 0);
    for(int i=0;i<V;i++)
    {
        for(auto nbr:adj[i])
            indegree[nbr]++;    //When a neighbour is encountered, its indegree is increased by 1
    }

    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);      //Pushing the starting nodes into the queue to act as source in BFS
    }

    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto nbr:adj[node])
        {
            indegree[nbr]--;        //Reducing the indegree of neighbour by 1
            if(indegree[nbr] == 0)
                q.push(nbr);        //When indegree of a node becomes 0 i.e. all incoming edges to it have been traverersed, then push the node into the queue
        }
    }

    cout<<"\nTopological Sort using BFS:";
    return topo;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Shortest Path
void shortestDistanceWithUnitWeights(int V, int src, vector<int> adj[])
{
    vector<int> distance(V,INT_MAX);
    queue<int> q;

    distance[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(auto nbr:adj[node])
        {
            if(distance[node]+1 < distance[nbr])
            {
                distance[nbr] = distance[node] + 1;
                q.push(nbr);
            }

        }
            
    }

    for(int i=0;i<V;i++)
        cout<<"\nDistance of Vertex"<<i<<":"<<distance[i];
}

void findTopoSort(int node, bool visited[], stack<int> &st, vector<pair<int, int>> adj[])
{
    visited[node] = true;
    for(auto nbr:adj[node])
    {
        if(!visited[nbr.first])
        {
            findTopoSort(nbr.first,visited,st,adj);
        }
    }
    st.push(node);
}

void shortestPathForDAG(int V, int src, vector<pair<int, int>> adj[])
{
   bool visited[V];
   stack<int> st;

   for(int i=0;i<V;i++)
        visited[i] = false;
   
   //First perform the Topological sort
   for(int i=0;i<V;i++)
   {
       if(!visited[i])
        findTopoSort(i,visited,st,adj);
   }
   
   //Create an arrray to store the distance
   int distance[V];
   for(int i=0;i<V;i++)
        distance[i] = INT_MAX;
    
    distance[src] = 0;
    while(!st.empty())        //Traverse the graph according the graph received in topological sort
    {
        int node = st.top();
        st.pop();

        if(distance[node] != INT_MAX)       //This means that the node is unreachable from any path starting from source till now
        {
            for(auto nbr:adj[node])
            {
                if(distance[node] + nbr.second < distance[nbr.first])
                    distance[nbr.first] = distance[node] + nbr.second;
            }
        }
    }

    for(int i=0;i<V;i++)
        cout<<"\nDistance of Vertex"<<i<<":"<<distance[i];
}

void dijkstraAlgo(int V, int src, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> distanceToSource(V,INT_MAX);

    distanceToSource[src] = 0;
    pq.push(make_pair(0,src));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(it=adj[prev].begin();it!=adj[prev].end();it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if(distanceToSource[next] > distanceToSource[prev]+nextDist)
            {
                distanceToSource[next] = distanceToSource[prev] + nextDist;
                pq.push(make_pair(distanceToSource[next],next));
            }
        }
    }
    for(int i=0;i<V;i++)
        cout<<"\nDistance of Vertex"<<i<<":"<<distanceToSource[i];

}

void bellmanFord(int V, int E)     //TC= O(V*E)    SC=O(V)
{
    vector<node> edges;
    for(int i=0;i<E;i++)
    {
        int u, v, wt;
        cout<<"\nEnter the edge (u->{v,wt}):";
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }

    int src;
    cout<<"\nEnter the source of the Graph:";
    cin>>src;

    vector<int> distance(V,INT_MAX);
    distance[src] = 0;

    for(int i=0;i<=V-1;i++)
    {
        for(auto it:edges)
        {
            if(distance[it.u] + it.wt < distance[it.v])
                distance[it.v] = distance[it.u] + it.wt;
        }
    }
    
    bool flag = false;
    for(auto it:edges)
    {
        if(distance[it.u] + it.wt < distance[it.v])
        {
            cout<<"\nNegative Cycle!!";
            flag = true;
            break;
        }
    }

    if(!flag)
    {
        cout<<"\nShorted Distance..";
        for(int i=0;i<V;i++)
            cout<<"\nVertex "<<i<<":"<<distance[i];
    }
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Disjoint operations
int disjointSet(int n, vector<int> &rank,vector<int> &parent)
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;      
            rank[i] = 0;
        }
    }

int findPar(int node, vector<int> &rank,vector<int> &parent)
{
    if(node == parent[node])
        return node;
    else
        return parent[node] = findPar(parent[node],rank,parent);        //Path compression property
}

void unionDisjointSet(int u, int v, vector<int> &rank,vector<int> &parent)
{
    u = findPar(u,rank,parent);
    v = findPar(v,rank,parent);

    if(rank[u] < rank[u])
        parent[u] = v;      //One with the higher rank becomes the parent
    else if(rank[v] < rank[u])
        parent[u]= v;
    else
    {
        //In case of equal rank of parent node, anyone of node can become the parent of other
        //Rank the rank of that parent node increases by 1
        parent[v] = u;
        rank[u]++;
    } 
}

bool sameComponent(int u, int v, vector<int> &rank,vector<int> &parent)
{
    //To check if two node belong to same connected components
    if(findPar(u,rank,parent) != findPar(v,rank,parent))
        return false;
    else
        return true;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Minimum spanning tree
void primsAlgo(int V, vector<pair<int, int>> adjW[])
{
    //Declare the array
    int parent[V];      //To store parent of the nodes
    int key[V];     //To store the key values of the node
    bool mstSet[V];     //To store whether the node has been included in the MST

    for(int i=0;i<V;i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[i] = -1;
    }
        

    key[0] = 0;
    parent[0] = 0;

    //Find the node with minimum key value if it is not present in the MST(use mstSet)
    
    for(int count=0; count< V-1; count++)       //Because MST has N-1(V-1) edges
    {
        int mini = INT_MAX;     //To keep track of minimum key value
        int u;
        for(int v=0; v < V;v++)
        {
            if(mstSet[v] == false && key[v] < mini) //If the node is not part of MST and value is lesser than minimum
            {
                mini = key[v];      //Update minimum
                u = v;      //Store the index
            }  
        }
        mstSet[u] = true;       //Now make it the part of MST

        //Iterate over the adjacent node
        for(auto nbr:adjW[u])
        {
            int v = nbr.first;
            int weight = nbr.second;
            if(mstSet[v]==false && weight<key[v])       //If the neighbour is not part of MST and has larger key value
            {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    
    //Print MST
    for(int i = 1; i<V; i++)        //Staring from 1 because source 0 has not parent
        cout<<"\nVertex "<<parent[i]<<"-"<<i;
}

bool compare(node a, node b)
{
    return a.wt < b.wt;
}

void kruskalsAlgo(int N, int E)     //TC=O(ElogE)   SC=O(V)
{
    //(1) Sort all the edges according to their weights in a linear data structure in format {wt,u,v}
    //(2) Pick the edges increasing order and connect them if they do not belong to the same connected component & connect them using disjoint union
    vector<node> edges;
    for(int i=0;i<E;i++)
    {
        int u, v, wt;
        cout<<"\nEnter edge {u,v,wt}:";
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(),edges.end(), compare);

    vector<int> parent(N);
    for(int i=0;i<N;i++)
    {
        parent[i] = i;
    }
        
    vector<int> rank(N, 0);
    int cost = 0;
    vector<pair<int, int>> mst;
    for(auto it:edges)
    {
        if(findPar(it.v,rank,parent) != findPar(it.u,rank,parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionDisjointSet(it.u, it.v, rank, parent);
        }
    }

    cout<<"\nMinimum Spanning Tree is total cost:"<<cost;
    for(auto it:mst)
        cout<<"\nVertex:"<<it.first<<"-"<<it.second;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Bridge
void dfsBridge(int node, int parent, vector<int> &visited, vector<int> &time, vector<int> &lowestTime, int &timer, vector<pair<int, int>> &bridgeList, vector<int> adj[])
{
    visited[node] = 1;
    time[node] = lowestTime[node] = timer++;
    for(auto nbr:adj[node])
    {
        if(nbr == parent)       //If the neighbour is the parent of the node, then it means that the DFS is going backward. In that case node updation must be done
            continue;

        if(!visited[nbr])
        {
            dfsBridge(nbr,node,visited,time,lowestTime,timer,bridgeList,adj);
            //After the DFS is completed, update the lowestTime for the node with the lowestTime of its neighbouring node
            lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
            if(lowestTime[nbr] > time[node])        //MAIN FORMULA!!!
                bridgeList.push_back({node, nbr});
        }
        else
            lowestTime[node] = min(lowestTime[node], time[nbr]);
    }
}

void detectBridges(int V, vector<int> adj[])
{
    //Difficult algo. If in doubt watch video at URL:https://youtu.be/2rjZH0-2lhk?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    vector<int> time(V, -1);
    vector<int> lowestTime(V, -1);
    vector<int> visited(V, 0);
    vector<pair<int, int>> bridgeList;
    int timer = 0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsBridge(i,-1,visited,time,lowestTime,timer,bridgeList,adj);
        }
    }
    cout<<"\nThe Bridges in the graph are...";
    for(auto it:bridgeList)
        cout<<"\nEdge "<<it.first<<"-"<<it.second;

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Aritculation Point
void dfsArticulationPoint(int node, int parent, vector<int> &visited, vector<int> &time, vector<int> &lowestTime, int &timer, vector<int> &isArticulationPoint, vector<int> adj[])
{
    visited[node] = 1;
    time[node] = lowestTime[node] = timer++;
    int child = 0;      //To compute individual childern of the starting node
    for(auto nbr:adj[node])
    {
        if(nbr == parent)       //If the neighbour is the parent of the node, then it means that the DFS is going backward. In that case node updation must be done
            continue;

        if(!visited[nbr])
        {
            dfsArticulationPoint(nbr,node,visited,time,lowestTime,timer,isArticulationPoint,adj);
            //After the DFS is completed, update the lowestTime for the node with the lowestTime of its neighbouring node
            lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
            if(lowestTime[nbr] >= time[node] && parent != -1)        //MAIN FORMULA!!!
                isArticulationPoint[node] = 1;

            child++;
        }
        else
            lowestTime[node] = min(lowestTime[node], time[nbr]);
    }

    if(parent == -1 && child > 1)
        isArticulationPoint[node] = 1;
}

void detectArticulationPoint(int V, vector<int> adj[])
{
    //Difficult algo. If in doubt watch video at URL:https://youtu.be/2rjZH0-2lhk?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    vector<int> time(V, -1);
    vector<int> lowestTime(V, -1);
    vector<int> visited(V, 0);
    vector<int> isArticulationPoint(V,0);
    int timer = 0;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfsArticulationPoint(i,-1,visited,time,lowestTime,timer,isArticulationPoint,adj);
        }
    }
    cout<<"\nThe Articulation Points in the graph are...\n[";
    for(int i=0;i<V;i++)
    {
        if(isArticulationPoint[i] == 1)
            cout<<i<<",";
    }
    cout<<"]";

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Kosaraju's Algorithm to find Strongly Connected Components
void revDFS(int Node, map<int, bool> &visited, vector<int> adj[])
{
    cout<<Node<<" ";
    visited[Node] = true;

    for(auto nbr:adj[Node])
    {
        if(!visited[nbr])
        {
            revDFS(nbr,visited,adj);
        }
    }
}

void kosarajusAlgo(int V, vector<int> adj[])        //TC=O(V+E)     SC=O(V+E)
{
    //Difficult algo. If in doubt watch URL: https://youtu.be/V8qIqJxCioo?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
    //(1) Sort all nodes in order of finishing time i.e. Topological Sort
    //(2) Transpose the graph, so that we the the Strongle Connected Components can be seperated
    //(3)   DFS according to finishing time i.e. Topological Sort resultant stack

    stack<int> sorted;
    map<int, bool> visited;

    for(int i=0;i<V;i++)
        visited[i] = false;

    //(1) Perform Topo Sort and store in the stack
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            dfsTopoSort(i,adj,visited,sorted);
    }

    //(2) Transpose the graph i.e. (u->v) to (v->u)
    vector<int> transpose[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
        for(auto nbr:adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    //
    while(!sorted.empty())
    {
        int node = sorted.top();
        sorted.pop();
        if(!visited[node])
        {
            cout<<"\nStrongly Connected Components:";
            revDFS(node,visited,transpose);
        }
    }

}
/*-------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    system("cls");
    int n, m;
    cout<<"Enter number of nodes:";
    cin>>n;
    cout<<"\nEnter the number of edges:";
    cin>>m;
    vector<int> adj[n+1];
    vector<pair<int, int>> adjW[n+1];

    
    // //Graph Traversal
    // vector<int> v = bfsOfGraph(n,adj);
    // printVector(v);
    // v = dfsOfGraph(n,adj);
    // printVector(v);

    /*--------------------------------------------------------------------------------------------------*/
    // //Cycle Detection
    // if(isCycleBFS(n,adj))
    //     cout<<"\nCycle exists in the given graph";
    // else
    //     cout<<"\nCycle does not exist in the given graph";


    // //Bipartite Graph Detection
    // if(isBipartiteBFS(n,adj))
    //     cout<<"\nThe graph is Bipartite";
    // else
    //     cout<<"\nThe graph is not Bipartite";
    // if(isBipartiteDFS(n,adj))
    //     cout<<"\nThe graph is Bipartite";
    // else
    //     cout<<"\nThe graph is not Bipartite";
    /*------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Cycle detection for Directed Graphs
    // buildDirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // if(isCyclicDirectedGraphDFS(n,adj))
    //     cout<<"\nThe Directed Graph has a cycle";
    // else
    //     cout<<"\nThe Directed Graph does not have a cycle";

    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Topological Sort
    // buildDirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // vector<int> v = topologicalSortDFS(n,adj);
    // printVector(v);
    // v = topologicalSortBFS(n,adj);
    // printVector(v);

    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Shortest Distance in Undirected Graph with unit weights
    // buildUndirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // shortestDistanceWithUnitWeights(n,0,adj);
    // buildDirectedWeightedGraph(m,adjW);
    // pritntAdjListWeighted(n,adjW);
    // shortestPathForDAG(n,0,adjW);

    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Minimum Spanning Tree
    // buildUndirectedWeightedGraph(m,adjW);
    // pritntAdjListWeighted(n,adjW);
    // primsAlgo(n,adjW);
    //kruskalsAlgo(n,m);

    /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Briges
    // buildUndirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // detectBridges(n,adj);

    /*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Articulation Point
    // buildUndirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // detectArticulationPoint(n,adj);

    /*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    // Find Strongly Connected Components
    // buildDirectedGraph(m,adj);
    // pritntAdjList(n,adj);
    // kosarajusAlgo(n,adj);
    
    /*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    //Shortest Distance in Directed Weighted Graph
    // bellmanFord(n,m);


    return 0;
}