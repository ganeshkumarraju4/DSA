class DisjointSet{
    public:
    vector<int> rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
      
        for(int i = 0; i <n;i++){
            parent[i] = i;
          
        }
    }
    int findUp(int a){
        if(parent[a] == a)return a;
     return parent[a] = findUp(parent[a]);
    }
    void UnionByRank(int u, int v){
        int up_u = findUp(u);
        int up_v = findUp(v);
        if(up_u == up_v)return;
        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        }
        else if(rank[up_u] > rank[up_v])
        parent[up_v] = up_u;
        else {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extras = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUp(u) == ds.findUp(v)){
                extras++;
            }
            else{
                ds.UnionByRank(u,v);
            }
        }
        int components = 0;
        for(int i =0;i<n;i++){
            if(ds.parent[i]==i)components++;
        }
        int ans = components -1;
        if(extras >= ans)return ans;
        return -1;
    }
};