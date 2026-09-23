#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){// we need n-1 passes for the array of size n
        bool swapped=false;//if the array is already sorted no need to traverse entire array again.
        for(int j=0;j<n-i-1;j++){// in each pass compare the neighbour element and move the large element to the end
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)break;
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
    bubbleSort(arr,n);
    for (int x : arr) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}

/*
Time Complexity
Worst case

Example:
[5, 4, 3, 2, 1]
Lots of comparisons and swaps.
O(n²)

Average case
O(n²)

Best case
Already sorted:
[1, 2, 3, 4, 5]
With the optimization:
O(n)

Without optimization, even the sorted array takes:

O(n²)
*/

/*
Space Complexity

Bubble Sort doesn't need another array.

It swaps elements inside the original array.

Therefore:

Space = O(1)

This is called in-place sorting.
*/

/*
Is Bubble Sort stable?

Yes.

Suppose:

(5,A) (5,B)

We don't swap equal elements because:

arr[j] > arr[j + 1]

not:

arr[j] >= arr[j + 1]

Therefore their relative order remains:

(5,A) (5,B)

So Bubble Sort is:

Stable ✅
In-place ✅
*/