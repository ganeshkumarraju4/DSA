class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m == 1 && n == 1 )return 0;
        vector<vector<int>> dist(m,vector<int> (n,1e9));
         priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};

        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            for(int i = 0;i<4;i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if(nr >=0 && nr < m && nc >= 0 && nc <n){
                    int dh = abs(heights[nr][nc] - heights[r][c]);
                    int mdh = max(dh,d);
                    if(  mdh < dist[nr][nc]){
                        pq.push({mdh,{nr,nc}});
                        dist[nr][nc] = mdh;
                    }
                }
            }

        }
        return dist[m-1][n-1];
    }
};