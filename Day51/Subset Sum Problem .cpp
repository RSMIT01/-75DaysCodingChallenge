class Solution{   
public:
    bool solve(vector<int>arr, int sum,int i, vector<vector<int>> &dp)
    {
        if(sum==0)
        {
            return 1;
        }
        else if(i<0 || sum<0)
        {
            return 0;
        }
         else if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
          return dp[i][sum]=solve(arr,sum-arr[i],i-1,dp) || solve(arr,sum,i-1,dp);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
         int n=arr.size();
          vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       
        return solve(arr,sum,n-1,dp);
    }
};