vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes; // {col: {row: {values}}}
    queue<pair<TreeNode*, pair<int, int>>> q; // {node, {row, col}}
    
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int row = p.second.first, col = p.second.second;
        
        nodes[col][row].insert(node->val);
        
        if (node->left) {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right) {
            q.push({node->right, {row + 1, col + 1}});
        }
    }
    
    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    
    return ans;
}