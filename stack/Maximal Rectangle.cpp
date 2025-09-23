/*
85. Maximal Rectangle
Solved
Hard
Topics
Companies
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size(); // rows
        int m = matrix[0].size(); // cols
        int maxArea = 0;

        vector<vector<int>> psum(n, vector<int>(m, 0));

         //traverse through matrix(column)wise to find maxArea
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int val = matrix[i][j] - '0'; // Correct char to int conversion
                sum = (val == 0) ? 0 : sum + 1;
                psum[i][j] = sum;
            }
        }
        //traverse through psum to find maxArea
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxArea=max(maxArea,largestRectangleArea(psum[i]));
            }
        }
        return maxArea;
    }
};

// prob link:https://leetcode.com/problems/maximal-rectangle/?envType=problem-list-v2&envId=stack