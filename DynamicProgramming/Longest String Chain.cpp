/*1048. Longest String Chain
Solved
Medium
Topics
Companies
Hint
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.



Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].*/

// code:-
class Solution
{
public:
    bool checkPossiable(string &s1, string &s2)
    {

        if (s1.size() != s2.size() + 1)
            return false; // s1 curr str s2 means prev str
        int first = 0;    // for str s1
        int second = 0;   // for str s2

        while (first < s1.size())
        {
            if (s1[first] == s2[second] && second < s2.size())
            {
                first++;
                second++;
            }
            else
            {
                first++; // cause s1 is greater than s2
            }
        }
        if (first == s1.size() && second == s2.size())
            return true;
        return false;
    }
    static bool cmp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string> &words)
    {

        // here they asked for sequence not sub sequence so words can be in any order so we sort according to lengths
        sort(words.begin(), words.end(), cmp);

        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (checkPossiable(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// prob link:-https://leetcode.com/problems/longest-string-chain/