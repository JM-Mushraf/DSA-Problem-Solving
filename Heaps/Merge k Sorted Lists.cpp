/*
23. Merge k Sorted Lists
Solved
Hard
Topics
Companies
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
*/

// code:-
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    struct compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val; // min-heap
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> min_heap;

        int k = lists.size();
        if (k == 0)
            return nullptr;
        // step 1 push head of k LL
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != nullptr)
            {
                min_heap.push(lists[i]);
            }
        }

        // step2
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (min_heap.size() > 0)
        {
            ListNode *top = min_heap.top();
            min_heap.pop();

            if (top->next != nullptr)
            {
                min_heap.push(top->next);
            }
            if (head == NULL)
            {
                head = tail = top;
                // if(tail->next!=NULL){
                //     min_heap.push(tail.next);
                // }
            }
            else
            {
                tail->next = top;
                // if(tail->next!=NULL){//instead of writing this condition twice we'll write once in top
                //     min_heap.push(tail.next);
                // }
                tail = top;
            }
        }
        return head;
    }
};

// prob link:-https://leetcode.com/problems/merge-k-sorted-lists/