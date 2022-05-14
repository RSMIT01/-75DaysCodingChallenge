class Solution {
public:
   int  solve(int e,int f,vector<vector<int>>& dp)
    {
        if(f==0 || f==1 || e==1)
        {
            return f;
        }
        if(dp[e][f]!=-1)
        {
            return dp[e][f];
        }
        int ans=INT_MAX,low=1,high=f,left,right,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(dp[e-1][mid-1]!=-1)
            {
                left=dp[e-1][mid-1];
            }
            else
            {
                left=solve(e-1,mid-1,dp);
                dp[e-1][mid-1]=left;
            }
            if(dp[e][f-mid]!=-1)
            {
                right=dp[e][f-mid];
            }
            else
            {
                right=solve(e,f-mid,dp);
                dp[e][f-mid]=right;
            }
            if(left<right)
            {
              low=mid+1;
            }
            else
            {
               high=mid-1;
            }
            int temp=1+max(left,right);
            ans=min(temp,ans);
        }
            
        
        return dp[e][f]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};