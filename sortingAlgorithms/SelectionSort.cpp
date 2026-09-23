#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;

        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
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
    SelectionSort(arr,n);
    for (int x : arr) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}


/*
Complexity

Selection Sort always searches the remaining unsorted portion.

Even if the array is already sorted:

[1, 2, 3, 4, 5]

it still searches for the minimum.

Therefore:

Best case
O(n²)
Average case
O(n²)
Worst case
O(n²)

Unlike optimized Bubble Sort and Insertion Sort, Selection Sort does not become O(n) for an already-sorted array.


Space Complexity

It sorts inside the same array:

O(1)

So it's in-place.

Is Selection Sort stable?

Here's an important detail:

Standard Selection Sort is NOT stable.

Why?

Consider:

[4A, 2, 4B, 1]

First minimum is 1.

We swap:

[1, 2, 4B, 4A]

Originally:

4A before 4B

Now:

4B before 4A

Their relative order changed.

Therefore:

Stable ❌
In-place ✅
*/