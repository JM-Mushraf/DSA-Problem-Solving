// Question:GIven an array of distinct integers return all the possiable permutations

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private: 
    void backtrack(vector<vector<int>> &resultList, vector<int> &tempList, const vector<int> &nums)
    {
        if (tempList.size() == nums.size())
        {
            resultList.push_back(tempList);
            return;
        }
        for (int number : nums)
        {
            if (find(tempList.begin(), tempList.end(), number) != tempList.end())
            {
                continue;
            }
            tempList.push_back(number);

            backtrack(resultList, tempList, nums);

            tempList.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> tempList;
        backtrack(result, tempList, nums);
        return result;
    }
};
int main()
{
    Solution obj1;
    vector<int> list = {1, 2, 3};
    vector<vector<int>> result;
    result = obj1.permute(list);
    int count = 0;
    // Printing the result to verify
    for (const auto &permutation : result)
    {
        for (int num : permutation)
        {
            cout << num << " ";
        }
        count++;
        cout << endl;
    }
    cout << "Total permutations:" << count;
    return 0;
}