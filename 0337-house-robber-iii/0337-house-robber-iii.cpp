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
    pair<int,int>find(TreeNode* root){
        if(root==NULL) return {0,0};

        auto left=find(root->left);
        auto right=find(root->right);
        pair<int,int>newPair;
        newPair.first=root->val+left.second+right.second;
        newPair.second=max(left.first,left.second)+max(right.first,right.second);
        return newPair;
    }
    int rob(TreeNode* root) {
        auto overAllPairResult=find(root);
        return max(overAllPairResult.first, overAllPairResult.second);
    }
};