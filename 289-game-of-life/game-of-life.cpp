class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copy(m,vector<int> (n));
        for(int i = 0;i < m;i++){
            for(int j = 0 ;j<n;j++){
                copy[i][j] = board[i][j];
            }
        }
        int dr[] = {0,1,0,-1,1,1,-1,-1};
        int dc[] = {1,0,-1,0,1,-1,-1,1};
        for(int i = 0;i < m;i++){
            for(int j = 0 ;j<n;j++){
                int neig = 0;
                    for(int k = 0;k<8;k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr>=0 && nr < m && nc >=0 && nc < n && copy[nr][nc])
                        neig++;
                    }
                if(board[i][j]){
                    if(neig < 2 || neig > 3)board[i][j] = 0;
                }
                else {
                    if(neig == 3)board[i][j] = 1;
                }
            }
        }

    }
};