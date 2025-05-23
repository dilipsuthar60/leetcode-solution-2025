class Solution {
public:
    void find(TreeNode*root,int sum,vector<int>curr,vector<vector<int>>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        curr.push_back(root->val);
        sum-=root->val;
        if(root->left==root->right&&sum==0){
            ans.push_back(curr);
        }
        find(root->left,sum,curr,ans);
        find(root->right,sum,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>curr;
        find(root,targetSum,curr,ans);
        return ans;
    }
};