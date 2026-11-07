class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        //stack<int> st;
        int l = 0;
        string ans="";
        for(char c:s){
            if(c!='*'){
                // st.push(c);
                l++;
                ans += c;
            }
            else{
                if(l>0){
                    ans.pop_back();
                    l--;
                }
                else ans += '*';
            }
        }
        return ans;
    }
};