class Solution {
public:
    bool Check(unordered_map<char,int> &freq,unordered_map<char,int> &target){
        for(auto it:target){
            if(it.second > freq[it.first])return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        string minStr = "",windowStr="";

        unordered_map<char,int> freq,target;
        int left = 0;

        for(int i =0;i<t.size();i++)
        target[t[i]]++;

        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            windowStr += s[right];
        
            while(freq.size() >= target.size() && Check(freq,target)){
                int k = minStr.size();
                if(k==0 || windowStr.size() < k){
                    minStr = windowStr;
                }
                freq[s[left]]--;
                if(freq[s[left]]==0)freq.erase(s[left]);
                windowStr.erase(0,1);
                left++;
            }

        }
        return minStr;
    }
};