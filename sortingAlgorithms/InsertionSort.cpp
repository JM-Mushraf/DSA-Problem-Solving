#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
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
    insertionSort(arr,n);
    for (int x : arr) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}


/*
Worst case
Reverse sorted:
[5, 4, 3, 2, 1]
Every new element has to move all the way to the beginning.
O(n²)

Average case
O(n²)

Best case

Already sorted:
[1, 2, 3, 4, 5]
Each key only needs one comparison.
O(n)

Space
No extra array:
O(1)



Is Insertion Sort stable?
Yes.
Because we use:
arr[j] > key
rather than:
arr[j] >= key
Equal elements aren't unnecessarily moved past each other.
*/