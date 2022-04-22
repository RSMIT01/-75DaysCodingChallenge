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
     int calc(TreeNode *root,int m,int &count)
     {
         
        if(root!=NULL){
         if(root->val>=m)
         {
             m=root->val;
             count++;
         }
        calc(root->left,m,count);
        calc(root->right,m,count);
        }
         return count;
     }
    int goodNodes(TreeNode* root) {
        int count=0;
       return  calc(root,root->val,count);
        
    }
};