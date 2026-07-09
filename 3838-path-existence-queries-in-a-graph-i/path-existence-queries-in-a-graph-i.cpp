class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        unordered_map<int,int> connection;
        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++){
            int j = upper_bound(nums.begin()+i, nums.end(),  nums[i] + maxDiff)- nums.begin() - 1;
            
            if(j <= i)continue;
            else connection[i] = j;
        }
        for(auto it: queries){
            int u = min(it[0],it[1]);
            int v = max(it[0],it[1]);
            if(u==v){
                ans.push_back(true);
                continue;
            }
            while(u < v){
                if(connection.count(u)){
                    if(connection[u] >= v){
                        ans.push_back(true);
                        break;
                    }
                    else u = connection[u];
                }
                else {
                    ans.push_back(false);
                    break;}
                
            }
        }
    return ans;
    }
};