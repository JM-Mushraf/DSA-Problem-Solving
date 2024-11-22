#include <iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n,sum,arr_sum=0;
    n=nums.size();
    sum=(n*(n+1))/2;
    for(int i=0;i<nums.size();i++)
    {
        arr_sum+=nums[i];
    }
    return (sum-arr_sum);
}
int main()
{
    vector<int> arr = {9,6,4,2,3,5,7,0,1};
    int res=missingNumber(arr);
    cout<<"Missing number is:"<<res<<endl;
    return 0;
}