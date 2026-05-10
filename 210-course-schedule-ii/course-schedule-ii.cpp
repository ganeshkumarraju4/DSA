class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;

        for (auto &p : prerequisites) {
            int u = p[0], v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int done = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            done++;

            for (auto nxt : adj[node]) {
                if (--indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        if(done == numCourses)
        {
             return ans;
        }
        else return {};
    }
};