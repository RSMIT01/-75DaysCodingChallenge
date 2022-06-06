class Solution {
public:
    int myAtoi(string s) {
         int i = 0;
    int sign = 1;
         long num = 0;
 
    while (s[i] == ' ')
    {
    i++;
    }
     
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    
    for (i ; i < s.length() && isdigit(s[i]); i++) {
        num =  10 * num + (s[i] - '0');
        if (num > INT_MAX && sign == 1) {
          return INT_MAX; 
        }

        if ( sign == -1 && num * sign < INT_MIN) {
            
            return INT_MIN;
        }

    }
    return sign * num;

}
};

