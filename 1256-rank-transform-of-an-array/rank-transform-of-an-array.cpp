class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());

        unordered_map<int,int> hash;
        int rank = 1;
        for(int i=0;i<temp.size();i++){
            if(!hash.count(temp[i])){
                hash[temp[i]] = rank;
                rank++;
            }
        }
        for(int i = 0;i<arr.size();i++){
            temp[i] = hash[arr[i]];
        }
        return temp;
    }
};