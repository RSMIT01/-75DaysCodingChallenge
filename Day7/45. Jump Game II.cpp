class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums[0]==0 || nums.size()<=1)
        {
            return 0;
        }
        int jump=1;
        int cur_max=nums[0];
        int max_pos=nums[0];
        int i=0;
        while(max_pos<nums.size()-1)
        {
           cur_max=max(i+nums[i],cur_max);
            if(i==max_pos)
            {
                max_pos=cur_max;
                jump++;
            }
            i++;
        }
        return jump;
    }
};