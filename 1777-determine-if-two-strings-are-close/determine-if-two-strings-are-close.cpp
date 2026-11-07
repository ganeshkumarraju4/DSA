class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> m1,m2,m3;
        for(char c:word1){
            m1[c]++;
        }

        for(char c:word2){
            m2[c]++;
        }
        if(m1.size()!=m2.size())return false;
        int totalChar = 0;
        for(auto it:m1){
            totalChar += it.second;
            if(m2.count(it.first)==0)return false;
            m3[it.second]++;
        }

        for(auto it:m2){
            totalChar -= it.second;
            if(m3.find(it.second)==0)return false;
            else m3[it.second]--;
        }
        for(auto it:m3){
            if(it.second!=0)return false;
        }
        if(totalChar !=0)return false;

        return true;
    }
};