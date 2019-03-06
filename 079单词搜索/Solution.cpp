class Solution {
public:
    bool exist(vector<vector<char>>& nums, string word) {
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<nums[0].size();j++){
                if(dfs(nums,i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& nums,int i,int j,string s){
        if(!s.size()){
            return true;
        }
        if(i<0||j<0||i>=nums.size()||j>=nums[0].size()||nums[i][j]!=s[0]){
            return false;
        }
        char c = nums[i][j];
        nums[i][j] = '*';
        s = s.substr(1);
        bool ret = false;
        if(dfs(nums,i-1,j,s)||dfs(nums,i,j-1,s)||dfs(nums,i,j+1,s)||dfs(nums,i+1,j,s)){
            ret =  true;
        }
        nums[i][j] = c;
        return ret;
    }
};
