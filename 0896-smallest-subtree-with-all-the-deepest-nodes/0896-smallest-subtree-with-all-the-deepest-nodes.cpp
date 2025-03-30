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
    TreeNode*find(TreeNode*root,int x,int y)
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->val==x||root->val==y)
        {
            return root;
        }
        TreeNode*left=find(root->left,x,y);
        TreeNode*right=find(root->right,x,y);
        if(left!=NULL&&right!=NULL)
        {
            return root;
        }
        return left==NULL?right:left;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        TreeNode*left_most=NULL;
        TreeNode*right_most=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto temp=q.front();
                q.pop();
                if(i==0)
                {
                    left_most=temp;
                }
                if(i==n-1)
                {
                    right_most=temp;
                }
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
        }
        return find(root,left_most->val,right_most->val);
    }
};