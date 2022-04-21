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
    bool solve(TreeNode* root, int targetSum,int cursum)
    {
             if(!root)
             {
                 return false;
             }
            cursum+=root->val;
            if(cursum==targetSum && root->left==NULL && root->right==NULL)
            {
                return true;
            }
         
        return solve(root->left,targetSum,cursum) || solve(root->right,targetSum,cursum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }
};