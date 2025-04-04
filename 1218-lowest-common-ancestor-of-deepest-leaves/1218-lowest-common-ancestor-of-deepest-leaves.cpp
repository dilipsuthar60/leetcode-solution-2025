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
    int find(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        return 1+max(find(root->left),find(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        if(root==NULL)
        {
            return root;
        }
        int left=find(root->left);
        int right=find(root->right);
        if(left==right)
        {
            return root;
        }
        if(left>right)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
            return lcaDeepestLeaves(root->right);
        }
    }
};