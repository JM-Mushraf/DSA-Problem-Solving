/*
767. Reorganize String
Solved
Medium
Topics
Companies
Hint
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

// code:
class Solution
{
public:
    string reorganizeString(string s)
    {
        // step1:store frequencies in u_map
        unordered_map<char, int> f;

        for (char c : s)
        {
            f[c]++;
        }

        // step2:initilize max heap to store frequencies of chars and chars
        priority_queue<pair<int, char>> max_heap;
        for (auto &ele : f)
        {
            max_heap.push({ele.second, ele.first});
        }

        // step3:build result
        string res = "";
        pair<int, char> prev = {0, '#'}; // initially no element

        while (!max_heap.empty())
        {
            auto curr = max_heap.top();
            max_heap.pop();

            res += curr.second;

            // check if there is a prev element with freq>0
            if (prev.first > 0)
            {
                max_heap.push(prev);
            }

            // decrease curr frequency by 1
            curr.first--;
            // update prev
            prev = curr;
        }

        if (res.length() == s.length())
        {
            return res;
        }
        return "";
    }
};

// prob link:https://leetcode.com/problems/reorganize-string/