class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1,m2;
        vector<vector<int>> ans(2);

        for(int x:nums1){
            if(!m1.count(x)){
                m1[x] = 1;
            }
        }

        for(int x:nums2){
            if(!m2.count(x))m2[x] =1;
        }

        for(auto it:m1){
            if(!m2.count(it.first))ans[0].push_back(it.first);
        }
        for(auto it:m2){
            if(!m1.count(it.first))ans[1].push_back(it.first);
        }
        return ans;
    }
};