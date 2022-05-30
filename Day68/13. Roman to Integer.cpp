class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int a[s.length()];
        for(int i=0;i<s.length();i++)
        {
            
           
            if(s[i]=='I')
            {
               
                a[i]=1;
            }
            else if(s[i]=='V')
            {
               a[i]=5;
            }
            else if(s[i]=='X')
            {
                
                a[i]=10;
            }
            else if(s[i]=='L')
            {
              
                a[i]=50;
            }
            else if(s[i]=='C')
            {
                
                a[i]=100;
            }
            else if(s[i]=='D')
            {
                a[i]=500;
            }
            else
            {
                
                a[i]=1000;
            }
        }
        sum=sum+a[0];
        for(int i=1;i<s.length();i++)
        {
            if(a[i-1]<a[i])
            {
              sum=sum+a[i]-2*a[i-1];
            }
            else
            {
            sum=sum+a[i];
            }
         
        }
        return sum;
    }
        
    
};