/*
131. Palindrome Partitioning
Solved
Medium
Topics
Companies
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters
*/
// code:-
class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void f(int i, string s, int n, vector<string> &path, vector<vector<string>> &res)
    {
        if (i == n)
        {
            res.push_back(path);
            return;
        }
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                path.push_back(s.substr(i, j - i + 1)); // j-i+1 to calculate lenth of palindrome str if i=0 and j=1 for aab then len=2
                f(j + 1, s, n, path, res);
                path.pop_back(); // back track
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<string> path;
        vector<vector<string>> res;
        f(0, s, n, path, res);
        return res;
    }
};
// prob link:-https://leetcode.com/problems/palindrome-partitioning/