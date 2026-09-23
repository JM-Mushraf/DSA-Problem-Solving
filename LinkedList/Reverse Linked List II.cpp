/*

Code
Testcase
Testcase
Test Result


92. Reverse Linked List II
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right)return head;

        ListNode*dummy=new ListNode();
        dummy->next=head;

        //find prevLeft one before the actual left sublist
        ListNode*prevleft=dummy;
        ListNode*curr=head;
        for(int i=1;i<left;i++){
            prevleft=curr;
            curr=curr->next;
        }

        //similarlly find prev Right
        ListNode*prevright=prevleft;
        for(int i=left;i<=right;i++){
            prevright=prevright->next;
        }

        //break connection from end to reverse the sublist
        ListNode*tail=prevright->next;
        prevright->next=nullptr;

        //reverse the sublist
        ListNode*newhead=nullptr;
        ListNode*newtail=nullptr;

        while(curr){
            ListNode*temp=curr->next;
            curr->next=newhead;
            newhead=curr;
            if(newtail==nullptr){
                newtail=newhead;
            }
            curr=temp;
        }

        prevleft->next=newhead;
        newtail->next=tail;

        //if the reversal starts at the very first node
        if(left==1){
            head=newhead;
        }
        delete dummy;
        return head;
    }
};

// link:https://leetcode.com/problems/reverse-linked-list-ii/