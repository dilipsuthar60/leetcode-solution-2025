class Solution
{
public:
    vector<int>ans;
    void find(TreeNode*root,int level){
        if(!root) return ;
        if(level>ans.size()){
            ans.push_back(root->val);
        }
        find(root->right,level+1);
        find(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        find(root,1);
        return ans;
    }
};