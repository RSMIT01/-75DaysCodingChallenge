class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
     int n=d.size()-1;
        while(n>=0)
        {
            if(d[n]==9)
            {
                d[n]=0;
            }
            else
            {
                d[n]++;
                return d;
            }
            n--;
        }
        d.insert(d.begin(),1);
        return d;
    }
};