void bfs(vector<int> adj[],int s,int v)
{
    vector<bool> visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
    }
    queue<int> q1;
    visited[s]=1;
    q1.push(s);
    while(!q1.empty())
    {
        int u=q1.front();
        q1.pop();
        cout<<u<<" "<<;
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q1.push(v);
            }
        }
    }
}