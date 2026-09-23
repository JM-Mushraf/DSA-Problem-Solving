/*
203. Remove Linked List Elements
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, 
and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return nullptr;

        while(head!=nullptr && head->val==val){
            ListNode*ptr=head;
            head=head->next;
            delete ptr;
        }
        if(head==nullptr)return nullptr;

        ListNode*curr=head;
        ListNode*prev=nullptr;

        while(curr!=NULL){
            if(curr->val==val){
                prev->next=curr->next;
                curr=prev->next;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};

// Link:https://leetcode.com/problems/remove-linked-list-elements/