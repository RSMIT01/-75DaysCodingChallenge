/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        if(!root)
        {
            return ans;
        }
        s1.push(root);
        while(!s1.empty() || !s2.empty() )
        {
          
            if(!s1.empty())
            {
                  vector<int>res1;
                int size1=s1.size();
               for(int i=0;i<size1;i++)
               {
                   TreeNode* cur=s1.top();
                   s1.pop();
                   res1.push_back(cur->val);
                   if(cur->left) s2.push(cur->left);
                   if(cur->right) s2.push(cur->right);
                
               }
              
                 ans.push_back(res1);
    
            }

           if(!s2.empty())
            {
                vector<int>res2;
               int size2=s2.size();
               for(int i=0;i<size2;i++)
               {
                   TreeNode* cur=s2.top();
                   s2.pop();
                   res2.push_back(cur->val);
                   if(cur->right) s1.push(cur->right);
                   if(cur->left) s1.push(cur->left);
                   
                   
               }
                ans.push_back(res2);
            }
           
        }
        return ans;
    }
};