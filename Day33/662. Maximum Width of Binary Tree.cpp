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
    int widthOfBinaryTree(TreeNode* root) {
          queue<pair<TreeNode*,int> >q;
          q.push({root,0});
          int width=1;
          while(!q.empty())
          {
              int sz=q.size();
              int left_start=q.front().second;
              int right_end=q.back().second;
               width=max(width,right_end-left_start+1);
              while(sz--)
              {
                  TreeNode* cur=q.front().first;
                  
                  int idx=q.front().second;
                  q.pop();
             
                  if(cur->left!=NULL)
                  {
                    
                      q.push({cur->left,(long long)2*idx+1});
                  }
                 
                  if(cur->right!=NULL)
                  {
                      q.push({cur->right,(long long)2*idx+2});
                  }
              }
             
          }
        return width;
    }
};