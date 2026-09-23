/*
387. First Unique Character in a String
Solved
Easy
Topics
premium lock icon
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> mp; // {index, count}
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second++;
            } else {
                mp[s[i]] = {i, 1};
            }
        }

        int ans = n; // large number
        for (auto &p : mp) {
            if (p.second.second == 1) {
                ans = min(ans, p.second.first);
            }
        }

        return (ans == n) ? -1 : ans;
    }
};
