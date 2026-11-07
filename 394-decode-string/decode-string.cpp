class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        
        int n = s.size();
        string ans = "";
        for(char c:s){
            if(c==']'){
                string temp = "";
vector<string> v;

while(!st.empty() && st.top() != "[") {
    v.push_back(st.top());
    st.pop();
}

while(!v.empty()) {
    temp += v.back();
    v.pop_back();
}
                st.pop();
                string num = "";
                while(!st.empty() && (st.top()>="0" && st.top()<="9")){
                    num += st.top();
                    st.pop();
                }
                int m;
                if(num.size()>0){
                    reverse(num.begin(),num.end());
                    m = stoi(num);
                }
                else m = 1;
                string x = "";
                while(m>0){
                    x += temp;
                    m--;
                }

                st.push(x);
            }
            else {
                string x ="";
                x+=c;
                st.push(x);}
           
        }
       vector<string> v;

while(!st.empty()) {
    v.push_back(st.top());
    st.pop();
}

reverse(v.begin(), v.end());

for(auto &x : v) {
    ans += x;
}
return ans;
    }
};