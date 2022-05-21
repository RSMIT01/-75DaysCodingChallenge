class Solution {
public:
    
    void solve(int n,int k, vector<vector<int>> &ans,vector<int> &sub,int start)
    {
        if(k==0)
        {
            ans.push_back(sub);
            return;
        }
        for(int j=start;j<=n;j++)
        {
            sub.push_back(j);
             solve(n,k-1,ans,sub,j+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>sub;
        vector<vector<int>>ans;
        solve(n,k,ans,sub,1);
        return ans;
    }
};