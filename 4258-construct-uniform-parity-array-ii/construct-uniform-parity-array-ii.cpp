class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        pair<int,int> son = {INT_MAX,-1};

        for(int i=0;i<n;i++){
            if(nums1[i]%2==1){
                if(nums1[i]<son.first){
                    son.first = nums1[i];
                    son.second = i;
                }
            }
        }

        //convert all elements to odd
        int odd = 0;
        int even = 0;
        int flag = 0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                if(son.first<nums1[i] && son.second!=i){
                    odd++;
                }
                else flag = 1;
            }
            else odd++;

            if(flag)break;
        }
        flag = 0;
        //all elements to even
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                if(son.first<nums1[i] && son.second!=i){
                    even++;
                }
                else flag = 1;
            }
            else even++;

            if(flag)break;
        }
        cout<<odd<<even;
        if(odd==n || even == n)return true;

        return false;
        
    }
};