/*
Q1. Find All Anagrams in a String
Solved
Medium
Topics
premium lock icon
Companies
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

// code:
class Solution {
public:
    bool isFreqMatch(vector<int>&arr1,vector<int>&arr2){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>pfreq(26,0);
        for(int i=0;i<p.size();i++){
            pfreq[p[i]-'a']++;
        }

        int windowSize=p.size();
        vector<int>res;
        for(int i=0;i<s.size();i++){
            int windowIdx=0,idx=i;
            vector<int>sfreq(26,0);
            while(windowIdx < windowSize && idx<s.size()){
                sfreq[s[idx]-'a']++;
                idx++;
                windowIdx++;
            }
            if(isFreqMatch(pfreq,sfreq)){
                res.push_back(i);
            }
        }
        return res;
    }
};

// link:https://leetcode.com/problems/find-all-anagrams-in-a-string/?envType=problem-list-v2&envId=hash-table