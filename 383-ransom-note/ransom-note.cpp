class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())return false;
        unordered_map<char,int> freq,target;
        for(auto it: ransomNote){
            target[it]++;
        }
        for(auto it: magazine){
            freq[it]++;
        }
        for(auto it: target){
            if(freq[it.first] < it.second)return false;
        }
        return true;
    }
};