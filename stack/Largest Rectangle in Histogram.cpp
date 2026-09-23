/*
84. Largest Rectangle in Histogram
Solved
Hard
Topics
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
-return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/

// code:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea=0;
        int n=heights.size();
        int nse=0,pse=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ind=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea=max(maxArea,(heights[ind]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind=st.top();
            st.pop();
            nse=n;
            pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,(heights[ind]*(nse-pse-1)));
        }
        return maxArea;
    }
};
// prob link:https://leetcode.com/problems/largest-rectangle-in-histogram/?envType=problem-list-v2&envId=stack