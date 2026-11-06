class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
       int r = 0;
        int n = nums.size();

        while(r<n){
            
            while(l<n && nums[l]!=0)l++;
            r = l;
            while(r<n && nums[r]==0)r++;
            if(l<n && r<n ){
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
            }
            l++;r++;
        }
    }
};