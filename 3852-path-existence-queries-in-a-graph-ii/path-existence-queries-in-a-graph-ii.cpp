class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        // 1. Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // 2. Sort by value
        sort(arr.begin(), arr.end());

        // pos[original index] = sorted position
        vector<int> pos(n);

        // sorted values
        vector<int> val(n);

        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        // 3. Build connected components
        vector<int> comp(n);
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];

            if (val[i] - val[i - 1] > maxDiff) {
                comp[i]++;
            }
        }

        // 4. Binary lifting table
        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG, vector<int>(n));

        // up[0][i] = farthest position reachable
        // from i using exactly one greedy jump
        int r = 0;

        for (int i = 0; i < n; i++) {
            if (r < i) {
                r = i;
            }

            while (r + 1 < n &&
                   val[r + 1] - val[i] <= maxDiff) {
                r++;
            }

            up[0][i] = r;
        }

        // 5. Build binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        // 6. Answer queries
        vector<int> ans;

        for (auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v) {
                swap(u, v);
            }

            // Same node
            if (u == v) {
                ans.push_back(0);
                continue;
            }

            // Different components
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            int cur = u;

            // Take largest jumps that still stay before v
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            // One final jump reaches v
            steps++;

            ans.push_back(steps);
        }

        return ans;
    }
};