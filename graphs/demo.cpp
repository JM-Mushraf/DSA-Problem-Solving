#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector<int> adj[],int v,int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

//the below function is when we have conneted graph
// void bfs(vector<int> adj[],int s,int v)
// {
//     vector<bool> visited(v,false);
//     queue<int> q1;
//     visited[s]=1;
//     q1.push(s);
//     while(!q1.empty())
//     {
//         int u=q1.front();
//         q1.pop();
//         cout<<u<<" ";
//         for(int v:adj[u])
//         {
//             if(visited[v]==false)
//             {
//                 visited[v]=true;
//                 q1.push(v);
//             }
//         }
//     }
// }

//the below function is when we have multiple disconneted graphs
void bfsDS(vector<int> adj[],int s,vector<bool> &visited)
{
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
    cout<<endl;
}
void bfsDisConnected(vector<int>adj[],int v)
{
    vector<bool> visited(v,false);
    int count=0;
    for (int i = 0; i < v; i++)
    {
        if(visited[i]==false)
        {
            bfsDS(adj,i,visited);
            count++;
        }
    }
    cout<<"Total number of disconnected Graphs:"<<count<<endl;
    
}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);

    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    // printGraph(adj,v);
    // bfs(adj,0,v);
    bfsDisConnected(adj, v);
    return 0;
}