/*
242. Valid Anagram
Solved
Easy
Topics
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.



Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false
*/

// code:
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> f;
        for (auto i : s)
        {
            f[i]++;
        }

        for (auto i : t)
        {
            if (f.count(i) == 0 || f[i] == 0)
            {
                return false;
            }
            f[i]--;
        }
        return true;
    }
};

// prob link:https://leetcode.com/problems/valid-anagram/?envType=problem-list-v2&envId=hash-table