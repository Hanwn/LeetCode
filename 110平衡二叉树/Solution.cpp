/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return flag;
    }
    
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if(abs(left-right)>1){
            flag = false;
        }
        return max(left,right)+1;
    }
};
