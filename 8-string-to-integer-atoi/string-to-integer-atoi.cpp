class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1;
        int n = s.size();
        int i = 0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        for(int j = i;j<n;j++){
            char ch = s[j];
            
            if(ch >= '0' && ch <='9'){
                if(num > INT_MAX / 10 ||
                    (num == INT_MAX / 10 && ch-'0' > 7))
                    {
                        return sign == 1 ? INT_MAX : INT_MIN;
                    }
                num = num *10 + (ch-'0');
            }
            else return num*sign;
        }
        return num*sign;
    }
};