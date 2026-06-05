class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int count = 0;
        for(auto it: nums){
            prefix += it;
           int x = ((prefix % k) + k) % k;
            if(m.find(x) != m.end()){
                count += m[x];
            }
            m[x]++;
        }
        return count;
    }
};