class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());
        int len = restrictions.size();
        if(restrictions[len-1][0]!= n)restrictions.push_back({n,n-1});
        len = restrictions.size()-1;
        
        
        int maxheight = 0;
        
        for(int i = 1;i<=len;i++){
            int dist = restrictions[i][0] - restrictions[i-1][0];
           restrictions[i][1] = min(restrictions[i][1],restrictions[i-1][1] + dist);

        }
        for(int i = len-1;i>=0;i--){
            int dist = restrictions[i+1][0] - restrictions[i][0];
           restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1] + dist);
           
        }
        for(int i=0;i < len;i++){
            int dist = restrictions[i+1][0] - restrictions[i][0];
            int peak = (restrictions[i][1] + restrictions[i+1][1] + dist)/2;
            maxheight = max(maxheight,peak);
        }
        return maxheight;
    }
};