class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> integer;
        int n = s.size();
        integer['I'] = 1;
        integer['V'] = 5;
        integer['X'] = 10;
        integer['L'] = 50;
        integer['C'] = 100;
        integer['D'] = 500;
        integer['M'] = 1000;
        int num = 0;
       for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch == 'V' || ch=='X'){
            if(i>0 && s[i-1] == 'I'){
                num -= 2*integer['I'];
            }
        }
        else if(ch=='L' || ch=='C'){
            if(i>0 && s[i-1] == 'X'){
                num -= 2*integer['X'];
            }
        }
       
       else if(ch=='D' || ch=='M'){
            if(i>0 && s[i-1] == 'C'){
                num -= 2*integer['C'];
            }
        }
        num += integer[ch];
       }
        return num;
    }
};