/*
703. Kth Largest Element in a Stream
Solved
Easy
Topics
Companies
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.


Example 1:

Input:
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output: [null, 4, 5, 5, 8, 8]
*/

// code:
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int num : nums)
        {
            min_heap.push(num);
            if (min_heap.size() > k)
            {
                min_heap.pop();
            }
        }
    }

    int add(int val)
    {
        if (min_heap.size() < k)
        {
            min_heap.push(val);
        }
        else if (val > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//  prob link:https://leetcode.com/problems/kth-largest-element-in-a-stream/?envType=problem-list-v2&envId=heap-priority-queue