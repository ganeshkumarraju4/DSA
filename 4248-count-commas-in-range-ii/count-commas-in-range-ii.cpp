class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        if(n>=1e15){
            count+= (n-1e15+1)*5+(1e15-1e12)*4+(1e12-1e9)*3+(1e9-1e6)*2+(1e6-1e3);
        }
        else if(n>=1e12){
            count+=(n-1e12+1)*4+(1e12-1e9)*3+(1e9-1e6)*2+(1e6-1e3);
        }
        else if(n>=1e9){
           count+= (n-1e9+1)*3+(1e9-1e6)*2+(1e6-1e3);
        }
        else if(n>=1e6){
            count+=(n+1-1e6)*2+(1e6-1e3);
        }
        else if(n>=1e3){
            count+=(n+1-1e3);
        }
        else return 0;

        return count;
    }
};