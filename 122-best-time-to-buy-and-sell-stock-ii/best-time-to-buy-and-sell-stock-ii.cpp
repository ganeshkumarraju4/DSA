class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1)return 0;
        int l = 0,r = 0;
        int profit = 0;

        while(r < n){
            int value = prices[r] - prices[l];
            if(value < 0)l = r;
            else if(value == 0)r++;
            else{
                profit += value;
                l = r;
                r++;
            }
        }
        return profit;
    }
};