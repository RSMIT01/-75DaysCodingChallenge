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
    TreeNode* prev=NULL;
    void checkbsttree(TreeNode* root,bool &ans)
    {
        if(!root)
        {
          return ;
        }
      checkbsttree(root->left,ans);
        if(prev && prev->val>=root->val)
        {
            ans=false;
        }
        prev=root;
      checkbsttree(root->right,ans);
       
        
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        checkbsttree(root,ans);
        return ans;
    }
};