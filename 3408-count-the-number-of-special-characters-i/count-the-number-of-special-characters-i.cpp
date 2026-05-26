class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> count(26,0);
        for(int i = 0; i < n;i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                count[word[i]-'A']=1;
            }
        }
        for(int i = 0; i < n;i++){
            if(word[i] >= 'a' && word[i] <= 'z' && count[word[i]-'a']==1){
                count[word[i]-'a']=2;
            }
        }
        int ans = 0;
        for(int i = 0;i<26;i++){
            if(count[i]==2)ans++;
        }
        return ans;
    }
};