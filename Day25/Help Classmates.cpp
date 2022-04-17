class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                arr[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
     
        while(!st.empty())
        {
            arr[st.top()]=-1;
            st.pop();
        }
        return arr;
    } 
};