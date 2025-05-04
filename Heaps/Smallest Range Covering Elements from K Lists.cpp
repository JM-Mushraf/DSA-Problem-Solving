/*
632. Smallest Range Covering Elements from K Lists
Solved
Hard
Topics
Companies
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
*/

// code:-
// returning range array
class Solution {
    public:
    class node{
        public:
            int data;
            int row;
            int col;
            node(int d,int r,int c){
                data=d;
                row=r;
                col=c;
            }
    };
    class compare{
        public:
            bool operator()(node*a,node*b){
                return a->data > b->data;
            }
    };
    vector<int> smallestRange(vector<vector<int>>& a) {
        int k=a.size();
        int n=a[0].size();
        int mini=INT_MAX,maxi=INT_MIN;
        vector<int>ans;
        priority_queue<node*,vector<node*>,compare>min_heap;

        //step1 insert first elements of all k lists
        for(int i=0;i<k;i++){
            mini=min(mini,a[i][0]);
            maxi=max(maxi,a[i][0]);

            min_heap.push(new node(a[i][0],i,0));
        }

        int start=mini;
        int end=maxi;
        //step2
        while(!min_heap.empty()){
            node*temp=min_heap.top();
            min_heap.pop();

            //update mini
            mini=temp->data;
            //track range
            if(maxi-mini < end-start){
                start=mini;
                end=maxi;
            }
            //track max
            if(temp->col+1 < a[temp->row].size()){
                maxi=max(maxi,a[temp->row][temp->col+1]);
                min_heap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
            }
            else{
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

//returning the range difference (end-start+1)
#include <bits/stdc++.h> 
class node{
    public:
        int data;
        int row;
        int col;
        node(int d,int r,int c){
            data=d;
            row=r;
            col=c;
        }
};
class compare{
    public:
        bool operator()(node*a,node*b){
            return a->data > b->data;
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<node*,vector<node*>,compare>min_heap;

    //step1 insert first elements of all k lists
    for(int i=0;i<k;i++){
        mini=min(mini,a[i][0]);
        maxi=max(maxi,a[i][0]);

        min_heap.push(new node(a[i][0],i,0));
    }

    int start=mini;
    int end=maxi;
    //step2
    while(!min_heap.empty()){
        node*temp=min_heap.top();
        min_heap.pop();

        //update mini
        mini=temp->data;
        //track range
        if(maxi-mini < end-start){
            start=mini;
            end=maxi;
        }
        //track max
        if(temp->col+1<n){
            maxi=max(maxi,a[temp->row][temp->col+1]);
            min_heap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return end-start+1;
}
// prob link:https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ and https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTabValue=SUBMISSION