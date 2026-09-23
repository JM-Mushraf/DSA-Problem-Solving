/*
Top View of BT
Subscribe to TUF+

Hints
Company
Given the root of a binary tree, return the top view of the binary tree.



The top view of a binary tree consists of the set of nodes visible when the tree is observed from above.



Return the values of these nodes ordered from the leftmost to the rightmost position.



If multiple nodes share the same horizontal distance from the root, only the node that appears first when traversing from left to right (i.e., the leftmost node) should be included in the result.


Example 1

Input : root = [1, 2, 3, 4, 5, 6, 7]

Output : [4, 2, 1, 3, 7]

Explanation :



Example 2

Input : root = [10, 20, 30, 40, 60, 90, 100]

Output : [40, 20, 10, 30, 100]
*/

// code:
class Solution {
public:
    // {level, {horizontal distance, node value}}
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    void traversal(TreeNode* root, int level, int hd) {
        if (root == nullptr)
            return;

        pq.push({level, {hd, root->data}});

        traversal(root->left, level + 1, hd - 1);
        traversal(root->right, level + 1, hd + 1);
    }

    vector<int> topView(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        traversal(root, 0, 0);

        map<int, int> mp;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int level = it.first;
            int hd = it.second.first;
            int value = it.second.second;

            // First node at this horizontal distance
            if (mp.find(hd) == mp.end()) {
                mp[hd] = value;
            }
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};