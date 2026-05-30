class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int wordlen = words[0].size();
        int wordcount = words.size();
        int totallen = wordlen * wordcount;

        if(n < totallen)return ans;
        unordered_map<string,int> target;
        for(auto word: words)target[word]++;

        for(int offset = 0;offset < wordlen;offset++){
            unordered_map<string,int> window;
            int left = offset;
            int count = 0;
            for(int r = offset;r+wordlen <= n;r+=wordlen){
                string word = s.substr(r,wordlen);
                if(target.count(word)){
                    window[word]++;
                    count++;

                    while(window[word] > target[word]){
                        string leftword = s.substr(left,wordlen);
                        window[leftword]--;
                        left += wordlen;
                        count--;
                    }
                    if(count == wordcount){
                        ans.push_back(left);
                        string leftword = s.substr(left,wordlen);
                        window[leftword]--;
                        left+= wordlen;
                        count--;
                    }
                }
                else {
                    window.clear();
                    count = 0;
                    left = r + wordlen;
                }
            }
        }
        return ans;
    }
};