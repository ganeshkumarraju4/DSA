class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for(int i = 0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-nums[0]) %x != 0)return -1;
        }
        int mid=nums.size()/2;
        int count=0;
        for(int i=0;i<nums.size();i++){
            count += (abs(nums[i]-nums[mid])/x);
        }
        return count;
    }
};