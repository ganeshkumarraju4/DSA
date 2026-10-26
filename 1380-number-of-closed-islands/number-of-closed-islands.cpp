class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans = 0;
        queue<pair<int,int>> q;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    bool stop = false;
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();
                        if(r==0 || c==0 || r==m-1 || c==n-1){
                            stop = true;
                            
                        }
                        for(int k = 0;k<4;k++){
                            int nr = r+dr[k];
                            int nc = c+dc[k];
                            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0 && vis[nr][nc]==0){
                                q.push({nr,nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                    if(stop==false){
                        ans++;
                    }
                
            }
            }
        }
        return ans;
    }
};