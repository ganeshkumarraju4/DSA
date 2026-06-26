class Solution {
public:
    int leastFreq(unordered_map<char,int> &hash){
        int least = INT_MAX;
        for(auto it: hash){
            least = min(least,it.second);
        }
        return least;
    }
    int mostFreq(unordered_map<char,int> &hash){
        int most = INT_MIN;
        for(auto it: hash){
            most = max(most,it.second);
        }
        return most;
    }
    int beautySum(string s) {
        int n = s.size();
        if(n==1)return 0;
        int sum  = 0;

        for(int i = 0;i<s.size();i++){
            unordered_map<char,int> hash;

            for(int j = i;j<n;j++){
                hash[s[j]]++;
                int least = leastFreq(hash);
                int most = mostFreq(hash);
                sum += most - least;
            }
        }
        return sum;
    }
};