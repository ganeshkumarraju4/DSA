class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            rows[seat[0]] |= (1 << seat[1]);
        }

        int ans = (n - rows.size()) * 2;

        int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &[row, mask] : rows) {

            bool left = (mask & leftMask) == 0;
            bool right = (mask & rightMask) == 0;

            if (left && right) {
                ans += 2;
            }
            else if (left || right) {
                ans += 1;
            }
            else if ((mask & middleMask) == 0) {
                ans += 1;
            }
        }

        return ans;
    }
};