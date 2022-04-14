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
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* ans=new ListNode(0);
         ans->next=head;
          ListNode* cur=ans;
         ListNode* prev=ans;
        ListNode* nextt=ans;
         int length=0;
        while(cur->next)
        {
            length++;
            cur=cur->next;
        }
       
        while(length>=k)
        {
            cur=prev->next;
            nextt=cur->next;
            for(int i=1;i<k;i++)
            {
                cur->next=nextt->next;
                nextt->next=prev->next;
                prev->next=nextt;
                nextt=cur->next;
                
            }
           prev=cur;
            length-=k;
        }
        return ans->next;
    }
};