class Solution {
public:
    bool Check(string &s,vector<vector<int>> &dp,int i,int cnt){
        if(i==s.size()){
            if(cnt==0)return 1;
            return 0;
        }
        if(cnt<0)return 0;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        if(s[i]=='(')dp[i][cnt]=Check(s,dp,i+1,cnt+1);
        if(s[i]==')')dp[i][cnt]=Check(s,dp,i+1,cnt-1);

        if(s[i]=='*'){
            dp[i][cnt] = Check(s,dp,i+1,cnt+1)||Check(s,dp,i+1,cnt-1)||
            Check(s,dp,i+1,cnt);
        }
        return dp[i][cnt];
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return Check(s,dp,0,0);
    }
};