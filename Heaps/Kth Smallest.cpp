/*Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4
Output: 15
Explanation: 4th smallest element in the given array is 15.*/

// Code:-
class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        int n = arr.size();

        priority_queue<int> pq;
        // step1:create max heap for k elements
        for (int i = 0; i < k; i++)
        {
            pq.push(arr[i]);
        }

        // step2:compare reamining elements with heap top
        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }

        // step 3:ans =heap.top();
        int ans = pq.top();
        return ans;
    }
};

// prob link:-https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1