class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        int l = 0;
        int r = 1;
        int profit = 0;
        while(r < n){
            int value = prices[r] - prices[l];
            if(value < 0)l++;
            else if(value>=0){
                profit = max(profit,value);
                r++;
            }
        }
        return profit;
    }
};