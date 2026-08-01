class Solution {
public:
    
    int Count(int target,vector<int> &dp,int n,int m){
        if(target == n)return 0;
        if(dp[target]!=-1){
            return dp[target];
        }
         int ans = INT_MAX;

        for (int i = m; i >= 1; i--) {
            if (target + i * i <= n) {
                int temp = Count(target + i * i, dp, n, m);
                if (temp != INT_MAX)
                    ans = min(ans, 1 + temp);
            }
        }

        return dp[target] = ans;
    }
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> dp(n+1,-1);
       
        return Count(0,dp,n,m);
        
    }
};