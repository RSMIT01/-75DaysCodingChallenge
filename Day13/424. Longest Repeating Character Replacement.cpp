class Solution {
public:
    int characterReplacement(string s, int k) {
    int start=0;
        int end=0;
        int n=s.length();
        vector<int>freq(26,0);
        int max_len=0;
        int max_freq=0;
        while(end<n)
        {
            freq[s[end]-'A']++;
           max_freq=max(max_freq,freq[s[end]-'A']);
            
           if((end-start+1)-max_freq>k)
           {
            
               max_len=max(max_len,end-start);
               freq[s[start]-'A']--;
               start++;
           }
        
            end++;
        }
        return max(max_len,end-start);
    }
};