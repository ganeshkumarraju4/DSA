class Solution {
public:
    string minWindow(string s, string t) {
        int required = 0,formed = 0;
        int start = 0;
        unordered_map<char,int> target,window;
        for(auto it: t){
            target[it]++;
        }
        int minLen = 1e9;
      
        required = target.size();
        int left = 0;
        for(int i = 0;i < s.size();i++){
            window[s[i]]++;
            if(target.count(s[i]) && window[s[i]] == target[s[i]]){
                formed++;
            }
            while(formed == required){
                if(i-left+1 < minLen){
                    minLen = i-left+1;
                    start = left;
                }
                window[s[left]]--;
                if(target.count(s[left]) && window[s[left]] < target[s[left]])formed--;
                left++;
            }
        }
        if(minLen == 1e9)return "";
        else return s.substr(start,minLen);
    }
};