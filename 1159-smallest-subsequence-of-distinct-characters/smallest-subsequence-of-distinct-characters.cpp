class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> index(26,0);
        vector<bool> vis(26, false);
        stack<char> st;

        for(int i = 0;i<s.size();i++){
            index[s[i]-'a'] = i;
        }

            for (int i = 0; i < s.size(); i++) {

            if (vis[s[i]-'a'])
                continue;

            while (!st.empty() &&
                st.top() > s[i] &&
                index[st.top()-'a'] > i) {

                vis[st.top()-'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};