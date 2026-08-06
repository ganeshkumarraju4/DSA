class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        if(n==1)return triangle[0][0];
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0] = triangle[0][0];

        int mini = INT_MAX;

        for(int i =1 ;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j==triangle[i].size()-1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }

                if(i==n-1){
                    mini = min(mini,dp[i][j]);
                }
            }
        }
        return mini;
    }
};