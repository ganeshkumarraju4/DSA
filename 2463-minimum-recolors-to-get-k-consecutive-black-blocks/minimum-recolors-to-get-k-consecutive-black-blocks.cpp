class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        
        int n = blocks.size();
        for(int i =0;i <k;i++){
            if(blocks[i] == 'W')whiteCount++;
        }
        int recolors = whiteCount;
        for(int i = k;i < n;i++){
            if(blocks[i] == 'W')whiteCount++;
            if(blocks[i-k]=='W')whiteCount--;
            recolors = min(recolors,whiteCount);
        }
        return recolors;
    }
};