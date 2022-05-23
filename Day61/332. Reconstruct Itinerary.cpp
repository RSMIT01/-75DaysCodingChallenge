class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>m;
        stack<string>st;
        st.push("JFK");
        for(auto it:tickets)
        {
            m[it[0]].insert(it[1]);
        }
        vector<string>res;
        while(!st.empty())
        {
            string src=st.top();
            if(m[src].size()==0)
            {
                res.push_back(src);
                st.pop();
            }
            else
            {
                auto dest=m[src].begin();
               st.push(*dest);
                m[src].erase(dest);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};