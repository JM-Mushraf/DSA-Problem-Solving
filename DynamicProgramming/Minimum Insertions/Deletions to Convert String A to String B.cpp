/*Delete Operation for Two Strings
583. Delete Operation for Two Strings
Solved
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
*/

// code:-
class Solution {
    public:
        // space optimization Longest Common Subsequence
        int longestCommonSubsequence(string text1, string text2)
        {
            int n = text1.size();
            int m = text2.size();
            vector<int> prev(m + 1, 0);
            vector<int> curr(m + 1, 0);
            // baseCase
            for (int ind2 = 0; ind2 <= m - 1; ind2++)
                prev[ind2] = 0;
    
            for (int ind1 = 1; ind1 <= n; ind1++)
            {
                for (int ind2 = 1; ind2 <= m; ind2++)
                {
                    // match
                    if (text1[ind1 - 1] == text2[ind2 - 1])
                    {
                        curr[ind2] = 1 + prev[ind2 - 1];
                    }
                    else
                    {
                        // no match
                        curr[ind2] = 0 + max(prev[ind2], curr[ind2 - 1]);
                    }
                }
                prev = curr;
            }
            return prev[m];
        }
        int minDistance(string word1, string word2) {
            //by formula as used in theory 
            int res=word1.size()+word2.size()-2*longestCommonSubsequence(word1, word2);
            return res;
        }
    };

    // prob link:-https://leetcode.com/problems/delete-operation-for-two-strings/