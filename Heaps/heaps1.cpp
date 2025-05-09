#include<iostream>
#include<vector>
#include<queue>
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
void maxHeapSort(int *arr,int n){
    int t=n;
    while(t>1){
        //step1
        swap(arr[1],arr[t]);
        //step2
        t--;
        // step3
        max_heapify(arr,t,1);
    }
}
//for 0 base indexing
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

    cout<<"Printing sorted heap"<<endl;
    maxHeapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    //heaps using priority_queue
    cout<<"------------heap using priority_queue------------"<<endl;
    cout<<"max heap"<<endl;
    priority_queue<int>max_heap;//max_heap

    max_heap.push(4);
    max_heap.push(2);
    max_heap.push(5);
    max_heap.push(3);

    cout<<max_heap.top()<<endl;
    max_heap.pop();
    cout<<max_heap.top()<<endl;
    if(max_heap.empty()){
        cout<<"priority_queue is empty"<<endl;
    }else{
        cout<<"priority_queue is not empty"<<endl;
    }

    // min heap
    cout<<"min heap"<<endl;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    min_heap.push(4);
    min_heap.push(2);
    min_heap.push(5);
    min_heap.push(3);

    cout<<min_heap.top()<<endl;
    min_heap.pop();
    cout<<min_heap.top()<<endl;
    if(min_heap.empty()){
        cout<<"priority_queue is empty"<<endl;
    }else{
        cout<<"priority_queue is not empty"<<endl;
    }
    return 0;
}