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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* mark1 = nullptr,*mark2 = nullptr;
        TreeNode* pre = nullptr;
        while (root||!s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                s.pop();
                if (pre && pre->val > root->val) {
                    if (!mark1) {
                        mark1 = pre;
                    }
                    mark2 = root;
                }
                pre = root;
                root = root->right;
            }
        }
        int temp = mark1->val;
        mark1->val = mark2->val;
        mark2->val = temp;
    }
};
