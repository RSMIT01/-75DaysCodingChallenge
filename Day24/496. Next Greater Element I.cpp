class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>m;
        for(int i=0;i<nums2.size();i++)
        {
               while(!st.empty() && st.top()<nums2[i])
                {
                    m[st.top()]=nums2[i];//if current element is greater then top then  next greater of top element  is current
                    st.pop();
                }
                st.push(nums2[i]);
         
        }
        while(!st.empty())
        {
            m[st.top()]=-1;//remaining element in stack has no next greater elements so mark -1.
            st.pop();
        }
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=m[nums1[i]]; //assign next greater
            
        }
        return nums1;
    }
};