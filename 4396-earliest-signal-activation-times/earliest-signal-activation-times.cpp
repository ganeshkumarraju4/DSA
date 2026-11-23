

class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:edges) {
            int u=edge[0];
            int v=edge[1];
            int d=edge[2];
            adj[u].push_back({v,d});
        }

        vector<long long> ans(n,-1);
        vector<int>& req=requiredSignals;
        req[0]=1;
        
        #define pli pair<long long,int>
        priority_queue<pli,vector<pli>,greater<pli>> heap;
        heap.push({0,0});

        while(!heap.empty()) {
            auto [T,u]=heap.top();
            heap.pop();
            req[u]--;
            if(!req[u]) {
                ans[u]=T;
                req[u]=n+1;
                for(auto& [v,d]:adj[u])
                    heap.push({T+d,v});
            }
        }

        return ans;
    }
};