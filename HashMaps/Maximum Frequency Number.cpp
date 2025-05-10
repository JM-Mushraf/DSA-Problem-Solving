/*
Problem statement
Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.

If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.

For example,

For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
*/
// code:
int maximumFrequency(vector<int> &arr, int n)
{
    int maxAns=0;
    int maxFreq=0;
    unordered_map<int,int>f;
    for(int i=0;i<n;i++){
        f[arr[i]]++;
        maxFreq=max(maxFreq,f[arr[i]]);
    }
    for(int i=0;i<n;i++){
        if(maxFreq==f[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}

// prob link:https://www.naukri.com/code360/problems/maximum-frequency-number_920319