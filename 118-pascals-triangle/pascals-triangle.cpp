class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j<=i;j++){
                if(j == 0 || j==i){
                    ans[i].push_back(1);
                }
                else{
                    int temp = ans[i-1][j-1] + ans[i-1][j];
                    ans[i].push_back(temp);
                }
            }
        }
        return ans;
    }
};