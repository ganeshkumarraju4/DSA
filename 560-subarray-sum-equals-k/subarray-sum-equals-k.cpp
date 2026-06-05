class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;
        int count = 0;
        int prefix = 0;
        for(auto it: nums){
            prefix += it;
            if(m.find(prefix-k)!= m.end()){
                count += m[prefix-k];
            }
            m[prefix]++;
        }
        return count;
    }

};