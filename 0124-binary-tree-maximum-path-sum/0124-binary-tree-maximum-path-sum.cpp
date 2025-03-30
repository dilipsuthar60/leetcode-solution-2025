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
    int ans;
    int find(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=find(root->left);
        int r=find(root->right);
        ans=max(ans,max(l,0)+max(r,0)+root->val);
        return max({l,r,0})+root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        ans=INT_MIN;
        find(root);
        return ans;
    }
};