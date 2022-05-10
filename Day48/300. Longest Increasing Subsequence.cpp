class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lci;
        lci.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
          int j=lci.size();
            if(lci[j-1]<nums[i])
            {
                lci.push_back(nums[i]);
            }
            else
            {
             int lower=lower_bound(lci.begin(),lci.end(),nums[i])-lci.begin();
               
                lci[lower]=nums[i];
            }
        }
        return lci.size();
    }
};