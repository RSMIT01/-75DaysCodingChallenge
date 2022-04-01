class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        int prefixsum=0;
        int rem=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
           prefixsum+=nums[i];
         
              rem=(prefixsum)%k;
            if(rem<0)
            {
                rem+=k;
            }
        
           if(m.find(rem)!=m.end())
           {
               ans+=m[rem];
           }
           m[rem]++;
        }
        return ans;
    }
};