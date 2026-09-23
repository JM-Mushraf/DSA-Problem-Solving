/*
567. Permutation in String
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

// code:
class Solution {
public:
    bool isFreqMatch(int*arr1,int*arr2){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }

        int windowSize=s1.size();

        for(int i=0;i<s2.size();i++){
            int windowIdx=0,idx=i;
            int windEleFreq[26]={0};

            while(windowIdx < windowSize  && idx<s2.size()){
                windEleFreq[s2[idx]-'a']++;
                windowIdx++;
                idx++;
            }

            if(isFreqMatch(freq,windEleFreq)){
                return true;
            }
        }
        return false;
    }
};

// prob link: https://leetcode.com/problems/permutation-in-string/