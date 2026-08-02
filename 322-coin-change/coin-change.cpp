class Solution {
public:
    long long Count(vector<long long>& dp,long long target,int amount,vector<int>& coins){
        if(target == amount)return 0;

        if(dp[target]!=-1)return dp[target];
        long long ans = LLONG_MAX;
        
        for(auto coin:coins){
            if(target+coin <= amount){
              long long  temp = Count(dp,target+coin,amount,coins);
            if(temp!=LLONG_MAX){
                ans = min(ans,1+temp);
            }
        }
        }
        return dp[target] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
       
        vector<long long>dp(amount+1,-1);
        
       long long output = Count(dp,0,amount,coins);
       if(output==LLONG_MAX)return -1;
       else return output;
    }
};