/*
205. Isomorphic Strings
Solved
Easy
Topics
Companies
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true
*/

// code:
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.length(); i++)
        {
            char c1 = s[i];
            char c2 = t[i];

            // check if c1 is already mapped
            if (s_to_t.count(c1))
            {
                // if c1 is mapping to something else then return false
                if (s_to_t[c1] != c2)
                    return false;
            }
            else
            {
                s_to_t[c1] = c2;
            }

            // check if c2 is already used by some other char
            if (t_to_s.count(c2))
            {
                if (t_to_s[c2] != c1)
                    return false;
            }
            else
            {
                t_to_s[c2] = c1;
            }
        }
        return true;
    }
};

// prob link:https://leetcode.com/problems/isomorphic-strings/?envType=problem-list-v2&envId=hash-table