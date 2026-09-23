/*
1. Two Sum
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int compliment=target-nums[i];
            if(mp.find(compliment)!=mp.end()){
                return {mp[compliment],i};
            }
            mp[nums[i]]=i;
        }
        return{};
    }
};


// optimal solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>numsWithIndex;

        for(int i=0;i<nums.size();i++){
            numsWithIndex.push_back({nums[i],i});
        }
        sort(numsWithIndex.begin(),numsWithIndex.end());
        int left=0,right=nums.size()-1;

        while(left<right){
            int sum=numsWithIndex[left].first+numsWithIndex[right].first;
            if(sum==target){
                return {numsWithIndex[left].second , numsWithIndex[right].second};
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
        return {-1,-1};
    }
};