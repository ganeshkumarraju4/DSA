class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        
    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                } else {
                    dist[i][j] = 1e9; 
                }
            }
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
           
            q.pop();
           
            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n ){
                    if(dist[nr][nc] > dist[r][c] + 1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
        
    }
};