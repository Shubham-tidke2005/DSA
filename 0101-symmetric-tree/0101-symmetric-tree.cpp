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
    bool ans=true;
    void isSymmetric_helper(TreeNode* left,TreeNode* right){
        if(!ans){
            return;
        }
        if(left==NULL && right==NULL){
            return ;
        }else if((left!=NULL && right==NULL) || (left==NULL && right!=NULL)){
            ans=false;
            return ;
        }else{

        }

        if(left->val!= right->val){
            ans=false;
            return;
        }

        isSymmetric_helper(left->left,right->right);
        isSymmetric_helper(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        isSymmetric_helper(root->left,root->right);
        return ans;
        
    }
};