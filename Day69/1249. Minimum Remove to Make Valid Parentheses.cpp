class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<pair<char,int>>st;
      for(int i=0;i<s.length();i++)
      {
          if(s[i]=='(')
          {
              st.push({'(',i});
          }
          else if(s[i]==')' && !st.empty() && st.top().first=='(')
          {
              st.pop();
          }
          else if(s[i]==')')
          {
              s.erase(i,1);
              i--;
          }
      }
        while(!st.empty())
        {
            int ind=st.top().second;
            s.erase(ind,1);
            st.pop();
        }
        return s;
    }
};