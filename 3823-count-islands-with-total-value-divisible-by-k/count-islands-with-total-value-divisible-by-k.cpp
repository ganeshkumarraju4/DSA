class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        int ans = 0;
        long long sum = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                    auto [r,c] = q.front();
                    q.pop();
                    sum += grid[r][c];
                    
                    for(int i=0;i<4;i++){
                        int nr = dr[i]+r;
                        int nc = dc[i]+c;
                        if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]!=0){
                            q.push({nr,nc});
                            vis[nr][nc] = 1;

                        }
                    }
                    
                    }  
                     if(sum%k==0)ans++;
                    
                    sum = 0;
                }
            }
        }
       
        return ans;
    }
};