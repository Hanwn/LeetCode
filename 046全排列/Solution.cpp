//Solution 1:
//深搜 + 回溯
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums,0,res);
        return res;
    }
private:
    void dfs(vector<int>& nums,int begin,vector<vector<int>>& res){
        if(nums.size() == begin){
            res.push_back(nums);
        }
        for(int i = begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            dfs(nums,begin+1,res);
            swap(nums[begin],nums[i]);
        }
    }
};
