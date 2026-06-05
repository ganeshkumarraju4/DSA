class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for(int i=0;i < s.size();i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq,freq[s[i]]);
        }
        
        string ans="";
        int n = s.size();
        if(maxFreq > (n+1)/2)return ans;

         for (auto &it : freq) {
            pq.push({it.second, it.first});
        }
        pair<int,char> prev = {0,'/'};
        while(!pq.empty()){
            int count = pq.top().first;
            int ch = pq.top().second;
            ans += ch;
            count--;
            pq.pop();
            if(prev.first > 0){
                pq.push(prev);
               
            }
            prev = {count,ch};
        }
        return ans;
    }
};