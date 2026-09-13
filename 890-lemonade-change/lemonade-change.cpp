class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0;
        unordered_map<int,int> m;
        for(int x:bills){
            if(x==5){
                m[5]++;
                change += 5;
            }
            else {
                if(change< x-5)return false;
                else {
                    if(x-5==5){
                        if(m[5]>0){
                            m[5]--;
                            change -= 5;
                            m[x]++;
                            change += x;
                        }
                        else return false;
                    }
                    else if(x-5==15){
                        if(m[5]>0 && m[10]>0){
                            m[5]--;m[10]--;
                            change-=15;
                            m[x]++;
                            change += x;
                        }
                        else if(m[5]>=3){
                            m[5]-=3;
                            change-=15;
                            m[x]++;
                            change+=x;
                        }
                        else return false;
                    }
                }
            }
        }
        return true;
    }
};