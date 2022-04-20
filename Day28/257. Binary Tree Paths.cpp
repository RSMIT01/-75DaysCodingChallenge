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
    vector<string>ans;
    void solve(TreeNode *root,string s)
    {
    if(!root->left && !root->right)
    {
        ans.push_back(s);
    }
    if(root->left)
    {
        string s1=s+"->"+to_string(root->left->val);
        solve(root->left,s1);
    }
      if(root->right)
    {
        string s1=s+"->"+to_string(root->right->val);
        solve(root->right,s1);
    }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s=to_string(root->val);
        solve(root,s);
        return ans;
    }
};