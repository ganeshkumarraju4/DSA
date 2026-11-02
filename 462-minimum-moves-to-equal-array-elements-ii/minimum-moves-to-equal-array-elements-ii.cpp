class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int a = n/2;
        int b = n/2-1;
        long long  count = 0;
        for(int i=0;i<n;i++){
            count += abs(nums[i]-nums[a]);
        }
        long long  ans = count;
        
        if(b<n && b>0){
            count = 0;
            for(int i=0;i<n;i++){
                count+= abs(nums[i]-nums[b]);
            }
        }
        ans = min(ans,count);
        return (int)ans;
    }
};