class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> best(m,vector<int>(n));
        if(grid[0][0]==0){
            pq.push({health,{0,0}});
        }
        else pq.push({health-1,{0,0}});
        best[0][0] = health - grid[0][0];

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == m-1 && c == n-1 && h >= 1)return true;
            for(int i = 0;i<4;++i){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if (h < best[r][c]) continue;
                if(nr>=0 && nr < m && nc >=0 && nc < n ){
                    int newHealth = h-grid[nr][nc];
                    if(newHealth >= 1 && newHealth > best[nr][nc]){
                        best[nr][nc] = newHealth;
                        pq.push({newHealth,{nr,nc}});
                        
                    }
                }
            }
        }
        return false;
    }
};