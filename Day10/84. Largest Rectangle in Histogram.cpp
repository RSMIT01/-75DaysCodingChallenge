class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left_small(n);
         vector<int>right_small(n);
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                left_small[i]=0;//every element on left is small
            }
            else
            {
                left_small[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
         for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() &&  heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                right_small[i]=n-1;//every element on right is small
            }
            else
            {
                right_small[i]=st.top()-1;
            }
             ans=max(ans,(right_small[i]-left_small[i]+1)*heights[i]);
            st.push(i);
        }
        return ans;
    }
};