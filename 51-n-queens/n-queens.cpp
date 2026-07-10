class Solution {
public:
    bool isSafe(vector<string>& temp, int r, int c, int n) {

    // Check upper-left diagonal
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
        if (temp[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
        if (temp[i][j] == 'Q')
            return false;
    }

    return true;
}
    void solve(vector<vector<string>> &ans,vector<string> & temp,int r,int n,vector<int> &col,int q){
        if(r>=n){
            if(q == n){
                ans.push_back(temp);
            }
            return;
        }
        for(int j = 0;j<n;j++){
            if(col[j] == 0){
                
                if(isSafe(temp,r,j,n)){
                    temp[r][j] = 'Q';
                    col[j] = 1;
                    solve(ans,temp,r+1,n,col,q+1);
                }
                temp[r][j] = '.';
                col[j] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        string s = "";
        for(int i = 0;i<n;i++){
            s.push_back('.');
        }
        for(int i =0 ;i<n;i++){
            temp[i] = s;
        }
        vector<vector<string>> ans;
        vector<int> col(n);
        solve(ans,temp,0,n,col,0);
        return ans;
    }
};