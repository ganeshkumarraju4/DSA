class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                int node = graph[i][j];
                adj[node].push_back(i);
                indegree[i]++;
            }
        }
      
        queue<int> q;
        for(int i = n -1;i>=0;i--){
            if(indegree[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adj[node]){
                if(--indegree[it] == 0)q.push(it);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};