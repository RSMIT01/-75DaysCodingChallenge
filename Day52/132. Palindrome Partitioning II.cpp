class Solution {
public:
     bool ispalindrom(int start,int end,string &s)
    {
        
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            {
                return false;
            }
        }
        return true;
    }
    int solve(string &s, vector<vector<int>> &dp,int start,int end)
    {
        if(ispalindrom(start,end,s))
        {
            return 0;
        }
        else if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        int ans=INT_MAX;
        for(int i=start;i<=end;i++)
        {
            if(ispalindrom(start,i,s))  
            {
              int temp=1+ solve(s,dp,start,i)+ solve(s,dp,i+1,end);
              ans=min(ans,temp);
            }
            
        }
        return  dp[start][end]=ans;
    }
    int minCut(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
       return solve(s,dp,0,s.size()-1);
       
    }
};