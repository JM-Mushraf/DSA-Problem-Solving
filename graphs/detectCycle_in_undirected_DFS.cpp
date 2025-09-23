bool isCycle(int v,vector<int>adj[]){
    vector<int>vis(v,0);

    for(int i=0;i<v;i++){
        if(vis[i]==0){
            if(detectCycle(i,adj,vis,-1)){
                return true;
            }
        }
    }
    return false;
}

bool detectCycle(int src,vector<int>adj[],vector<int>&vis,int parent){
    vis[src]=1;
    for(auto adjnode : adj[src]){
        if(!vis[adjnode]){
            if(detectCycle(adjnode,adj,vis,src)==true){
                return true;
            }
        }
        else if(parent!=adjnode){
            return true;
        }
    }
    return false;
}