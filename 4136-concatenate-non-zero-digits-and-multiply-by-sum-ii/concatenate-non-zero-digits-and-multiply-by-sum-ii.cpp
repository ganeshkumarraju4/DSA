class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        // cnt[i] = number of non-zero digits in s[0 ... i-1]
        vector<int> cnt(n + 1, 0);

        // digit prefix sum on original string
        vector<long long> sumPref(n + 1, 0);

        vector<int> digits;

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            cnt[i + 1] = cnt[i] + (d != 0);
            sumPref[i + 1] = sumPref[i] + d;

            if (d != 0) {
                digits.push_back(d);
            }
        }

        int k = digits.size();

        // powers of 10
        vector<long long> power10(k + 1, 1);

        for (int i = 1; i <= k; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // numeric prefix of compressed non-zero digits
        vector<long long> pref(k + 1, 0);

        for (int i = 0; i < k; i++) {
            pref[i + 1] =
                (pref[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // corresponding range in compressed digits
            int L = cnt[l];
            int R = cnt[r + 1];

            int len = R - L;

            // extract concatenated number
            long long x =
                (pref[R]
                - pref[L] * power10[len] % MOD
                + MOD) % MOD;

            // zeros contribute nothing, so ordinary digit prefix sum works
            long long sum =
                (sumPref[r + 1] - sumPref[l]) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};