class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int operations = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                    st.push(s[i]);
                }
            else if(s[i]==')'){
                if(st.empty()){
                    operations++;
                }
                else 
                st.pop();
            }

        }
        while(!st.empty()){
            operations++;
            st.pop();
        }
        return operations;
    }
};