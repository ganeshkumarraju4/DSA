class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        vector<bool> Vis(isConnected.size(),false);
       
        int V = isConnected.size() ;
        int count = 0;
        for(int i= 0;i < V;i++){
            if(!Vis[i]){
                count++;
                queue<int> q;
                q.push(i);
                Vis[i]=true;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                   for (int j = 0; j < V; j++) {
                        if (isConnected[node][j] == 1 && !Vis[j]) {
                            Vis[j] = true;
                            q.push(j);
                        }
                    }

                }
            }
        }
        return count;

    }
};