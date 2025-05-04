/*Problem statement
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 10^4
0 <= data <= 10^8
Where T is the number of test cases, N is the number of elements in the data stream.

Time Limit : 1 sec
Sample Input 1:
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:
1 1 2
9 9 
4 
Explanation for Sample Input 1:
For test case 1 
After reading first element of stream , Median of [1] is 1 
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2.
Sample Input 2:
2
3
5 3 8
2
3 8
Sample Output 2:
5 4 5
3 5
Explanation for Sample Input 2:
For test case 1 
After reading first element of stream, Median of [5] is 5
After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
So the output will be 5 4 5.
*/

// Code:
#include <bits/stdc++.h> 
int signum(int a,int b){
	if(a==b)return 0;
	else if(a>b)return 1;
	else return -1;
}
void call_median(int element,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini,int &median){
	switch(signum(maxi.size(),mini.size())){
		case 0: //maxi.size()=mini.size()
			if(element>median){
				mini.push(element);
				median=mini.top();
			}
			else{
				maxi.push(element);
				median=maxi.top();
			}
			break;
		case 1: //maxi.size()>mini.size()
			if(element>median){
				mini.push(element);
				median=(maxi.top()+mini.top())/2;
			}
			else{
				mini.push(maxi.top());
				maxi.pop();
				maxi.push(element);
				median=(maxi.top()+mini.top())/2;
			}
			break;
		case -1: //maxi.size()<mini.size()
			if(element>median){
				maxi.push(mini.top());
				mini.pop();
				mini.push(element);
				median=(maxi.top()+mini.top())/2;
			}
			else{
				maxi.push(element);
				median=(maxi.top()+mini.top())/2;
			}
			break;
	}
}
vector<int> findMedian(vector<int> &arr, int n){
	vector<int>ans;
	priority_queue<int>max_heap;
	priority_queue<int,vector<int>,greater<int>>min_heap;
	int median=0;
	for(int i=0;i<n;i++){
		call_median(arr[i],max_heap,min_heap,median);
		ans.push_back(median);
	}
	return ans;
}


// prob link:https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTabValue=PROBLEM