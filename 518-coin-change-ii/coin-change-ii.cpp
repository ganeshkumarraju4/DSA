class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+1,0);
        dp[0] = 1;

      int g = 0;
bool hasAmountCoin = false;

for (int c : coins) {
    if (c == amount)
        hasAmountCoin = true;
    else if (c < amount)
        g = std::gcd(g, c);
}

if (g != 0 && amount % g != 0)
    return hasAmountCoin ? 1 : 0;
        for(int coin:coins){
            for(int i=coin;i<=amount;i++){
                dp[i] += dp[i-coin];
            }
        }
        return (int)dp[amount];
    }
};