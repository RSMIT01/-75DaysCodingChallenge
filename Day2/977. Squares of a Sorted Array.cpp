class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //O(nlogn)
        // for(int i=0;i<nums.size();i++)
        // {
        //     nums[i]=nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        
        
        
        //time:O(n) space:O(n)
        vector<int>ans(nums.size());
        int left=0;
        int right=nums.size()-1;
        int n=nums.size()-1;
        while(left<=right)
        {
            if(abs(nums[left])<abs(nums[right]))
            {
                ans[n--]=nums[right]*nums[right];
                right--;
            }
            else
            {
                ans[n--]=nums[left]*nums[left];
                left++;
            }
        }
        return ans;
         
    }
};