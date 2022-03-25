class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum=0;
        int left=0;
        int right=nums.size()-1;
        int leftsum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
           sum-=nums[i];
           if(leftsum==sum)
           {
               return i;
           }
           leftsum+=nums[i];
        }
        return -1;
    }
};