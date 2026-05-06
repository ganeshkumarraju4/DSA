class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
      
        vector<vector<int>> v(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 || i == m-1 ||
                    j == 0 || j == n-1 ){
                        if(board[i][j] =='O'){
                            q.push({i,j});
                            
                            v[i][j]=1;}
                    }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
           
            q.pop();
           
            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && v[nr][nc]==0){
                    if(board[nr][nc] =='O'){
                        q.push({nr, nc});
                       
                        v[nr][nc]=1;
                    }
                }
            }
           
                
        }
         for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(v[i][j]!=1)board[i][j]='X';
                }
            }
    }
};