class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int n1=num1.length();
        int n2=num2.length();
         if(n1==1 && num1[0]=='0' || n2==1 && num2[0]=='0')
         {
            return "0";

         }
        vector<int>temp(n1+n2);
        
        
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                temp[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                temp[i+j+1]+=temp[i+j]/10;
                temp[i+j]%=10;
                
            }
        }
        
        reverse(temp.begin(),temp.end());
        string res="";
        
         int i=0;
        while(temp[i]==0 && i<temp.size()) i++;
        
        
        while(i<temp.size())
        {
          res+=to_string(temp[i]);
            i++;
        }
        
        return res;
    }
};