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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* temp=head->next;
         ListNode* prev=head;
        while(temp)
        {
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        head->next=NULL;
        return prev;
    }
};