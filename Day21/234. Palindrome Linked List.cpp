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
    ListNode* start=NULL;
    void solve(ListNode* tail,bool &ans)
    {
        if(tail==NULL)
        {
            return;
        } 
        solve(tail->next,ans);
        if(start->val!=tail->val)
        {
            ans=false;
        }
        start=start->next;
           
    }
    bool isPalindrome(ListNode* head) {
        bool ans=true;
        start=head;
         solve(head,ans);
        return ans;
    }
};