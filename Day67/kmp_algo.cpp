#include <bits/stdc++.h>
using namespace std;

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

void kmp(string &txt, string &pat)
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
            cout << i - j << " ";
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
}

int main()
{
    string txt = "abcabcdaabcabcd";
    string pat = "abcabcd";
    kmp(txt, pat);
    return 0;
}