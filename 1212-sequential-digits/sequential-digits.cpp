class Solution {
public:
    void generate(int low,int high, vector<int> &ans,int i,int num){
        if(num >= low && num <= high){
            ans.push_back(num);
        }
        if(num > high || i > 9)return;
        
        generate(low,high,ans,i+1,num*10+i);
        
    }
    vector<int> sequentialDigits(int low, int high) {
        // int stDigit = 0;
        // int num = low;
        // while(num > 0){
        //     stDigit = num%10;
        //     num = num/10;
        // }
        int num = 0;
        vector<int> ans;
        for(int i = 1;i<=9;i++){
            generate(low,high,ans,i+1,num*10+i);
            num = 0;
        }
      
        sort(ans.begin(),ans.end());
        return ans;
    }
};