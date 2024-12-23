/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
*/


//Code:-
class Solution {
private:
    int timer=1;
    void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>adj[],vector<vector<int>>&bridge){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;

            if(vis[it]==0){
                dfs(it,node,vis,tin,low,adj,bridge);
                low[node]=min(low[it],low[node]);

                if(low[it]>tin[node]){
                    bridge.push_back({it,node});
                }
            }else{
                low[node]=min(low[it],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridge;

        dfs(0,-1,vis,tin,low,adj,bridge);
        return bridge;
    }
};