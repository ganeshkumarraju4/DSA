class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)return -1;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > pq;

        pq.push({1,{0,0}});
        dist[0][0] = 1;
        int dr[] = {0,1,0,-1,-1,-1,1,1};
        int dc[] = {1,0,-1,0,-1,1,1,-1};
        
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i = 0; i< 8;i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if(nr >=0 && nr < n && nc >=0 && nc < n ){
                    if(grid[nr][nc] == 0 &&  d +1 < dist[nr][nc]){
                        dist[nr][nc] = d + 1;
                        pq.push({d+1,{nr,nc}});
                    }
                }
            }
        }
        if(dist[n-1][n-1]!= 1e9)return dist[n-1][n-1];
        else return -1;
    }
};