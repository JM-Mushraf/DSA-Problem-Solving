/*
49. Group Anagrams
Solved
Medium
Topics
Companies
Given an array of strings strs, group the anagrams together. You can return the answer in any order.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]
*/

// code:
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;

        for (string &word : strs)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            m[sorted_word].push_back(word);
        }
        vector<vector<string>> res;
        for (auto i : m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};

// prob link:https://leetcode.com/problems/group-anagrams/submissions/1631090561/?envType=problem-list-v2&envId=hash-table