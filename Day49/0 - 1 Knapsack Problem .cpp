class Solution
{
    public:
    int solve(int w,int wt[],int val[],int n,vector<vector<int>> &dp)
    {
        if(n<0)
        {
            return 0;
        }
        if(dp[w][n]!=-1)
        {
            return dp[w][n];
        }
        int temp=0;
        if(wt[n]<=w)
        {
            temp=val[n]+solve(w-wt[n],wt,val,n-1,dp);
        }
        return dp[w][n]=max(temp,solve(w,wt,val,n-1,dp));
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
       return solve(W,wt,val,n-1,dp);
    }
};