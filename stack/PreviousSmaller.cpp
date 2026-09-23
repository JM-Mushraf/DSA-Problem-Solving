#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// vector<int> prevSmallerElement(vector<int>& nums){
//     stack<pair<int,int>> st;
//     int n = nums.size();
//     vector<int> ans(n, -1);
//     for(int i = n - 1; i >= 0; i--){
//         while(!st.empty() && nums[i] < st.top().first){
//             auto temp = st.top();
//             ans[temp.second] = nums[i];
//             st.pop();
//         }
//         st.push({nums[i], i});
//     }
//     return ans;
// }

vector<int> prevSmallerElement(vector<int>& nums){
    stack<int>st;
    int n=nums.size();
    vector<int>prev_min(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]<nums[st.top()]){
            st.pop();
        }
        prev_min[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return prev_min;
}

int main()
{
    vector<int> nums = {4,5,2,10,8};
    vector<int> result = prevSmallerElement(nums);

    cout << "Next smaller elements: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
