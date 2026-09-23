/*
14. Longest Common Prefix
Solved
Easy
Topics
premium lock icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

// code:
class Solution {
public:

// ertical Scanning (Most Common)

// Compare characters column by column.

// Idea
// Take the first string.
// For each character in it:
// Check whether every other string has the same character at that position.
// If not, return the prefix up to that point.
// Example
// flower
// flow
// flight

// Compare:

// f ✓ ✓ ✓
// l ✓ ✓ ✓
// o ✓ ✓ ✗

// Answer = "fl"
//     string longestCommonPrefix(vector<string>& strs) {
//         if(strs.empty())return "";

//         for(int i=0;i<strs[0].size();i++){
//             char ch=strs[0][i];

//             for(int j=1;j<strs.size();j++){
//                 if(i>=strs[j].size() || strs[j][i]!=ch){
//                     return strs[0].substr(0,i);
//                 }
//             }
//         }
//         return strs[0];
//     }


// Sort the Array
// Observation

// After sorting,

// the most different strings become the first and last.

// The common prefix of these two is the answer.

// Example:

// before sorting

// flower
// flow
// flight

// after sorting

// flight
// flow
// flower

// Only compare:

// flight
// flower

// Common prefix = "fl"
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";

        sort(strs.begin(),strs.end());

        string first=strs.front();
        string last=strs.back();

        int i=0;
        while(i<first.size() && i<last.size() && first[i]==last[i]){
            i++;
        }
        return first.substr(0,i);
    }
};