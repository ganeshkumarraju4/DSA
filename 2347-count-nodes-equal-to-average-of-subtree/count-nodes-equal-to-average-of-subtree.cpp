/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> Solve(TreeNode* root,int &count){
        if(root==NULL)return {0,0};

        pair<int,int> l,r;
        l = Solve(root->left,count);
        r = Solve(root->right,count);
        int sum = l.first+r.first+root->val;
        int n = l.second+r.second+1;
        if(sum/n==root->val)count++;

        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        Solve(root,count);

        return count;
    }
};