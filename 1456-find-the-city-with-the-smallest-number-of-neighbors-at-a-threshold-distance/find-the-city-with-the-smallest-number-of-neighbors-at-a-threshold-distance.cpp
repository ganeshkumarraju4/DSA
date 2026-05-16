class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> neig(n,0);
      
      
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
         priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > pq;
        for(int i = 0; i < n;i++){
            vector<int> vis(n,0);
            vector<int> d(n,1e9);
            pq.push({0,i});
            vis[i] =1;
            d[i] = 0;

            while(!pq.empty()){
                int dist = pq.top().first;
                int node = pq.top().second;
               
                pq.pop();
                for(auto it: adj[node]){
                    int adjnode = it.first;
                    int edw = it.second;
                    int newdist = edw + dist;
                    if(newdist < d[adjnode] &&  newdist <= distanceThreshold){
                        pq.push({newdist, adjnode});
                        d[adjnode] = newdist;
                        if(!vis[adjnode]){
                            neig[i]++;
                            vis[adjnode] = 1;
                        }
                    }
                }
            }
        }

        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i< n;i++){
            if(neig[i] <= mini){
                mini = neig[i];
                ans = i;
            }
        }
    return ans;
    }
};