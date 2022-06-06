class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int cur=nums[0];
        int temp=max(nums[1]*nums[2],nums[n-1]*nums[n-2]);
        if(cur<0)
        {
            return cur*min(nums[1]*nums[2],nums[n-1]*nums[n-2]);
        }
        return temp*cur;
    }
};