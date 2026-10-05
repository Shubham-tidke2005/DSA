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
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        queue<TreeNode*>q;
        q.push(root);
        bool foundNull=false;
        while(!q.empty()){
            TreeNode *ft=q.front();
            q.pop();
            if(ft==NULL){
               foundNull=true;
               continue;
            }

            if(foundNull){
                return false;
            }
                
            q.push(ft->left);
            q.push(ft->right);
            
        }

        return true;
    }
};