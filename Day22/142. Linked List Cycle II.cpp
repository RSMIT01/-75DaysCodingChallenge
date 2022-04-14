/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       // unordered_set<ListNode *>s;
       //  while(head)
       //  {
       //      if(s.find(head)!=s.end())
       //      {
       //          return head;
       //      }
       //      else
       //      {
       //         s.insert(head);
       //      }
       //      head=head->next;
       //  }
       //  return NULL;
        
        if(!head || !head->next )
        {
            return NULL;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        do{
            
            slow=slow->next;
            fast=fast->next->next;
        }while(fast && fast->next && slow!=fast);
        if(slow!=fast)
        {
             return NULL;
           
        }
         slow=head;
         while(slow!=fast)
         {
             slow=slow->next;
              fast=fast->next;
         }
        return slow;
    }
};