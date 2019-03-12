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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        stack<TreeNode*> s;
        while(p||!s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(--k == 0){
                return p -> val;
            }else{
                p = p->right;
            } 
        }
        return 0;
    }
};
