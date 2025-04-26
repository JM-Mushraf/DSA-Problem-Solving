/*Problem statement
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.



A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.



For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.



You are given an array 'arr' consisting of 'n' positive integers.



Find the length of the longest bitonic subsequence of 'arr'.



Example :
Input: 'arr' = [1, 2, 1, 2, 1]*/

// Code:-
#include <bits/stdc++.h> 
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	//forward LIS calculation
	vector<int>dp1(n,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && 1+dp1[j]>dp1[i]){
				dp1[i]=1+dp1[j];
			}
		}
	}

	//backward LIS calculation
	vector<int>dp2(n,1);
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j] && 1+dp2[j]>dp2[i]){
				dp2[i]=1+dp2[j];
			}
		}
	}

	//bitonic calculation
	int maxi=0;
	for(int i=0;i<n;i++){
		maxi=max(maxi,dp1[i]+dp2[i]-1);
	}
	return maxi;
}
// prob link:-https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM