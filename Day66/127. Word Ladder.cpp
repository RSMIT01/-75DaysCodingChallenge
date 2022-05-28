class Solution {
public:
  
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          int n=wordList.size();
          unordered_set<string>visited;
         unordered_set<string>word_list(wordList.begin(),wordList.end());
          queue<string>q;
          q.push(beginWord);
          int step=0;
          while(!q.empty())
          {
              
              int sz=q.size();
               step++;
              while(sz--)
              {
                string cur=q.front();
                q.pop();
                  if(cur==endWord)
                  {
                      return step;
                  }
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
                       if(word_list.find(temp)!=word_list.end() && visited.find(temp)==visited.end())
                       {
                               visited.insert(temp);
                               q.push(temp);
                       }
                       
                    }
                     temp[i]=cur[i];
              }
              }
             
             
          }
        return 0;
    }
};