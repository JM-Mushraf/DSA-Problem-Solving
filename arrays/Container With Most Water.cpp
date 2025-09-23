/*

Code


Testcase
Testcase
Test Result
11. Container With Most Water
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

// code:
class Solution {
public:
    // tc:O(n2) TLE
    // int maxArea(vector<int>& height) {
    //     int maxWater=0;
    //     int n=height.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             int width=j-i;
    //             int hight=min(height[i],height[j]);
    //             int area=width*hight;
    //             maxWater=max(maxWater,area);
    //         }
    //     }
    //     return maxWater;
    // }

    //TC:O(n)
    //using two pointers
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int n=height.size();
        int lp=0,rp=n-1;

        while(lp < rp){
            int w=rp-lp;
            int h=min(height[lp],height[rp]);

            int area=w*h;
            maxWater=max(maxWater,area);

            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};