class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;
            if (cnt < 2) continue;

            long long root = sqrt(x);
            if (root * root == x && freq.count(root) && freq[root] >= 2)
                continue;

            long long cur = x;
            int len = 0;

            while (freq.count(cur) && freq[cur] >= 2) {
                len += 2;

                if (cur > 31622) break;   // prevent overflow
                cur = cur * cur;
            }

            if (freq.count(cur) && freq[cur] == 1)
                len += 1;
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};