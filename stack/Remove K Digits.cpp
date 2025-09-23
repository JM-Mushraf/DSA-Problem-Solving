/*
402. Remove K Digits
Solved
Medium
Topics
Companies
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

Constraints:

1 <= k <= num.length <= 105
num consists of only digits.
num does not have any leading zeros except for the zero itself.
*/

// code:
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && ((st.top()-'0') > (num[i]-'0'))){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty())return "0";

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Remove trailing zeroes (which are actually leading zeroes after reversal)
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if (res.empty()) return "0";

        return res;
    }
};

// prob link:https://leetcode.com/problems/remove-k-digits/?envType=problem-list-v2&envId=stack