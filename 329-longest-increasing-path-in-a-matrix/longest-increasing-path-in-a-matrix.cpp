class Solution {
public:
    int dr[4] = {-1,0,0,1};
    int dc[4] = {0,-1,1,0};
    int Solve(vector<vector<int>> &dp,int i,int j,vector<vector<int>>& matrix){
        
        if(dp[i][j])return dp[i][j];

         dp[i][j] = 1;
         
        for(int k=0;k<4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if(nr>=0 && nr< matrix.size() && nc>=0 && nc<matrix[0].size() && matrix[nr][nc]>matrix[i][j]){
                dp[i][j] = max(dp[i][j],1+Solve(dp,nr,nc,matrix));
            }
        }
        
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp = Solve(dp,i,j,matrix);
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};