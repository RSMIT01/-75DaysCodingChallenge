class Solution {
public:
    
    bool palindrome(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            {
                if(!palindrome(i+1,j,s) && !palindrome(i,j-1,s))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
             i++;
             j--;
        }
        return true;
    }
};