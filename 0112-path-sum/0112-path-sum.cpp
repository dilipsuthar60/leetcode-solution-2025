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
    bool find(TreeNode*root, int target){
        if(!root) return false;
        if(root->left==root->right){
            return target-root->val==0;
        }
        if(find(root->left,target-root->val)||find(root->right,target-root->val)){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return find(root,targetSum);
    }
};