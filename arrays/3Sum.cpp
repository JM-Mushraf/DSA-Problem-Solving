/*
question:
    15. 3Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.





theory:
What the problem wants (in plain words)

From an array, find all unique triplets (a, b, c) whose sum is 0.

“Unique” means no duplicate triplets like [-1,0,1] appearing twice.

Indices must be different, but the order of numbers in a triplet doesn’t matter.

Why sorting helps

If the array is sorted, then:

When the sum is too small, moving the left pointer right increases the sum.

When the sum is too big, moving the right pointer left decreases the sum.
This lets us find matches in O(n²) instead of brute-force O(n³).

The recipe (Sorting + Two Pointers)

Sort the array.

Loop i from 0 to n-1 (this picks the first number of the triplet):

If i > 0 and nums[i] == nums[i-1], skip (avoid duplicate first elements).

For this fixed nums[i], set two pointers:

left = i + 1, right = n - 1

While left < right:

sum = nums[i] + nums[left] + nums[right]

If sum == 0: record the triplet, then skip duplicates of nums[left] and nums[right], and move both.

If sum < 0: need a bigger sum → left++

If sum > 0: need a smaller sum → right--

Dry run on the classic example

nums = [-1,0,1,2,-1,-4]
Sort → [-4,-1,-1,0,1,2]

i = 0 (-4), left=1, right=5

sum = -4 + (-1) + 2 = -3 < 0 → left++

sum = -4 + (-1) + 2 = -3 < 0 → left++

sum = -4 + 0 + 2 = -2 < 0 → left++

sum = -4 + 1 + 2 = -1 < 0 → left++ → left == right (stop)

i = 1 (-1), left=2, right=5

sum = -1 + (-1) + 2 = 0 ✅ push [-1,-1,2]

skip dup left/right (left→3, right→4)

sum = -1 + 0 + 1 = 0 ✅ push [-1,0,1]

move left/right → left=4, right=3 (stop)

i = 2 is -1 again → skip (duplicate first)

i = 3 (0), left=4, right=5

sum = 0 + 1 + 2 = 3 > 0 → right-- → left==right (stop)

Answer: [[-1,-1,2], [-1,0,1]].
*/

// code:
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;

            int left=i+1,right=n-1;
            while(left < right){
                long long sum=(long long) nums[i]+nums[left]+nums[right];

                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});

                    int leftval=nums[left],rightval=nums[right];

                    while(left < right && nums[left]==leftval)left++;
                    while(right > left && nums[right]==rightval)right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res;
    }
};