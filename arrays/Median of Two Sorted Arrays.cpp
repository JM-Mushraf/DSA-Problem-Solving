/*
4. Median of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

// code:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n+m);
        
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                i++;
                k++;
            }else{
                ans[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<n){
            ans[k]=nums1[i];
            i++;
            k++;            
        }
        while(j<m){
            ans[k]=nums2[j];
            j++;
            k++;
        }

        if((n+m)%2!=0){
            return ans[(m + n) / 2];
        }else{
            int x=(m + n) / 2;
            int p=ans[x];
            int q=ans[x-1];
            return (p + q) / 2.0;
        }
    }
};

// link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/