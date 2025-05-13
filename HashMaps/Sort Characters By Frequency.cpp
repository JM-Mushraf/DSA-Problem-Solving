/*
451. Sort Characters By Frequency
Solved
Medium
Topics
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

// code:
class Solution
{
public:
    string frequencySort(string s)
    {
        // step1 calculate frequencies
        unordered_map<char, int> f;
        for (auto &c : s)
        {
            f[c]++;
        }

        // Step 2: store in max heap
        priority_queue<pair<int, char>> max_heap;
        for (auto &i : f)
        {
            max_heap.push({i.second, i.first});
        }

        // step3:build ans
        string ans = "";
        while (!max_heap.empty())
        {
            auto ele = max_heap.top();
            int count = ele.first;
            while (count > 0)
            {
                ans += ele.second;
                count--;
            }
            max_heap.pop();
        }
        return ans;
    }
};

// prob link:https://leetcode.com/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=hash-table