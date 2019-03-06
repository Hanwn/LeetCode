//Solution 1：
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return res;
    }
    void dfs(vector<int> nums,int left){
        if(left == nums.size()-1){
            res.push_back(nums);
        }
        for(int i = left;i<nums.size();i++){
            if(i!=left&&nums[left] == nums[i]){
                continue;
            }
            swap(nums[left],nums[i]);
            dfs(nums,left+1);
        }
        
    }
};

