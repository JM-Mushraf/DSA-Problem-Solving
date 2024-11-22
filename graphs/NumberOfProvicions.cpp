class Solution {
public:
    void DFS(vector<vector<int>>& isConnected,int s,vector<bool> &visited)
    {
        visited[s]=true;
        for (int v = 0; v < isConnected.size(); v++) {
            if (isConnected[s][v] == 1 && !visited[v]) {
                DFS(isConnected, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> visited(n+1,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                DFS(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};