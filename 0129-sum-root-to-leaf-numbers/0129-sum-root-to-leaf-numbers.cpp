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
    void inorder(TreeNode* root,int &ans,string currpath){
        if(root==NULL){
            return ;
        }

        currpath=currpath+to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            ans+=stoi(currpath);
            return ;
        }

        inorder(root->left,ans,currpath);
        inorder(root->right,ans,currpath);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int ans=0;
        inorder(root,ans,"");
        return ans;
    }
};