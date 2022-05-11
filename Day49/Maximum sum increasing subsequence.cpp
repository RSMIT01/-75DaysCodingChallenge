class Solution{
		
    int solve(int nums[],int n,int prev,int cur,vector<vector<int>> &dp)
    {
        if(cur==n)
        {
            return 0;
        }
         if(dp[prev+1][cur]!=-1)
        {
            return dp[prev+1][cur];
        }
        int sum=solve(nums,n,prev,cur+1,dp);
        if(prev==-1 || nums[prev]<nums[cur])
        {
           sum=max(sum,nums[cur]+solve(nums,n,cur,cur+1,dp));
        }
        return dp[prev+1][cur]=sum;
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(arr,n,-1,0,dp);
	}  
};