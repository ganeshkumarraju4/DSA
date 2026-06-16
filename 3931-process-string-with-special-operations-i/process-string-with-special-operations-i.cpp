class Solution {
public:
    string processStr(string s) {
        string ans;
        for(auto ch: s){
            if(ch >= 'a' && ch <= 'z'){
                ans+= ch;
            }
            else if(ch == '*'){
                if(ans.size() > 0){
                    ans.pop_back();
                }
            }
            else if(ch == '#'){
                ans.append(ans);
            }
            else if(ch == '%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};