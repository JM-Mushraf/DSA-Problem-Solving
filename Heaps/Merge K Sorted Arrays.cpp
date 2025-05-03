/*
Problem statement
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
1 <= K <= 5
1 <= N <= 20
-10^5 <= DATA <= 10^5

Time Limit: 1 sec 
Sample Input 1:
1
2
3 
3 5 9 
4 
1 2 3 8   
Sample Output 1:
1 2 3 3 5 8 9 
*/

// code:-
#include <bits/stdc++.h> 
class node{
    public:
    int data;
    int row;
    int col;

    node(int val,int i,int j){
        data=val;
        row=i;
        col=j;
    }
};
class compare{
    public:
    bool operator()(node*a,node*b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare>min_heap;
    vector<int>ans;
    //step1
    for(int i=0;i<k;i++){
        node*temp=new node(kArrays[i][0],i,0);
        min_heap.push(temp);
    }
    //step2
    while(min_heap.size()>0){
        node*temp=min_heap.top();
        ans.push_back(temp->data);
        min_heap.pop();

        int i=temp->row;
        int j=temp->col;

        if(j+1<kArrays[i].size()){
            node*next=new node(kArrays[i][j+1],i,j+1);
            min_heap.push(next);
        }
    }
    return ans;
}
// prob link:-https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTabValue=PROBLEM