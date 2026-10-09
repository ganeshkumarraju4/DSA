class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(s[i]);
            else {
                if(!st.empty()){
                    if(i+1<n && s[i+1]==')'){
                        st.pop();
                        i++;
                    }
                    else{
                        count++;
                        st.pop();
                    }
                }
                else{
                     if(i+1<n && s[i+1]==')'){
                        count++;
                        i++;
                    }
                    else{
                        count+=2;
                        
                    }
                }
            }
        }
        while(!st.empty()){
            count+=2;
            st.pop();
        }
        return count;
    }
};