class Solution {
public:
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        // {end, start, profit}
        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        // Sort by end time
        sort(jobs.begin(), jobs.end());

        // Store end times
        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            ends[i] = jobs[i][0];
        }

        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            int end = jobs[i][0];
            int start = jobs[i][1];
            int p = jobs[i][2];

            // Last job whose end <= start
            int j = upper_bound(ends.begin(), ends.begin() + i, start)
                    - ends.begin() - 1;

            // Take current job
            int take = p;

            if (j >= 0)
                take += dp[j];

            // Don't take current job
            int skip = (i > 0) ? dp[i - 1] : 0;

            dp[i] = max(take, skip);
        }

        return dp[n - 1];
    }
};