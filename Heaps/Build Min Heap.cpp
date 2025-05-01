/*Problem statement
You are given an array 'ARR' of integers having 'N' elements. Your task is to convert the input array into a min-Binary Heap.

A min-Binary heap is a complete binary tree in which the value of each internal node is smaller than or equal to the values of the children of that node.

Note :
1. Input array follows 0 - based indexing. 

2. After constructing the min-heap, the Left child of the 'i-th' node should be present at the (2*i + 1)-th index if it exists.

3. After constructing the min-heap, the Right child of the 'i-th' node should be present at the (2*i + 2)-th index if it exists.

4. Note that you do not need to create a tree, just update the array.
Detailed explanation ( Input/output format, Notes, Images )*/

// code:-
#include <bits/stdc++.h> 
void minHeapify(vector<int>&arr,int i,int n){
    int smallest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    if(leftChild<n && arr[leftChild]<arr[smallest]){
        smallest=leftChild;
    }
    if(rightChild<n && arr[rightChild]<arr[smallest]){
        smallest=rightChild;
    }

    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,smallest,n);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{   
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        minHeapify(arr,i,n);
    }
    return arr;
}


// prob link:-https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTabValue=PROBLEM