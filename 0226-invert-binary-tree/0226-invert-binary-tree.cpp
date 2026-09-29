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
    void inverthelper(TreeNode* l,TreeNode* r,TreeNode* lprev,TreeNode* rprev,bool ll){
        if(l==NULL && r==NULL){
            return ;
        }

        if(l==NULL){
           if(ll){
                lprev->left=r;
                rprev->right=NULL;
                inverthelper(r->left,r->right,r,r,true);
           }else{
                lprev->right=r;
                rprev->left=NULL;
                inverthelper(r->left,r->right,r,r,true);
           }return;
        }if(r==NULL){
           if(ll){
                rprev->right=l;
                lprev->left=NULL;
                inverthelper(l->left,l->right,l,l,true);
           }else{
                rprev->left=l;
                lprev->right=NULL;
                inverthelper(l->left,l->right,l,l,true);
           }return;
        }


        swap(l->val,r->val);
        inverthelper(l->left,r->right,l,r,true);
        inverthelper(l->right,r->left,l,r,false);
        
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        inverthelper(root->left,root->right,root,root,true);
        return root;
    }
};