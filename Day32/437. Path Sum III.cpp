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
    void solve(TreeNode* root, int targetSum, unordered_map<int,int>m,int &path,long long cursum)
    {
        if(!root)
        {
            return;
        }
        cursum+=root->val;
      
        if(cursum==targetSum)
        {
            path++;
        }
        if(m.find(cursum-targetSum)!=m.end())
        {
            path+=m[cursum-targetSum];
        }
        
          m[cursum]++;
         solve(root->left,targetSum,m,path,cursum);
         solve(root->right,targetSum,m,path,cursum);
          m[cursum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int path=0;
        unordered_map<int,int>m;
        solve(root,targetSum,m,path,0);
        return path;
    }
};