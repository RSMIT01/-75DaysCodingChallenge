/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
        {
            return head;
        }
        //if child exist then it will remain on top of next so first child will linked and then continue to next.
        stack<Node*>st;
        st.push(head);
        Node * temp=new Node(0);
        Node *prev=temp;
       while(!st.empty())
       {
           Node *cur=st.top();
           st.pop();
           if(cur->next)
           {
               st.push(cur->next);
           }
           if(cur->child)
           {
               st.push(cur->child);
           }
           cur->child=NULL;
           cur->prev=prev;
           prev->next=cur;
           prev=cur;
           
       }
      temp->next->prev=NULL;
      return temp->next;
    }
};