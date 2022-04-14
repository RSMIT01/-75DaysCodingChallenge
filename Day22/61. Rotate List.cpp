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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
        {
            return head;
        }
       int count=0;
        ListNode*temp= head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        k=k%count;
        if(k==0)
        {
            return head;
        }
      temp= head;
        ListNode* end= head;
         int c=0;
          while(temp->next)
          {
            if(c>=k)
            {
                end=end->next;
            }  
              c++;
              temp=temp->next;
          }
         temp->next=head;
         head=end->next;
        end->next=NULL;
         
          return head;
    }
};