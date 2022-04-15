/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
       // unordered_map<Node*,Node*>m;
       //  m[NULL]=NULL;
       //  Node *temp=head;
       //  while(temp)
       //  {
       //      m[temp]=new Node(temp->val);
       //      temp=temp->next;
       //  }
       //  temp=head;
       //  Node *ans=m[head];
       //  while(temp)
       //  {
       //     ans->next=m[temp->next];
       //     ans->random=m[temp->random];
       //      ans=ans->next;
       //      temp=temp->next;
       //  }
       //  return m[head];
        
        
        
        //without extra space
        
        
        Node *temp=head;
        while(temp)
        {
            Node *newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        temp=head;
        while(temp)
        {
            temp->next->random=(temp->random)?temp->random->next:NULL;
            temp=temp->next->next;
        }
        temp=head->next;
        Node *ans=head->next;
        while(head)
        {
            head->next=temp->next;
            head=head->next;
            if(!head)
            {
                break;
            }
            temp->next=temp->next->next;
            
            temp=temp->next;
        }
        return ans;
    }
};