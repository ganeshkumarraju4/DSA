class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

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
            done++;

            for (auto nxt : adj[node]) {
                if (--indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        return done == numCourses;
    }
};