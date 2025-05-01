#include<iostream>
#include<vector>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    //insertion in max heap
    void insert(int val){
        size++;
        int ind=size;
        arr[ind]=val;
        while(ind>1){
            int parent=ind/2;
            if(arr[parent]<arr[ind]){
                swap(arr[parent],arr[ind]);
                ind=parent;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //step1 swap root with last element
        arr[1]=arr[size];
        //step2 delete last element
        size--;
        int ind=1;
        while(ind<size){
            int leftChild=2*ind;
            int rightChild=2*ind+1;
            if(leftChild<size && arr[leftChild]>arr[ind]){
                swap(arr[leftChild],arr[ind]);
                ind=leftChild;
            }
            else if(rightChild<size && arr[rightChild]>arr[ind]){
                swap(arr[rightChild],arr[ind]);
                ind=rightChild;
            }
            else{
                return;
            }
        } 
    }
};

void max_heapify(int *arr,int n,int i){
    int largest=i;
    int leftChild=2*i;
    int rightChild=2*i+1;

    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest=leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[largest]){
        largest=rightChild;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

//for 0 base indexing
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
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.print();
    h.deleteFromHeap();
    h.print();

    int arr[6]={-1,54,53 ,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        max_heapify(arr,n,i);
    }
    cout<<"printing array after heapify"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}