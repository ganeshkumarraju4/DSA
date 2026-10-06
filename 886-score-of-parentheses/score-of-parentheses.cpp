class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }
            else if(s[i]==')'){
                if(i>0 && s[i-1]=='('){
                    
                    score += pow(2,depth-1);
                }
                depth--;
            }
        }
        return score;
    }
};