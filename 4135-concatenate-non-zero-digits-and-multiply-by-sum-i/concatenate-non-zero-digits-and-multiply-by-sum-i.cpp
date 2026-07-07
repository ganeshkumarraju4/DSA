class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
          int p = 0;
        while(n > 0){
            int digit = n % 10;
            n = n/10;
          
            if(digit != 0){
                x = x + pow(10,p) * digit;
                sum += digit;
                p++;
            }
        }
        return 1LL * sum * x;
    }
};