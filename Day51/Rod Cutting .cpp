class Solution{
  public:
   int solve(int price[], int n,vector<int> &dp)
   {
       if(n==0)
       {
           return 0;
       }
       else if(dp[n]!=-1)
       {
           return dp[n];
       }
       int ans=INT_MIN;
       for(int i=0;i<n;i++)
       {
           ans=max(ans,price[i]+solve(price,n-i-1,dp));
       }
       return dp[n]=ans;
   }
  
    int cutRod(int price[], int n) {
        //code here
         vector<int>dp(n+1,-1);
         return solve(price,n,dp);
    }
};