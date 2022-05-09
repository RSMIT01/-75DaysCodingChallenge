/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   void find_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
   {
       queue<TreeNode* >q;
       q.push(root);
       while(!q.empty())
       {
           int sz=q.size();
           while(sz--)
           {
               TreeNode* cur=q.front();
               q.pop();
               if(cur->left)
               {
                   q.push(cur->left);
                   parent[cur->left]=cur;
               }
               if(cur->right)
               {
                   q.push(cur->right);
                   parent[cur->right]=cur;
               }
           }
       }
   }
      
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        find_parent(root,parent);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode* >q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty())
        {
            if(level==k)
            {
                break;
            }
            int sz=q.size();
            while(sz--)
            {
                TreeNode* cur=q.front();
                 q.pop();
                if(cur->left && !visited[cur->left])
               {
                   q.push(cur->left);
                  visited[cur->left]=true;
               }
                 if(cur->right && !visited[cur->right])
               {
                   q.push(cur->right);
                  visited[cur->right]=true;
               }
                
               if(parent[cur] && !visited[parent[cur]])
               {
                     q.push(parent[cur]);
                  visited[parent[cur]]=true;
               }
            }
            level++;
            
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};