#include<bits/stdc++.h>
using namespace std;
void rabin_karp(string txt,string pat,int q,int d)
{
    int m=txt.length();
    int n=pat.length();
    int h=1;
    int t=0;
    int p=0;
    for(int i=0;i<n-1;i++)
    {
      h=(h*d)%q;
    }
    for(int i=0;i<n;i++)
    {
      t=(t*d+txt[i])%q;
      p=(p*d+pat[i])%q;
    } 
    int i,j;
    for(int i=0;i<=m-n;i++)
    {
          if(p==t)
          {
              
              for(j=0;j<n;j++)
              {
                  if(txt[i+j]!=pat[j])
                  {
                      break;
                  }
              }
              if(j==n)
              {
                  cout<<"found at "<<i<<endl;
              }
          }
          if(i<m-n)
          {
              t=((d*(t-h*txt[i]))+txt[i+n])%q;
                if(t<0)
                {
                    t=t+q;
                }
          }
          
    }
}
int main()
{
string txt =  "GEEKS FOR GEEKS";
string pat = "GEEKS";
int q=3;
int d=101;
rabin_karp(txt,pat,q,d);
return 0;
}