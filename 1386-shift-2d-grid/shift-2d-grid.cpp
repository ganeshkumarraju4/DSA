class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        while(k>0){
         int temp = grid[m-1][n-1];
           for(int i=0;i<m;i++){
            for(int j= 0;j<n;j++){
                int a = grid[i][j];
                grid[i][j] = temp;
                temp  = a;
           }
           }
            k--;
        }
        return grid;
    }
};