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
    vector<int>ele;
    void findinorder(TreeNode* root){
        if(root==NULL){
            return ;
        }

        findinorder(root->left);
        ele.push_back(root->val);
        findinorder(root->right);
        
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL || (root->right==NULL && root->left==NULL)){
            return false;
        }

        findinorder(root);

        int st=0;
        int end=ele.size()-1;
        while(st<end){
            int sum=ele[st]+ele[end];
            if(sum==k){
                return true;
            }else if(sum>k){
                end--;
            }else{
                st++;
            }
        }return false;
        
    }
};