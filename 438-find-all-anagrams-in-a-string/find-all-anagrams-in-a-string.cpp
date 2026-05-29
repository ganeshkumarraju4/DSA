class Solution {
public:
    bool Compare(vector<int> &a,vector<int> &b){
        for(int i =0 ;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26,0),freqWindow(26,0);
        vector<int> ans;
        if(s.size()<p.size())return {};

        for(int i = 0;i<p.size();i++){
            freqP[p[i]-'a']++;
            freqWindow[s[i]-'a']++;
        }
        if(Compare(freqP,freqWindow)){
            ans.push_back(0);
        }
        int k = p.size();
        for(int i=k;i < s.size();i++){
            freqWindow[s[i]-'a']++;
            freqWindow[s[i-k]-'a']--;
            if(Compare(freqP,freqWindow)){
                ans.push_back(i-k+1);
            }
        }
    return ans;
    }
};