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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        return build(inorder,index,postorder,0,inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& inorder,int& index,vector<int>& postorder,int begin,int end){
        if(index<0||begin>end){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[index--]);
        int pos = find(inorder,root->val);
        root -> right = build(inorder,index,postorder,pos+1,end);
        root -> left = build(inorder,index,postorder,begin,pos - 1);
        return root;
    }
    
    int find(vector<int>& nums,int target){
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == target){
                return i;
            }
        }
        return 0;
    }
};
