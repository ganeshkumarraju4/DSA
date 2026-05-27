class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowercase(26,0),uppercase(26,0);
        int n = word.size();

        for(int i = 0;i < n ; i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(uppercase[word[i]-'a']==0){
                    lowercase[word[i]-'a']=1;
                }
                else  lowercase[word[i]-'a']=0;
            }
            if(word[i] >= 'A' && word[i] <= 'Z' && !uppercase[word[i]-'A']){
                uppercase[word[i]-'A'] = 1;
            }
        }
        int count = 0;
        for(int i = 0;i< 26;i++){
            count += lowercase[i] * uppercase[i];
        }
        return count;
    }
};