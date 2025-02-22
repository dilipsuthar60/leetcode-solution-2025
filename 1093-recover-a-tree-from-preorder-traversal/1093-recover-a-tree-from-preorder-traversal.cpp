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
    int index=0;
    TreeNode* find(string &s,int depth){
        if(index>=s.size()) return NULL;
        int j=index;
        int dashCount=0;
        while(j<s.size()&&s[j]=='-'){
            j++;
        }
        dashCount=(j-index);
        if(dashCount!=depth){
            return NULL;
        }
        index+=dashCount;
        string num="";
        while(j<s.size()&&isdigit(s[index])){
            num+=s[index];
            index++;
        }
        TreeNode* root= new TreeNode(stoi(num));
        root->left=find(s,depth+1);
        root->right=find(s,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return find(traversal,0);
    }
};