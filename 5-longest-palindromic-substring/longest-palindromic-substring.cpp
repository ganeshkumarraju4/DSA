class Solution {
public:
    int expand(int i,int j,string s){
        while(i>=0 && j < s.size() && s[i]==s[j]){
            i--;j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int longest = 0;
        int index = 0;
        int n = s.size();
        int l1 = 0,l2 = 0;
        for(int i = 0;i<n;i++){

           l1 = expand(i,i,s);
           if(i+1 < n)
           l2 = expand(i,i+1,s);
           int len = max(l1,l2);
            if(len > longest){
                int start = i-(len-1)/2;
                index = start;
                longest = len;
            }
        }
        return s.substr(index,longest);
    }
};