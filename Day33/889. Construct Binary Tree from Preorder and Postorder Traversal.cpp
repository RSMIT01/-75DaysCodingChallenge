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
    
      TreeNode* construct(vector<int>& preorder,int prestart,int preend, vector<int>& postorder,int poststart,int postend)
      {
          if(prestart>preend) return NULL;
          
           TreeNode* root=new  TreeNode(preorder[prestart]);
          
          if(prestart==preend) return root;
          
          int postidx=poststart;
          
          while(postorder[postidx]!=preorder[prestart+1]) postidx++;
          
          int len=postidx-poststart+1;
          root->left=construct(preorder,prestart+1,prestart+len,postorder,poststart,postidx);
          root->right=construct(preorder,prestart+len+1,preend,postorder,postidx+1,postend-1);
          
          return root;
          
          
      }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return construct(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};