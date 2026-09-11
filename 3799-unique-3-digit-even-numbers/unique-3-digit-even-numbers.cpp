class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int x:digits){
            freq[x]++;
        }
        int count = 0;
        for(int i=1;i<10;i++){
            int x = freq[i]--;
            for(int j=0;j<10;j++){
                int y=freq[j]--;
                for(int k=0;k<10;k++){
                   int z=freq[k]--;
                    if(x>0 && y>0 && z>0){
                       if(k%2==0)count++;
                    }
                    freq[k]++;
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return count;
    }
};