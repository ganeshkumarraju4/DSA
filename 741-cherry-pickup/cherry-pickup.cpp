class Solution {
public:
    int solve(vector<vector<vector<int>>> &dp,vector<vector<int>>& grid, int r1, int c1, int r2,int n){
        int c2 = r1+c1-r2;
        if(r1>=n || r2>=n || c1>=n || c2>=n )
        return -1e9;

        if(grid[r1][c1]==-1 || grid[r2][c2]==-1)
        return -1e9;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];

        int cherries = 0;
        if(r1==r2 && c1==c2){
            cherries += grid[r1][c1];
        }
        else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }
        int best = max({
            solve(dp,grid, r1 + 1, c1, r2 + 1,n), // both down
            solve(dp,grid, r1 + 1, c1, r2,n),     // P1 down, P2 right
            solve(dp,grid, r1, c1 + 1, r2 + 1,n), // P1 right, P2 down
            solve(dp,grid, r1, c1 + 1, r2,n)      // both right
        });

        cherries += best;
        return dp[r1][c1][r2] = cherries;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n;
        vector<vector<vector<int>>> dp;
        n = grid.size();

        dp.assign(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n, -1)
            )
        );

        int ans = solve(dp,grid, 0, 0, 0,n);

        return max(0, ans);
    }
};