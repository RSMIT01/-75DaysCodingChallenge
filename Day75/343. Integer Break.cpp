class Solution {
public:
    int integerBreak(int n) {
        int p=1;
        if(n==2 || n==3)
        {
            return n-1;
        }
        else
        {
           while(n>4)
           {
               n=n-3;
               p=p*3;
           }
        }
     
        return n*p;
    }
};