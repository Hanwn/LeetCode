class Solution{
public:
	TreeNode* build(vecotr<int> inorder,vecotr<int> preorder){
		int index = 0;
		return helper(inorder,index,preorder,0,preorder.size() - 1);
	}
private:
	TreeNode* helper(vecotr<int>& inorder,int& index,vecotr<int>& preorder,int begin,int end){
		if(begin > end||index>=inorder.size()){
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[index++]);
		int pos = find(inorder,root->val);
		root -> left = helper(inorder,index,preorder,begin,pos - 1);
		root -> right = helper(inorder,index,preorder,pos + 1, end);
	}

	int find(vecotr<int>& nums,int target){
		for(int i = 0;i<nums.size();i++){
			if(nums[i] == target){
				return i;
			}
		}
		return 0;
	}

};
