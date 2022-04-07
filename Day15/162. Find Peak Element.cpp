class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=1)
        {
          return 0;
        }
        if(nums[0]>nums[1] ) //fisrt element is peak
        {
            return 0;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2])//last element is peak
        {
            return nums.size()-1;
        }
        int l=1;
        int h=nums.size()-2;
        int mid=0;
         while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
           else if(nums[mid]<nums[mid-1] )
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
       return -1;
    }
};