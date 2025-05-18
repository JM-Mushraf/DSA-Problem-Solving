#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>& nums){
    stack<pair<int,int>> st;
    int n = nums.size();
    vector<int> ans(n, -1);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[i] < st.top().first){
            auto temp = st.top();
            ans[temp.second] = nums[i];
            st.pop();
        }
        st.push({nums[i], i});
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,5,2,10,8};
    vector<int> result = nextSmallerElement(nums);

    cout << "Next smaller elements: ";
    for(int x : result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
