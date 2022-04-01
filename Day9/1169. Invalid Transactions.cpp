class Solution {
public:
    pair<pair<string,string>,pair<int,int>> parsedata(string &s)
    {
        //storing index of all 3 comas
        vector<int>coma;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==',')
            {
                coma.push_back(i);
            }
        }
        string name=s.substr(0,coma[0]);
         int time=stoi(s.substr(coma[0]+1,coma[1]-coma[0]-1));
        int amount=stoi(s.substr(coma[1]+1,coma[2]-coma[1]-1));
        string city=s.substr(coma[2]+1);
        return {{name,city},{time,amount}};
    }
    
    bool invalid(int i,unordered_map<string,unordered_map<string,vector<int>>> &m, vector<pair<pair<string,string>,pair<int,int>>> &data)
    {
        pair<string,string>pstring=data[i].first;
        pair<int,int>pnum=data[i].second; 
         if(pnum.second>1000)
         {
             return true;
         }
         int curtime=pnum.first;
          for(auto it:m[pstring.first])
          {
              if(it.first==pstring.second)
              {
                  continue;
              }
              for(auto i:it.second)//checking if any same name and different city which occurs within 60 minutes 
              {
                   int time=data[i].second.first;
                  if(abs(curtime-time)<=60)
                  {
                      return true;
                  }
              }
          }
         return false;
    }
    
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<pair<pair<string,string>,pair<int,int>>>data(n);//[[name,city],[time,amount]]
        unordered_map<string,unordered_map<string,vector<int>>>m;//[[name],[city,all i of same city]]
        
        
        //taking data from strings
          for(int i=0;i<transactions.size();i++)
          {
                auto [pstring,pnum]=parsedata(transactions[i]);
                data[i]={pstring,pnum};
              m[pstring.first][pstring.second].push_back(i);
          }
        
        
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
             if(invalid(i,m,data))
             {
                 ans.push_back(transactions[i]);
             }
        }
        return ans;
    }
};