class Solution {
public:
    int solve(vector<int>& coins,int amount,int i,vector<vector<int>> &dp)
    {
        if(amount==0)
        {
            return 0;
        }
        else if(i<0 || amount<0)
        {
            return 1e8;
        }
       else if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        else if(coins[i]<=amount)
        {
          return dp[i][amount]= min(1+solve(coins,amount-coins[i],i,dp),solve(coins,amount,i-1,dp));
        }
        else
        {
            return dp[i][amount]= solve(coins,amount,i-1,dp);
        }
        
    }
    int coinChange(vector<int>& coins,int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= solve(coins,amount,n-1,dp);
        if(ans==1e8)
        {
            return -1;
        }
        return ans;
    }
};