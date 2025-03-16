class Solution
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root) return {};

        vector<int>rightView;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(i==size-1){
                    rightView.push_back(temp->val);
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
        return rightView;
    }
};