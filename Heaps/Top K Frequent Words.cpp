/*
692. Top K Frequent Words
Solved
Medium
Topics
Companies
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.



Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
*/

// code:
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> f;
        for (auto &i : words)
        {
            f[i]++;
        }
        auto cmp = [](const pair<int, string> &a, const pair<int, string> &b)
        {
            // If frequency is equal, return alphabetically earlier word first
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first; // higher frequency comes first
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> max_heap(cmp);
        for (auto &i : f)
        {
            max_heap.push({i.second, i.first});
        }
        vector<string> res;
        for (int i = 1; i <= k; i++)
        {
            auto ans = max_heap.top();
            res.push_back(ans.second);
            max_heap.pop();
        }
        return res;
    }
};

// prob link:https://leetcode.com/problems/top-k-frequent-words/?envType=problem-list-v2&envId=heap-priority-queue