class Solution {
public:
    
    void dfs(string &begin,string &end,unordered_map<string,vector<string>> &adj,vector<string>seq,  vector<vector<string>> &sts)
    {
         
        if(begin==end)
        {
            seq.push_back(end);
            sts.push_back(seq);
            return;
        }
        for(auto it:adj[begin])
        {
           seq.push_back(begin);
            dfs(it,end,adj,seq,sts);
            seq.pop_back();
        }
        
    }
    

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         int n=wordList.size();
        unordered_map<string,int>visited;
           unordered_map<string,vector<string>>adj;
        unordered_set<string>word_list(wordList.begin(),wordList.end());
          queue<string>q;
          q.push(beginWord);
          visited[beginWord]=0;
          while(!q.empty())
          {

                string cur=q.front();
                q.pop();
                  string temp=cur;
                for(int i=0;i<cur.length();i++)
                {
                    
                    for(char c='a';c<='z';c++)
                    {
                        if(temp[i] == c)
                        {
                            continue;
                        }
                        
                        temp[i]=c;
                       if(word_list.find(temp)!=word_list.end()  )
                       {
                           if(visited.find(temp)==visited.end())
                           {
                               visited[temp]=visited[cur]+1;
                               q.push(temp);
                               adj[cur].push_back(temp);
                           }
                           else if(visited[temp]==visited[cur]+1)
                           {
                               adj[cur].push_back(temp);
                           }
                       }
                       
                    }
                     temp[i]=cur[i];
              }
             
              
          }
            vector<vector<string>>sts;
        vector<string>seq;
          dfs(beginWord,endWord,adj,seq,sts);
        return sts;
        
    }
};