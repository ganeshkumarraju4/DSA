class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {

                if (board[r][c] == 'X') continue;
                if (r == n - 1 && c == n - 1) continue;

                int best = -1;
                int count = 0;

                // down
                if (r + 1 < n && score[r + 1][c] != -1) {
                    best = score[r + 1][c];
                    count = ways[r + 1][c];
                }

                // right
                if (c + 1 < n && score[r][c + 1] != -1) {
                    if (score[r][c + 1] > best) {
                        best = score[r][c + 1];
                        count = ways[r][c + 1];
                    }
                    else if (score[r][c + 1] == best) {
                        count = (count + ways[r][c + 1]) % MOD;
                    }
                }

                // diagonal
                if (r + 1 < n && c + 1 < n &&
                    score[r + 1][c + 1] != -1) {

                    if (score[r + 1][c + 1] > best) {
                        best = score[r + 1][c + 1];
                        count = ways[r + 1][c + 1];
                    }
                    else if (score[r + 1][c + 1] == best) {
                        count = (count + ways[r + 1][c + 1]) % MOD;
                    }
                }

                if (best == -1) continue;

                int val = 0;
                if (isdigit(board[r][c])) {
                    val = board[r][c] - '0';
                }

                score[r][c] = best + val;
                ways[r][c] = count;
            }
        }

        if (score[0][0] == -1) return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};