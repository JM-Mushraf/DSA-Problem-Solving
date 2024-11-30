/*Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.*/
// Code:-

class DisjointSets
{
public:
    vector<int> parent, size;
    DisjointSets(int v)
    {
        size.resize(v + 1, 1);
        parent.resize(v + 1);
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
        }
    }
    int findupr(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findupr(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int u_ulp = findupr(u);
        int v_ulp = findupr(v);
        if (u_ulp == v_ulp)
        {
            return;
        }
        if (size[u_ulp] < size[v_ulp])
        {
            parent[u_ulp] = v_ulp;
            size[v_ulp]++;
        }
        else
        {
            parent[v_ulp] = u_ulp;
            size[u_ulp]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSets ds(n);
        unordered_map<string, int> mapmailnode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mapmailnode.find(mail) == mapmailnode.end())
                {
                    mapmailnode[mail] = i;
                }
                else
                {
                    ds.unionBySize(i, mapmailnode[mail]);
                }
            }
        }
        vector<string> mergedmail[n];
        for (auto it : mapmailnode)
        {
            string mail = it.first;
            int node = ds.findupr(it.second);
            mergedmail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedmail[i].size() == 0)
                continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};