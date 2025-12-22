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
    int result=0;
    pair<int,int>find(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto left=find(root->left);
        auto right=find(root->right);
        pair<int,int>ans={1,1}; // inc, dic
        if(root->left){
            if(root->val-root->left->val==1){
                ans.first=left.first+1;
            }
            if(root->left->val-root->val==1){
                ans.second=left.second+1;
            }
        }
        if(root->right){
            if(root->val-root->right->val==1){
                ans.first=max(ans.first,right.first+1);
            }
            if(root->right->val-root->val==1){
                ans.second=max(ans.second,right.second+1);
            }
        }
        result=max(result,ans.first+ans.second-1);
        return ans;
    }
    int longestConsecutive(TreeNode* root) {
        find(root);
        return result;
    }
};