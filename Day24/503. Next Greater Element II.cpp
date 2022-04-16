class Solution {
public:
    //time: O(2n) space=O(n) 
    vector<int> nextGreaterElements(vector<int>& nums) {
         stack<int>st;
        int n=nums.size();
         vector<int>res(n,-1);
         for(int i=0;i<2*n;i++)
         {
              while(!st.empty() && nums[st.top()]<nums[i%n])
              {
                  res[st.top()]=nums[i%n];
                  st.pop();
              }
              st.push(i%n);
         }
        return res;
    }
};