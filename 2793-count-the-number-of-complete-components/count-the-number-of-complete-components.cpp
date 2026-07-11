class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            queue<int> q;
            if(!vis[i]){
                int edgeCount = 0;
                q.push(i);
                vis[i] =1;
                int n = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    n++;
                    for(auto it:adj[node]){
                        edgeCount++;
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
                 if(n==1 || (edgeCount == n*(n-1)))count++;
            }
           
        }
        return count;
    }
};