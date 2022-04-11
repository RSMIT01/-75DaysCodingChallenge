class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>m;
        for(int i=0;i<order.length();i++)
        {
            m[order[i]]=i;
        }
        
        for(int i=0;i<words.size()-1;i++)
        {
            string w1=words[i];
            string w2=words[i+1];
            bool issmall=false;
             for(int j=0;j<min(w1.length(),w2.length());j++)
             {
                 
                 if(m[w1[j]]<m[w2[j]])  //if one char small then it is smaller in lexicographically order
                 {
                     issmall=true;
                    break;
                 }
                 if(m[w1[j]]>m[w2[j]])  
                 {
                    
                     return false;
                 }
             }
            if(!issmall && w1.length()>w2.length()) //if prefix of both is same and w1 has some more extra characters then it is larger.
            {
                return false;
            }
        }
        return true;
    }
};