#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cout<<"Enter the number of nodes and edges:";
    cin>>n>>m;
    vector<int> adj[m];
    cout<<"Enter the edge between nodes:"<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // int adj[n+1][m+1];
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     adj[u][v]=1;
    //     adj[v][u]=1;
    // }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<i;j++)
    //     {
    //         if(adj[i][j]!=0)
    //         {
    //             cout<<adj[i][j];
    //         }
    //         cout<<endl;
    //     }
    // }
    return 0;
}