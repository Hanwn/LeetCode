class Solution {
public:
    vector<string> res;
    vector<string> nums;
    int n;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return res;
        }
        n = digits.size();
        nums.push_back("abc");
        nums.push_back("def");
        nums.push_back("ghi");
        nums.push_back("jkl");
        nums.push_back("mno");
        nums.push_back("pqrs");
        nums.push_back("tuv");
        nums.push_back("wxyz");
        dfs(digits,"",0);
        return res;
    }
    
    void dfs(string& s,string path,int start){
        if(path.size() == n){
            res.push_back(path);
            return;
        }
        for(int i = start;i < s.size() ; i++){
            for(int j = 0;j < nums[s[i] - '2'].size(); j++){
                path += nums[s[i]-'2'][j];
                dfs(s, path , i+1);
                path.pop_back();
            }
        }
    }
};
