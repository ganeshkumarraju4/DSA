class Solution {
public:
    int compress(vector<char>& chars) {
        char c = chars[0];
        int n = chars.size();
        int l = 0;
        if(n==1)return 1;
        int count = 1;
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1])count++;
            else {
                chars[l] = c;
                c = chars[i];
                l++;
                if(count>1){
                    string s = to_string(count);
                    int j = 0;
                    while(j<s.size()){
                        chars[l] = s[j];
                        j++;l++;
                    }
                }
                
               count = 1;
            }
        }
        chars[l] = c;
               
                l++;
                if(count>1){
                    string s = to_string(count);
                    int j = 0;
                    while(j<s.size()){
                        chars[l] = s[j];
                        j++;l++;
                    }
                }
        return l;
    }
};