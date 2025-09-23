/*
907. Sum of Subarray Minimums
Solved
Medium
Topics
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
*/

// code:
class Solution {
public:
    vector<int>prev_min(vector<int>&arr){
        int n=arr.size();
        vector<int>prev(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            prev[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return prev;
    }
    vector<int>next_min(vector<int>&arr){
        int n=arr.size();
        vector<int>next(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            next[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return next;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        long long res=0;
        int n=arr.size();

        vector<int>prevmin=prev_min(arr);
        vector<int>nextmin=next_min(arr);

        for(int i=0;i<n;i++){
            long long left=i-prevmin[i];
            long long right=nextmin[i]-i;
            res=(res+(left*right*arr[i])%mod)%mod;
        }
        return (int)res;
    }
};

// prob link:https://leetcode.com/problems/sum-of-subarray-minimums/?envType=problem-list-v2&envId=stack