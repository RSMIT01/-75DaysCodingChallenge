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
    //without reversing
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        
        int carry=0;
        ListNode *head=NULL;
    
        while(!s1.empty() || !s2.empty())
        {
            int x=0;
            int y=0;
            if(!s1.empty())
            {
                x=s1.top();
                s1.pop();
            }
            if(!s2.empty())
            {
                y=s2.top();
                s2.pop();
            }
             int val=(x+y+carry)%10;
             ListNode *temp=new ListNode(val);
              temp->next=head;
              head=temp;
            carry=(x+y+carry)/10;
        }
        if(carry>0)
        {
             ListNode *temp=new ListNode(carry);
              temp->next=head;
              head=temp;
        }
        return head;
    }
    
};