class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // int zeroes=0;
        // for(int i =0;i<m;i++){
        //     for(int j =0;j<n;j++){
        //         if(grid[i][j]== '0')zeroes++;
        //     }
        // }
        // if(zeroes==0)return 0;
        int count = 0;
         int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0}; 
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i = 0;i < m; i++){
            for(int j = 0;j < n; j++){
                if(grid[i][j]== '1' && !v[i][j]){
                    count++;
                    q.push({i,j});
                     while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
                v[r][c]=1;
               
            for(int i = 0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'
                    && v[nr][nc]!=1){
                        q.push({nr,nc});
                        v[nr][nc]=1;
                    }
            }
            
        }
                }
            }
        }
       
      return count;
    }
};