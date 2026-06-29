class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())return false;
        int req = 0;
        int p1 =0, p2 = 0;
        while(p1 < s.size() && p2<t.size()){
            if(s[p1]==t[p2]){
                req++;
                p1++;p2++;
            }
            else p2++;
        }
        return req==s.size();
    }
};