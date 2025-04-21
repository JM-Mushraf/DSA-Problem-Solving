/*Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.
Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
*/

// code:-
class Solution
{
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
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
    int minInsertions(string s)
    {
        int res = s.size() - longestPalindromeSubseq(s);
        return res;
    }
};

// prob link:-https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/