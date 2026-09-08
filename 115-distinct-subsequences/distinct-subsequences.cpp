class Solution {
public:
    int Solve(vector<vector<int>> &dp,string &s,string &t,int i,int j){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
            take = Solve(dp,s,t,i+1,j+1);
        }
        int skip = Solve(dp,s,t,i+1,j);

        return dp[i][j] = take+skip;
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return Solve(dp,s,t,0,0);
        
    }
};