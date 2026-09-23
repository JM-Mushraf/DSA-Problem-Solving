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
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || head->next==nullptr)return head;
    //     ListNode*ptr1=head;
    //     ListNode*ptr2=head->next;
    //     ListNode*ptr3;
    //     while(ptr2!=nullptr){
    //         ptr3=ptr2->next;

    //         ptr2->next=ptr1;
    //         ptr1=ptr2;
    //         ptr2=ptr3;
    //     }
    //     head->next=nullptr;
    //     head=ptr1;
    //     return head;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*next;
        ListNode*prev=nullptr;

        while(curr!=nullptr){
            next=curr->next;
            
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
};

// Link:https://leetcode.com/problems/reverse-linked-list/