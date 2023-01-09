#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
#include<cstring>

using namespace std;


template<typename T>
class UnWeightedGraph
{
    map<T, list<T> > adjList;

    public:

    void addEdge(T u, T v, bool bidir=true)
    {
        //Default bidirectional graph
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto row:adjList)
        {
            T vertex = row.first;
            cout<<"\nVertex:"<<vertex<<"->";
            
            list<T> nbrs = row.second;
            for(auto nbr:nbrs)
            {
                cout<<nbr<<",";
            }
        }
    }

    void bfs(T src)
    {
        map<T, bool> visited;
        map<T, int> distance;
        map<T, T> parent;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        distance[src] = 0;      //Puting distance of source equal to zero
        parent[src] = src;      //Puting parent of source equal to source

        cout<<"\nBreadth First Search Traversal is:";
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";


            for(T nbr:adjList[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    distance[nbr] = distance[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        //Print distance of  all nodes from the source
        cout<<"\nDistance of all the nodes from the source is:";
        for(auto row:distance)
        {
            T vertex = row.first;
            int dist = row.second;
            cout<<"\nVertex "<<vertex<<":"<<dist;
        }

        //Print the parent of  all the nodes
        cout<<"\nParent of all the nodes from source is:";
        for(auto row:parent)
        {
            cout<<"\nVertex "<<row.first<<":"<<row.second;
        }
    }

    void shortestPath(T src, T dest)
    {
        map<T, bool> visited;
        map<T, T> parent;
        map<T, int> distance;
        queue<T> q;

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        distance[src] = 0;

        cout<<"\nBFS Traversal is:";
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            
            for(auto nbr:adjList[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    distance[nbr] = distance[node] + 1;
                    parent[nbr] = node;
                }
            }
        }

        // cout<<"\nDistance of each node from source:";
        // for(auto row:distance)
        // {
        //     cout<<"\nVertex "<<row.first<<":"<<row.second;
        // }

        // cout<<"\nParent of each node from source:";
        // for(auto row:parent)
        // {
        //     cout<<"\nVertex "<<row.first<<":"<<row.second;
        // }

        cout<<"\nShorstet distance of destinarion("<<dest<<") from source("<<src<<") is:"<<distance[dest];
        cout<<"\nShortest path is:";
        T temp =  dest;
        while(parent[temp]!=temp)
        {
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<"source("<<src<<")";
        
    }
};

template<typename T>
class WeightedGraph
{
    map<T, list<pair<T, int> > > adjList;

    public:
        void addEdge(T u, T v, int wt, bool bidir=true)
        {
            adjList[u].push_back(make_pair(v, wt));
            if(bidir)
            {
                adjList[v].push_back(make_pair(u, wt));
            }
        }

        void printAdjList()
        {
            for(auto row:adjList)
            {
                T vertex = row.first;
                list< pair<T, int> > nbrs = row.second;

                cout<<"\nVertex:"<<vertex<<"->";
                for(auto nbr:nbrs)
                {
                    T node = nbr.first;
                    int weight = nbr.second;
                    cout<<"("<<node<<","<<weight<<"),";
                }
            }
        }

        void bfs(T src)
        {
            map<T, bool> visited;
            map<T, int> distance;
            map<T, T> parent;
            queue<T> q;

            q.push(src);
            visited[src] = true;
            distance[src] = 0;

            cout<<"\nBreadth First Search Traversal of graph is:";
            while(!q.empty())
            {
                T node = q.front();
                cout<<node<<" ";
                q.pop();

                for(auto nbr:adjList[node])
                {
                    if(!visited[nbr.first])
                    {
                        q.push(nbr.first);
                        visited[nbr.first] = true;
                        distance[nbr.first] = distance[node] + 1;
                        parent[nbr.first] = node;
                    }
                }
            }
        }

};


int R = 10;
int C = 10;
void printMat(char mat[][50])
{
    for(int i=0;i<R;i++)
    {
        cout<<"\n";
        for(int j=0;j<C;j++)
        {
            cout<<mat[i][j]<<" ";
        }
    }
}

void floodFill(char mat[][50], int i, int j, char ch, char color)
{
    if(i<0 || j<0 || i>=R || j>=C || mat[i][j]!=ch)     //Base cases
        return;

    //Fill color in the cells
    mat[i][j] = color;

    //Call to fill the color on neighbouring cells
    floodFill(mat,i+1,j,ch,color);
    floodFill(mat,i,j+1,ch,color);
    floodFill(mat,i-1,j,ch,color);
    floodFill(mat,i,j-1,ch,color);
}

int main()
{
    // //UnWeighted Graph
    // UnWeightedGraph<int> g;
    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(5,0);

    // g.printAdjList();
    // g.bfs(0);
    // g.shortestPath(0,4);
    // cout<<"\n\n----------------------------------------------------------------------------------\n";

    // //Weighted Graph
    // WeightedGraph<string> g2;
    // g2.addEdge("A","B",10);
    // g2.addEdge("B","D",40);
    // g2.addEdge("A","C",10);
    // g2.addEdge("C","D",40);
    // g2.addEdge("A","D",50);

    // g2.printAdjList();
    // g2.bfs("A");

    //Snakes&Ladders question
    // cout<<"\n----------------------------------------------------------------------------------"
    //     <<"\nSnakes & Ladders Game solution";
    
    // int board[50] = {0};
    // board[2] = 13;
    // board[5] = 2;
    // board[9] = 18;
    // board[18] = 11;
    // board[17] = -13;
    // board[20] = -14;
    // board[24] = -8;
    // board[25] = -10;
    // board[32] = -2;
    // board[34] = -22;
    
    // UnWeightedGraph<int> g3;

    // for(int u=0;u<36;u++)   //Insert edges
    // {
    //     //Throw a dice from 1 to 6
    //     for(int dice=1;dice<=6;dice++)
    //     {
    //         int v = u + dice + board[u+dice];
    //         g3.addEdge(u,v,false);
    //     }
    // }
    // g3.shortestPath(0,36);


    //Flood Filling Algorithm
    cout<<"\n---------------------------------------------------------------------------------------"
        <<"\nFlood Fill Algorithm";


    char mat[50][50] = {
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','#','#','#','#','#','#','#','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','.','.','.','.','.','.','#','.'},
        {'.','#','#','#','#','#','#','#','#','.'},
        {'.','.','.','.','.','.','.','.','.','.'}
    };

    //This call me used to for getting matrix from the user
    // cout<<"\nEnter the number of rows and columns:";
    // cin>>R>>C;

    // for(int i=0;i<R;i++)
    // {
    //     for(int j=0;j<C;j++)
    //         cin>>mat[i][j];
    // }

    printMat(mat);
    floodFill(mat,5,5,'.','R');
    printMat(mat);



    return 0;
}