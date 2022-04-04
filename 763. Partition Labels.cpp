class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last_idx(26,-1);
        vector<int>partition;
        for(int i=0;i<s.length();i++)
        {
            last_idx[s[i]-'a']=i;
        }
        int cur_last=0;
       int len=0;
        for(int i=0;i<s.length();i++)
        {
            cur_last=max(cur_last,last_idx[s[i]-'a']);
            len++;
            if(cur_last==i)
            {
                partition.push_back(len);
                len=0;
            }
        }
        return partition;
    }
};