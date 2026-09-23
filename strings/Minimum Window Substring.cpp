// 76. Minimum Window Substring
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s and t of lengths m and n respectively, 
//return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
//If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

// code:
class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,startInd=-1,minlen=1e9,cnt=0;
        vector<int>hash(256,0);
        int m=t.size(),n=s.size();

        //start freq's of all t chars
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        //traverse through s array to find minimum window
        while(r<n){
            if(hash[s[r]]>0){
                cnt+=1;
            }
            hash[s[r]]--;

            while(cnt==m){
                if(minlen > r-l+1){
                    minlen=r-l+1;
                    startInd=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt-=1;
                l++;
            }
            r++;
        }
        return startInd==-1 ? "" : s.substr(startInd,minlen);
    }
};
// link: https://leetcode.com/problems/minimum-window-substring/description/