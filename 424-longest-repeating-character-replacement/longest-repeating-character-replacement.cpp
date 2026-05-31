class Solution {
public:
    int freqCharCount(vector<int> freq){
        int maxi =0;
        for(int i=0;i<26;i++)maxi=max(maxi,freq[i]);
        return  maxi;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        vector<int> freq(26,0);
        
        int windowLength = 0;
        int left = 0;

        for(int right =0;right<s.size();right++){
            windowLength++;
            freq[s[right]-'A']++;
            
            while(windowLength - freqCharCount(freq) >k){
            
                freq[s[left]-'A']--;
                left++;
                windowLength--;
            }
            ans = max(ans,windowLength);
        }
       
        return ans;
    }
};