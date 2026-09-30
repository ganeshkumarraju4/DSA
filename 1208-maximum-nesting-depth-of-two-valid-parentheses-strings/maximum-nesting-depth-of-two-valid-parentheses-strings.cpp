class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int depth = 0;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                if(depth%2!=0){
                    ans[i] = 1;
                
                }
                depth++;
            }
            else{
                if(depth%2==0){
                    ans[i]=1;
                }
                depth--;
            }
        }
        return ans;
    }
};