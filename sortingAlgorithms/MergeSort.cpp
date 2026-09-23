#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>&arr,int low,int mid,int high){

    int i=low,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }


    for(int k=low;k<=high;k++){
        arr[k]=temp[k-low];
    }
}


void mergeSort(vector<int>&arr,int low,int high){

    if(low>=high)return;

    int mid=low+(high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid,high);
}
int main()
{
    vector<int> arr = {5, 3, 8, 2, 1};
    int n=arr.size();

    cout<<"Before Sorting:"<<endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout<<endl;

    cout<<"After Sorting:"<<endl;
    mergeSort(arr,0,n-1);
    for (int x : arr) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}



/*
Complexity

This is where Merge Sort becomes powerful.

Every time we divide:

n
↓
n/2
↓
n/4
↓
n/8
↓
...
↓
1

The number of levels is approximately:

log₂(n)

At each level, we process all n elements during merging.

Therefore:

O(n log n)

And importantly:

Best    → O(n log n)
Average → O(n log n)
Worst   → O(n log n)

Unlike Bubble, Selection, and Insertion Sort, the worst case doesn't become O(n²)



Space Complexity

We create:

vector<int> temp;

So additional space is:

O(n)

Therefore:

Time  → O(n log n)
Space → O(n)

Is Merge Sort stable?

Yes, if implemented properly.

Notice:

if (arr[i] <= arr[j])

We take the left element first when they're equal.

That preserves their original relative order.

Therefore:

Stable → ✅
*/