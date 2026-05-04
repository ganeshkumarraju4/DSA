class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oc = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        int vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        queue<pair<pair<int,int>,int>> q;
        image[sr][sc]=color;
        q.push({{sr,sc},color});
        vis[sr][sc]=1;

        int drow[]={0,1,-1,0};
        int dcol[]={1,0,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int neir = drow[i]+r;
                int neic = dcol[i] + c;
                if(neir>=0 && neir<m && neic>=0 && neic <n && 
                    image[neir][neic]==oc && !vis[neir][neic]){
                        q.push({{neir,neic},color});
                        image[neir][neic] = color;
                        vis[neir][neic]=1;
                    }
            }
        }
        return image;
    }
};