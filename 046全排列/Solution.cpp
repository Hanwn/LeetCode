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

//Solution 2:
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> visted;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visted(nums.size(),0);
        dfs(nums);
        return ans;
    }
    
    void dfs(vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visted[i]==0){
                vis[i] = 1;
                temp.push_back(nums[i]);
                dfs(nums);
                visted[i] = 0;
                temp.pop_back();   
            }
        }
    }
};
