/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodes;
        int n = 0;
        while(head){
            nodes.push_back(head->val);
            head = head->next;
            n++;
        }
        int maxSum = 0;
        int twinSum = 0;
        for(int i = 0;i <= (n / 2) - 1;i++){
            twinSum  = nodes[i] + nodes[n-i-1];
            maxSum = max(maxSum,twinSum);
        }
        return maxSum;
    }
};