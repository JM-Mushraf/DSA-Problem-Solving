bool isCycle(int v,vector<int>adj[]){
    vector<int>vis(v,0);

    for(int i=0;i<v;i++){
        if(vis[i]==0){
            if(detectCycle(i,adj,vis)){
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(int src,vector<int>adj[],vector<int>&vis){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;

        q.pop();
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                q.push({adjnode,node});
                vis[adjnode]=1;
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    }
    return false;
}


