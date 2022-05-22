class Solution {
public:
    void solve(vector<int>& num,vector<vector<int>> &ans,vector<int> &subset,int i)
    {
        if(i==num.size())
        {
            ans.push_back(subset);
            return;
        }
         solve(num,ans,subset,i+1);
         subset.push_back(num[i]);
         solve(num,ans,subset,i+1);
         subset.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        
        solve(nums,ans,subset,0);
       
        return ans;
    }
};