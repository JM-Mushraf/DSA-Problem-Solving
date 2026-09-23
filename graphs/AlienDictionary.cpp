/*
64. Alien Dictionary
Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".

Example 1:
Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]

Output: b d a c

Explanation: 

We will analyze every consecutive pair to find out the order of the characters.

The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.

The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.

The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.

The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.

So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

Example 2:
Input: N = 3, K = 3, dict = ["caa","aaa","aab"]

Output: c a b

Explanation: Similarly, if we analyze the consecutive pair 

for this example, we will figure out [‘c’, ‘a’, ‘b’] is 

a valid ordering.
*/


class Solution {
public:

    string findOrder(string dict[], int N, int K) {

        vector<vector<int>> adj(K);

        // 1. Build directed graph
        for(int i = 0; i < N - 1; i++) {

            string word1 = dict[i];
            string word2 = dict[i + 1];

            int len = min(word1.size(), word2.size());

            for(int j = 0; j < len; j++) {

                if(word1[j] != word2[j]) {

                    int u = word1[j] - 'a';
                    int v = word2[j] - 'a';

                    adj[u].push_back(v);

                    break;
                }
            }
        }

        // 2. Calculate indegree
        vector<int> indegree(K, 0);

        for(int u = 0; u < K; u++) {

            for(int v : adj[u]) {

                indegree[v]++;
            }
        }

        // 3. Put nodes with indegree 0 into queue
        queue<int> q;

        for(int i = 0; i < K; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // 4. Topological sort
        string ans = "";

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for(int neighbour : adj[node]) {

                indegree[neighbour]--;

                if(indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // 5. Cycle detected / invalid ordering
        if(ans.size() != K) {
            return "";
        }

        return ans;
    }
};