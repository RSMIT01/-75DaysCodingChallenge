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
    
    TreeNode *prev,*firstwrong,*secondwrong;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
         inorder(root->left);
        
         if(!firstwrong  && prev->val>root->val)
         {
             firstwrong=prev;
         }
        if(firstwrong && prev->val>root->val)
        {
            secondwrong=root;
        }
        prev=root;
        
         inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(firstwrong->val,secondwrong->val);
    }
};