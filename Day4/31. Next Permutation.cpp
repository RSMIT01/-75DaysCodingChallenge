class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size()-2;
         while(n>=0 && nums[n]>=nums[n+1])
         {
             n--;
         }
         if(n<0)
         {
             reverse(nums.begin(),nums.end());
         }
         else
         {
             int idx=nums.size()-1;
             while(idx>=0 && nums[idx]<=nums[n])
             {
                 idx--;
             }
             swap(nums[n],nums[idx]);
             reverse(nums.begin()+n+1,nums.end());
         }
    }
};