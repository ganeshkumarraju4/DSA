class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,1e9);
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<flights.size();i++){
            int s = flights[i][0], d = flights[i][1], p = flights[i][2];
            adj[s].push_back({d,p});
        }
        queue<pair<int,pair<int,int>>> q;
        price[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int p = q.front().second.second;
            q.pop();
            if(stops > k+1)continue;
            
           
            for(auto it: adj[node]){
                int adjnode = it.first;
                int edp = it.second;
                if(p + edp < price[adjnode] && stops <= k){
                    price[adjnode] = p + edp;
                    q.push({stops +1,{it.first,p + edp}});
                }
            }
        }
        if(price[dst] != 1e9)return price[dst];
        return -1;
    }
};