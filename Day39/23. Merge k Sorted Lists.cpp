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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
       for(int i=0;i<lists.size();i++)
       {
           if(lists[i])
           {
               pq.push({lists[i]->val,lists[i]->next});
           }
       }
        
        ListNode* ans=new ListNode(-1);
        ListNode* head=ans;
        
        
        while(!pq.empty())
        {
           
            pair<int,ListNode*>cur=pq.top();
            pq.pop();
            head->next=new ListNode(cur.first);
            if(cur.second)
            {
                pq.push({cur.second->val,cur.second->next});
            }
            head=head->next;
            
        }
        return ans->next;
        
    }
};