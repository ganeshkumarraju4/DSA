class Solution {
public:
    bool Check(vector<int> &a,vector<int> &b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())return false;
        vector<int> freq(26,0),windowFreq(26,0);
        int k = s1.size();
        for(int i=0;i<k;i++){
            freq[s1[i]-'a']++;
            windowFreq[s2[i]-'a']++;
        }
        if(Check(freq,windowFreq))return true;
        for(int i = k;i<s2.size();i++){
            windowFreq[s2[i]-'a']++;
            windowFreq[s2[i-k]-'a']--;
            if(Check(freq,windowFreq))return true;
        }
        return false;
    }
};