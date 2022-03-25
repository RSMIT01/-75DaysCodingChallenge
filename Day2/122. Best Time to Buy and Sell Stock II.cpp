class Solution {
public:
    
    
    // time O(n*2) space=(n*2)+recursion stack
    
    
    // int solve(vector<vector<int>> &dp,int i,vector<int>& prices,bool buy)
    // {
    //     if(i>=prices.size())
    //     {
    //         return 0;
    //     }
    //     if(dp[i][buy]!=-1)
    //     {
    //         return dp[i][buy];
    //     }
    //     int ans=INT_MAX;
    //     if(buy)
    //     {
    //         ans=max(solve(dp,i+1,prices,buy),solve(dp,i+1,prices,!buy)-prices[i]);
    //     }
    //     else
    //     {
    //           ans=max(solve(dp,i+1,prices,buy),solve(dp,i+1,prices,!buy)+prices[i]);
    //     }
    //     return dp[i][buy]=ans;
    // }
    int maxProfit(vector<int>& prices) {
        
      // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
      // return solve(dp,0,prices,true);
     
        
        
        //O(n)
       int m=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i-1]<prices[i])
            {
                m+=prices[i]-prices[i-1];
            }
        }
        return m;
    }
};