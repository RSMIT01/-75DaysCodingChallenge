class Solution {
public:

    bool canJump(vector<int>& nums) {
       if(nums[0]==0 && nums.size()>1 )
       {
           return false;
       }
        for(int i=1;i<nums.size()-1;i++)
        {
            nums[i]=max(nums[i],nums[i-1]-1);
            if(nums[i]<=0)
            {
                return false;
            }
        }
        return true;
    }
};