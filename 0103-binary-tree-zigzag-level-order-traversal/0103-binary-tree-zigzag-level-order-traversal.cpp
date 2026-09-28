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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode *>q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr!=NULL){
                level.push_back(curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }else{
                ans.push_back(level);
                level={};
                if(!q.empty()){
                    q.push(NULL);
                }              
            }
        }

        bool iseven=false;
        for(vector<int> &currlevel:ans){
            if(iseven){
                reverse(currlevel.begin(), currlevel.end());
            }iseven=!(iseven);
        }return ans;
    }
};