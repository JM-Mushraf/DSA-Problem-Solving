/*
234. Palindrome Linked List
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

// code:
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
         // An empty list or a single-node list is considered a palindrome
        if(head==nullptr || head->next==nullptr)return true;

        // Find the middle of the linked list using slow and fast pointers
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=nullptr;
        ListNode*temp;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;

            //while advancing slow  Reverse the first half of the linked list
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

         // If the total number of nodes is odd, move slow to the next node
        if(fast!=nullptr){
            slow=slow->next;
        }
        // Compare the reversed first half with the second half
        while(prev!=nullptr && slow!=nullptr){
            if(prev->val!=slow->val)return false; // Values don't match, not a palindrome
            prev=prev->next;
            slow=slow->next;
        }
        // If we reach here, the linked list is a palindrome
        return true;
    }
};

// link:https://leetcode.com/problems/palindrome-linked-list/  