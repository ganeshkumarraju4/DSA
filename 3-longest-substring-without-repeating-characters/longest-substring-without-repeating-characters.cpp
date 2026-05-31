class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int windowSize = 0;
        int longestSubstrLength = 0;
        for(int i = 0;i<s.size();i++){
            if(freq.find(s[i]) != freq.end()){
                longestSubstrLength = max(longestSubstrLength,windowSize);
                while(freq.find(s[i]) != freq.end()){
                    freq.erase(s[i-windowSize]);
                    windowSize--;
                }
                
            }
            freq[s[i]]=1;
            windowSize++;
        }
        longestSubstrLength = max(longestSubstrLength,windowSize);
        return longestSubstrLength;
    }
};