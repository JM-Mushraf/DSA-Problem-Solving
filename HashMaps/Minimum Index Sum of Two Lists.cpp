/*
599. Minimum Index Sum of Two Lists
Solved
Easy
Topics
Companies
Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.



Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
Example 3:

Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
*/

// code:
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> indexMap;

        for (int i = 0; i < list1.size(); i++)
        {
            indexMap[list1[i]] = i;
        }

        int min = INT_MAX;
        vector<string> res;

        for (int i = 0; i < list2.size(); i++)
        {
            if (indexMap.count(list2[i]))
            {
                int sum = i + indexMap[list2[i]];

                if (min > sum)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    min = sum;
                }
                else if (sum == min)
                {
                    res.push_back(list2[i]);
                }
            }
        }
        return res;
    }
};
// prob link:https://leetcode.com/problems/minimum-index-sum-of-two-lists/?envType=problem-list-v2&envId=hash-table