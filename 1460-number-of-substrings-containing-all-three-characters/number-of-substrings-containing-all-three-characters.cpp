class Solution {
public:
    bool isValid(unordered_map<char,int> &m){
        if(m.size() < 3)return false;
        return m['a'] && m['b'] && m['c'];
    }
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int n = s.size();
        int l = 0,r = 0;
        int count = 0;
        while(r < n){
            m[s[r]]++;
            while(isValid(m)){
                count += n - r;
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return count;
    }
};