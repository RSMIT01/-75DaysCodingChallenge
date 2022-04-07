class Solution {
public:
    int find_last(vector<int>& nums, int target)
  {
      int idx=-1;
      int low=0;
      int high=nums.size()-1;
      while(low<=high)
      {
          int mid=low+(high-low)/2;
          if(nums[mid]<=target)
          {
              if(nums[mid]==target)
              {
                  idx=mid;
              }
              low=mid+1;
          }
          else 
          {
              high=mid-1;
          }
      }
      return idx;
  }
  
 int find_first(vector<int>& nums, int target)
 {
      int idx=-1;
      int low=0;
      int high=nums.size()-1;
      while(low<=high)
      {
          int mid=low+(high-low)/2;
          if(nums[mid]>=target)
          {
              if(nums[mid]==target)
              {
                  idx=mid;
              }
              high=mid-1;
          }
          else 
          {
              low=mid+1;
          }
      }
      return idx;
 }
  
    
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int l=find_first( nums,target);
        int r=find_last( nums,target);
      
        return {l,r};
    }
};