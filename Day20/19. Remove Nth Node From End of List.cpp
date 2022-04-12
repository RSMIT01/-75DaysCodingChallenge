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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
         ListNode*prev=NULL;
        ListNode *rmv=head;
        int c=0;
        while(temp)
        {
            if(c>=n)
            {
                prev=rmv;
                rmv=rmv->next;
            }
            c++;
            
            temp=temp->next;
        }

         if(prev==NULL) //if we have to remove 1st node
         {
             return head->next;
         }
         prev->next=rmv->next;
        return head;
    }
};