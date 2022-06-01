class Solution {
public:
    //idead is to divide stirng in parts so that each part not contain any char whose freq is <k and take max from all parts
    int longestSubstring(string s, int k) {
        int n=s.length();
        if(k>n || n==0)
        {
            return 0;
        }
        if(k<=1)
        {
            return n;
        }
        unordered_map<char,int>m;
        //count freq of chars in cur string
        for(int i=0;i<n;i++) m[s[i]]++;
        int l=0;
        //take char whose freq in cur string greater or equal k
        while(l<n && m[s[l]]>=k) l++;
        
        //if all char hase more than or equal k freq return it
        if(l>=n-1) return l;
        
        //call for first string
        int len1=longestSubstring(s.substr(0,l),k);
        
        //skip char whose freq less than k
         while(l<n && m[s[l]]<k)l++;
        
        //if any remaing string than call for it
         int len2=(l<n)?longestSubstring(s.substr(l),k):0;
        
        // take max of both
        return max(len1,len2);
        
    }
};