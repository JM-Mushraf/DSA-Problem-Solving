/*
Problem statement
Given an array 'v' of 'n' numbers.



Your task is to find and return the highest and lowest frequency elements.



If there are multiple elements that have the highest frequency or lowest frequency, pick the smallest element.



Example:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2

Explanation: The element having the highest frequency is '1', and the frequency is 3. The elements with the lowest frequencies are '2', '3', and '4'. Since we need to pick the smallest element, we pick '2'. Hence we return [1, 2].
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
1 2 3 1 1 4
Sample Output 1 :
1 2
Sample Explanation 1:
Input: ‘n' = 6, 'v' = [1, 2, 3, 1, 1, 4]

Output: 1 2
*/

// code:
#include <bits/stdc++.h> 
vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int,int>f;
    int maxf = INT_MIN;  // Maximum frequency
    int minf = INT_MAX;  // Minimum frequency

    // Iterate over the vector to calculate the frequency of each element
    for(int i=0;i<v.size();i++){
        f[v[i]]++;
    }

    for (auto& i : f) {
        maxf = max(maxf, i.second);  // find maximum frequency
        minf = min(minf, i.second);  // find minimum frequency
    }
    vector<int>ans;

    // variables to store the element with the maximum and minimum frequency
    int mxele=INT_MAX;
    int miele=INT_MAX;
    for(auto i:f){
        // If the current element has the max frequency, and it's smaller than the current mxele, update mxele
        if(maxf==i.second && mxele > i.first){
            mxele=i.first;
        }
        // If the current element has the min frequency, and it's smaller than the current miele, update miele
        if(minf==i.second && miele > i.first){
            miele=i.first;
        }
    }
    ans.push_back(mxele);
    ans.push_back(miele);
    return ans;
}
// prob link:https://www.naukri.com/code360/problems/k-most-occurrent-numbers_625382?leftPanelTabValue=PROBLEM