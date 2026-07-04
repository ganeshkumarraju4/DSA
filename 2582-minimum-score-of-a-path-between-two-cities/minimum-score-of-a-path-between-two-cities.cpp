class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1,0);
       queue<int> q;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        q.push(1);
        vis[1] = 1;
        int minDist = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                int adjnode = it.first;
                int weight = it.second;
                minDist = min(minDist,weight);
                if(!vis[adjnode]){
                    q.push(adjnode);
                    vis[adjnode]=1;
                }
            }
        
        }
        return minDist;
    }
};