class Solution {
public:
   int dp[100001][2][2];
    int solve(vector<int>& prices,bool isbuy,int i,int n)
    {
       if(i==prices.size() || n==2)
       {
           return 0;
       }
        if(dp[i][n][isbuy]!=-1)
        {
           return dp[i][n][isbuy];
        }
        int no_transaction=solve(prices,isbuy,i+1,n);
        int transaction=0;
        if(isbuy)
        {
              transaction=solve(prices,false,i+1,n)-prices[i];
        }
        else 
        {
            transaction=solve(prices,true,i+1,n+1)+prices[i];
        }
         
        return dp[i][n][isbuy]=max(no_transaction,transaction);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,true,0,0);
    }
};