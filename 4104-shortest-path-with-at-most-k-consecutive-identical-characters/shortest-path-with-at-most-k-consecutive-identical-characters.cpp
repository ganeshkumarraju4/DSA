class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        
        // dist[u][streak] stores the minimum weight to reach node u with a given streak of identical labels
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        
        // Min-heap storing: {weight, {node, streak}}
        priority_queue<
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>
        > pq;

        // Start at node 0 with weight 0 and initial label streak of 1
        dist[0][1] = 0;
        pq.push({0, {0, 1}});
        
        while (!pq.empty()) {
            auto [weight, p] = pq.top();
            auto [node, streak] = p;
            pq.pop();
            
            if (node == n - 1) return weight;
            
            if (weight > dist[node][streak]) continue;
            
            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edgeCost = it.second;
                
                // Calculate the new consecutive identical label streak
                int nextStreak = (labels[node] == labels[adjNode]) ? streak + 1 : 1;
                
                if (nextStreak <= k) {
                    int newCost = weight + edgeCost;
                    if (newCost < dist[adjNode][nextStreak]) {
                        dist[adjNode][nextStreak] = newCost;
                        pq.push({newCost, {adjNode, nextStreak}});
                    }
                }
            }
        }
        
        return -1;
    }
};