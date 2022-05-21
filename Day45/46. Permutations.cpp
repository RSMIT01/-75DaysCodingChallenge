class Solution {
public:
     vector<vector<int>> ans;
     void perm(vector<int>  &nums,int j)
     {
         if(j==nums.size())
         {
             ans.push_back(nums);
             return ;
         }
         for(int i=j;i<nums.size();i++)
         {
             swap(nums[i],nums[j]);
             perm(nums,j+1);
             swap(nums[i],nums[j]);
         }
      
     }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return ans;
    }
};