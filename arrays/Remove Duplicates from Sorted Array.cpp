class Solution {
public:
    // here we are taking extra space hash map
    // int removeDuplicates(vector<int>& nums) {
    //     unordered_map<int,int>mp;
    //     int index=0;
    //     for(int i=0;i<nums.size();i++){
    //         if(mp.find(nums[i])==mp.end()){
    //             mp[nums[i]]=1;
    //             nums[index]=nums[i];
    //             index++;
    //         }
    //     }
    //     return index;
    // }

    //without extra space
    int removeDuplicates(vector<int>& nums) {
        int k=1;

        for(int i=1;i<nums.size();i++){
            if(nums[k-1]!=nums[i]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};