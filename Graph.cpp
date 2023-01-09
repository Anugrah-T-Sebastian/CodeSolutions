#include<iostream>
#include<list>      //For undirected graph
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>


using namespace std;

class UndirectedGraph
{
    int V;
    list<int> *l;
    
    public:
        UndirectedGraph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }

        void AddEdgeUG(int x, int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void PrintAdjListUG()
        {
            for(int i=0; i<V; i++)
            {
                cout<<"\nVertex:"<<i<<"->";
                for(int nbr:l[i])
                {
                    cout<<nbr<<" ";
                }
            }
        }
};

class DirectedWeightedGraph
{
    //Adj List in form  A->[(B,20)(C,10)]
    unordered_map<string, list<pair<string, int>>> l;
    
    public:
        void AddEdge(string x, string y, bool bidir, int wt)
        {
            l[x].push_back(make_pair(y,wt));
            if(bidir)       //If the edge is bidirectional then create an edge other way around too
            {
                l[y].push_back(make_pair(x,wt));
            }
        }

        void PrintAjList()
        {
            //Iterate over all the keys in the map
            //p returns all elements of Adj list i.e. A->[(B,20)(C,10)]
            for(auto p:l)
            {
                string city = p.first;      //A is the first part of the Adj list
                list<pair<string, int>> nbrs = p.second;        //[(B,20)(C,10)] is the second part of the Adj lis

                cout<<"\nCity:"<<city<<"->";

                //Iterating over all the pairs
                for(auto nbr:nbrs)
                {
                    string dest = nbr.first;        //B is the first part of the pair list
                    int dist = nbr.second;          //20 is the second part of the pair list

                    cout<<"("<<dest<<" "<<dist<<"),";

                }

            }
        }
};

template<typename T>        //Creating Template for T
class TemplateGraph
{
    map<T, list<T> > l;      //map<int, list<int> >

    public:
        void AddEdge(int x, int y)
        {
            //Assuming that the edges are Bidirectional unweighted
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void bfs(T src)
        {
            map<T, int> visited;
            queue<T> q;

            q.push(src);
            visited[src] = true;        //Visited means that visited node has already being into the queue

            cout<<"\nBreadth First Search Traversal is:";
            while(!q.empty())
            {
                T node = q.front();
                q.pop();
                cout<<node<<" ";

                for(int nbr:l[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);        //Push the nbr into the queue
                        visited[nbr] = true;        //Mark that nbr as visited
                    }
                }
            }
        }

        void dfs(T src, map<T, bool> &visited)
        {
            //Recursive function that will traverse the graph
            //We take in the source node and the map structure by reference because we want to make changes to the same map & not create copies of it
            cout<<src<<" ";
            visited[src] =  true;
            //Go to all nbr of that node that is not visited
            for(T nbr: l[src])
            {
                if(!visited[nbr])
                {
                    dfs(nbr, visited);
                }
            }
        }

        void dfs_Traversal(T src)
        {
            map<T, bool> visited;       //MArk all the nodes as not visited
            for(auto p:l)
            {
                T node = p.first;
                visited[node] = false;
            }

            cout<<"\nDepth First Search Traversal is:";
            //call dfs function
            dfs(src, visited);      //We pass on the source and the visited mapped
        }

        
};

class DirectedGraph
{
    int V;
    list<int> *l;
    
    public:
        DirectedGraph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }

        void AddEdge(int x, int y)
        {
            l[x].push_back(y);
        }

        void PrintAdjList()
        {
            for(int i=0; i<V; i++)
            {
                cout<<"\nVertex:"<<i<<"->";
                for(int nbr:l[i])
                {
                    cout<<nbr<<" ";
                }
            }
        }

        bool Detect_cycle(int node, bool *visited, int parent)
        {
            visited[node] = true;

            for(auto nbr:l[node])
            {
                //Case 1: nbr is not visited
                if(!visited[nbr])
                {
                    //Go and recursivel visit the nbr
                    bool cycle_detected = Detect_cycle(nbr, visited, node);
                    if(cycle_detected)
                        return true;

                }

                //Case 2: nbr is visited but nbr should not be equal to the parent
                else if(nbr != parent)
                {
                    return true;
                }
            }
            return false;
        }

        bool Contains_cycle()
        {
            //Check for Cycle in Directed Graph
            bool *visited = new bool[V];
            for(int i=0; i<V; i++)
            {
                visited[i] = false;
            }

            return Detect_cycle(0, visited, -1);
        }
};

int main()
{
    //Undirected Graph
    UndirectedGraph g1(4);
    g1.AddEdgeUG(0,1);
    g1.AddEdgeUG(2,3);
    g1.AddEdgeUG(0,2);
    g1.AddEdgeUG(1,2);

    g1.PrintAdjListUG();

    //Directed Weighted Graph
    DirectedWeightedGraph g2;
    g2.AddEdge("A","B",true,20);
    g2.AddEdge("B","D",true,40);
    g2.AddEdge("A","C",true,10);
    g2.AddEdge("C","D",true,40);
    g2.AddEdge("A","D",false,50);

    g2.PrintAjList();

    //Template Graph
    TemplateGraph<int> g3;
    g3.AddEdge(0,1);
    g3.AddEdge(1,2);
    g3.AddEdge(2,3);
    g3.AddEdge(3,4);
    g3.AddEdge(4,5);

    g3.bfs(0);
    g3.dfs_Traversal(0);

    //Directed Graph
    DirectedGraph g4(5);
    g4.AddEdge(0,1);
    g4.AddEdge(1,2);
    g4.AddEdge(2,3);
    g4.AddEdge(3,4);
    //g4.AddEdge(4,0);

    g4.PrintAdjList();

    if(g4.Contains_cycle())
        cout<<"\nThe Graph contains a cycle";
    else
        cout<<"\nThe Graph does NOT contains a cycle";



    return 0;
}