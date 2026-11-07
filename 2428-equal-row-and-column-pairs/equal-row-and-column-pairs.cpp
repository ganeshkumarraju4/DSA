class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>,int> m1;
        vector<int> temp(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               temp[j] = grid[i][j];
            }
            m1[temp]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j] = grid[j][i];
            }
            if(m1.count(temp)!=0){
                ans += m1[temp];
            }
        }
        return ans;
    }
};