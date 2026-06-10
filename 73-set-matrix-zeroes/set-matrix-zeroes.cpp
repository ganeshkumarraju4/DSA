class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroes;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0)zeroes.push_back({i,j});
            }
        }
        for(auto it: zeroes){
            int r = it.first;
            int c = it.second;
            for(int j = 0;j<matrix[0].size();j++){
                matrix[r][j] = 0;
                
            }
            for(int j = 0;j<matrix.size();j++){
                matrix[j][c] = 0;
                
            }
        }
    }
};