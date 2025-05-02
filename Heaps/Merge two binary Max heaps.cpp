/*
Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
*/

// code:-
void max_heapify(vector<int> &arr,int n,int i){
    int largest=i;
    int leftChild=2*i;
    int rightChild=2*i+1;

    if(leftChild<=n && arr[leftChild]>arr[largest]){
        largest=leftChild;
    }
    if(rightChild<=n && arr[rightChild]>arr[largest]){
        largest=rightChild;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    //step 1 merge two given arrays into single array
    vector<int>ans;
    ans.push_back(-1);
    for(auto i :a){
        ans.push_back(i);
    }
    for(auto i :b){
        ans.push_back(i);
    }
    int size=ans.size()-1;
    //step 3 heapify for the mergred array
    for(int i=size/2;i>0;i--){
        max_heapify(ans,size,i);
    }
    ans.erase(ans.begin());
    return ans;
}

// prob link:-https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1