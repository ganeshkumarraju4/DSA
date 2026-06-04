class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i = 0;i < nums.size();i++){
            int key = nums[i];
            if(m.find(key) == m.end()){
                m[key] = i;
            }
            else {
                if(abs(i-m[key]) <= k)return true;
                else m[key] = i;
            }
        }
        return false;
    }
};