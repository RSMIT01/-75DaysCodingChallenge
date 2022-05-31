class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
     vector<int>last_idx(256,-1);
        
      int len=0;
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            start=max(start,last_idx[s[i]]+1);
            last_idx[s[i]]=i;
            len=max(len,i-start+1);
        }
        return len;
      
    }
};