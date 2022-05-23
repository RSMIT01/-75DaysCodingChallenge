/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* original,Node* clone,vector<Node*>&visited)
    {
         visited[clone->val]=clone;
         for(auto cur:original->neighbors)
         {
             if(visited[cur->val]==NULL)
             {
                 Node *temp=new Node(cur->val);
                 (clone->neighbors).push_back(temp);
                 dfs(cur,temp,visited);
             }
             else
             {
                  (clone->neighbors).push_back(visited[cur->val]);
             }
         }
    }
    Node* cloneGraph(Node* node) {
      if(!node)
      {
          return NULL;
      }
      vector<Node*>visited(101,NULL);
      Node *clone=new Node(node->val);
      dfs(node,clone,visited);
      return clone;
        
      
    }
};