class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,bool> m;
        int maxi = 0;
        for(int i = 0;i< n;i++){
            if(nums[i]>0){
                m[nums[i]] = 1;
                maxi = max(maxi,nums[i]);
            }
        }
       
        for(int i = 1;i< maxi;i++){
            if(m.find(i)==m.end()){
                
                return i;
            }
        }
       
        return maxi + 1;
    }
};