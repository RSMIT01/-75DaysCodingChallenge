class Solution{
public:
    int solve(int arr[],int sum,int cursum,int i,int n,vector<vector<int>> &dp)
    {
        if(cursum==sum)
        {
            return 1;
        }
        if(i==n || cursum>sum)
        {
            return 0;
        }
        if(dp[i][cursum]!=-1)
        {
            return dp[i][cursum];
        }
        return dp[i][cursum]=solve(arr,sum,cursum,i+1,n,dp) || solve(arr,sum,cursum+arr[i],i+1,n,dp);
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
         if(sum%2)
        {
            return 0;
        }
        vector<vector<int>>dp(N+1,vector<int>(sum,-1));
        return solve(arr,sum/2,0,0,N,dp);
    }
   
};