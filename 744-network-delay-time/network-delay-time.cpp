class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        vector<int> t(n + 1,1e9);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > pq;
        pq.push({0,k});
        t[k] = 0;
       
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjnode = it.first;
                int travelTime = it.second;
                if(travelTime + time < t[adjnode]){
                    pq.push({travelTime + time, adjnode});
                     t[adjnode] = time + travelTime;
                }
            }
        }
       int ans = 0;

        for(int i = 1; i <= n; i++){

            if(t[i] == 1e9) return -1;

            ans = max(ans, t[i]);
        }

        return ans;
    }
};