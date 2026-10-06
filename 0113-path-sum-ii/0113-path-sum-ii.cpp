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

    void inorder_trav(TreeNode* root, int targetSum, int currpathsum,vector<vector<int>> &ans,vector<int> path){
        if(root==NULL){
            return ;
        }

        path.push_back(root->val);
        currpathsum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(currpathsum==targetSum){
                ans.push_back(path);
                return ;
            }
        }

        inorder_trav(root->left,targetSum,currpathsum,ans,path);
        inorder_trav(root->right,targetSum,currpathsum,ans,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }

        vector<vector<int>> ans;
        inorder_trav(root,targetSum,0,ans,{});
        return ans;
    }
};