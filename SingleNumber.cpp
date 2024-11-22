
// 136. Single Number
#include <iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int> &nums){
    int res=0;
    for(int num:nums)
    {
        res=res^num;
    }
    return res;
}
int main()
{
    vector<int>nums={4,1,2,1,2};
    cout<<"res:"<<singleNumber(nums);
    return 0;
}