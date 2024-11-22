#include<iostream>
using namespace std;

void countSort(int* arr, int n)
{
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;  // Initialize all count values to 0
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                count[i]++;
            }
        }
    }
    int output[n];
    for (int i = 0; i < n; i++)
    {
       output[count[i]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
       arr[i] = output[i];
    }
}

void printArray(int *arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[]={1,3,5,2,7};
    cout<<"before Sorting:"<<endl;
    printArray(arr,5);
    countSort(arr,5);
    cout<<"after Sorting:"<<endl;
    printArray(arr,5);
    return 0;
}