class Solution {
public:
    void find_lps(string &pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            lps[i] = ++len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = len;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

int kmp(string &txt, string &pat)
{
    int m = txt.length();
    int n = pat.length();
    vector<int> lps(n, 0);
    find_lps(pat, lps);
    int i = 0;
    int j = 0;
    while (i < m)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            return i-j;
            j = lps[j - 1];
        }
        if (i < m && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    return -1;
}
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length())
        {
            return -1;
        }
        // int n=needle.length();
        // if(n==0)
        // {
        //     return 0;
        // }
        // for(int i=0;i<=haystack.length()-n;i++)
        // {
        //     if(haystack.substr(i,n)==needle)
        //     {
        //         return i;
        //     }
        // }
        // return -1;
        
        
        
        //kmp algo
        
        return kmp(haystack,needle);
        
    }
};