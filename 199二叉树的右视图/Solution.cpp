/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Solution 1 dfs
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* root,int level){
        if(!root){
            return ;
        }
        if(level >= res.size()){
            res.push_back(root->val);
        }
        dfs(root->right,level+1);
        dfs(root->left,level+1);
    }
};
//Solution 2 bfs

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> myqueue;
        vector<int> res;
        if(!root){
            return res;
        }
        myqueue.push(root);
        while(!myqueue.empty()){
            res.push_back(myqueue.back()->val);
            for(int i = myqueue.size(); i > 0 ; i--){
                TreeNode* tn = myqueue.front();
                myqueue.pop();
                if(tn->left){
                    myqueue.push(tn->left);
                }
                if(tn->right){
                    myqueue.push(tn->right);
                }
            }
        }
        return res;
    }
};

