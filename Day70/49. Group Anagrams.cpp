class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>t=strs;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            sort(t[i].begin(),t[i].end());
            m[t[i]].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};