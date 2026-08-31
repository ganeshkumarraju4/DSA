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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        int fc = 0;
        int cc = 0;
        int index = 1;
        int min_dis = INT_MAX;
        int max_dis = -1;
        prev = head;
        head = head->next;
        index++;
        while(head){
            if(head->next){
                if((head->val > prev->val && head->val > head->next->val) ||
                (head->val < prev->val && head->val<head->next->val)){
                    if(fc==0){
                        fc = index;
                    }
                    else {
                        min_dis = min(min_dis,index-cc);
                        max_dis = max(max_dis,index-fc);
                    }
                    cc = index;
                   
                }
            }
            prev = head;
            head = head->next;
            index++;
        }
        if(!fc || fc==cc){
            return {-1,-1};
        }
        return {min_dis,max_dis};
    }
};