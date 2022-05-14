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
    // time:O( C(2n, n)/ (n+1))  Catalan Series

    
    vector<TreeNode*> solve(int start,int end)
    {
         vector<TreeNode*>ans;
         if(start>end)
         {
             ans.push_back(NULL);
             return ans;
         }
        
         for(int i=start;i<=end;i++)
         {
            vector<TreeNode*> lefttree=solve(start,i-1);
            vector<TreeNode*> righttree=solve(i+1,end);
             
             for(auto l:lefttree)
             {
                 for(auto r:righttree)
                 {
                     TreeNode*cur=new TreeNode(i);
                     cur->left=l;
                     cur->right=r;
                     ans.push_back(cur);
                 }
             }
         }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return solve(1,n);
    }
};