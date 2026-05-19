class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)return -1;
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int disconnected = 0;
        vector<int> vis(n,0);
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(!vis[i]){
                disconnected++;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        return disconnected - 1;
       
    }   
};