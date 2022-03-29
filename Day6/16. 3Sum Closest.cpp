class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int diff=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int start=i+1,end=nums.size()-1;
            while(start<end)
            {
                int sum=nums[i]+nums[start]+nums[end];
                if(abs(target-sum)<abs(diff)) //taking abs for -ve target 
                {
                    diff=target-sum;
                }
                else if(sum>target)
                {
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
        return target-diff;
    }
};