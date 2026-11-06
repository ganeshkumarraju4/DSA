class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        
        int k = queries.size();

        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
        });
        

        vector<pair<int,int>> q(k);

        for(int i=0;i<k;i++){
            q[i]= {queries[i],i};
        }

        sort(q.begin(),q.end());
        unordered_map<int,int> map;
        vector<int> ans(k);
        int l = 0;
        int r = 0;
        for(auto [t,i]:q){
            //expansion
            while(r<m && logs[r][1]<=t){
                map[logs[r][0]]++;
                r++;
            }
            //shrinking
           while(l<m && logs[l][1]<t-x){
                map[logs[l][0]]--;
                if(map[logs[l][0]]==0){
                    map.erase(logs[l][0]);
                }
                l++;
           }

           ans[i] = n - map.size();
           
            
        }
        return ans;
    }
};