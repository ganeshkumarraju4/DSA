class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>>dp(m,vector<vector<bool>>(n,vector<bool>(1024,0)));
        if(m==1 && n==1)return grid[0][0];
        int ans = INT_MAX;
        dp[0][0][grid[0][0]] =true;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                for(int k=0;k<1024;k++){
                    if(j-1>=0 && dp[i][j-1][k]!=false){
                       int x = k^grid[i][j];
                        dp[i][j][x] = true;
                         if(i==m-1 && j==n-1){
                        ans = min(ans,x);
                    }
                    }
                     if(i-1>=0 && dp[i-1][j][k]!=false){
                       int x = k^grid[i][j];
                        dp[i][j][x] = true;
                         if(i==m-1 && j==n-1){
                        ans = min(ans,x);
                    }
                    }
                   
                }
            }
        }
        return ans;
    }
};