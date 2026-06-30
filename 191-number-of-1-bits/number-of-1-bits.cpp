class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n>0){
            int x = n;
            n = n >> 1;
            if((2*n)+1 == x){
                count++;
            }
        }
        return count;
    }
};