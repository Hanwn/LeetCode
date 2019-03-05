//Solution 1:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }        
        unordered_set<int> record(nums.begin(),nums.end());
        int res = 1;
        for(auto ele : nums){
            if(record.find(ele) == record.end()){
                continue;
            }
            record.erase(ele);
            int left = ele - 1;
            int right = ele + 1;
            while(record.find(left)!=record.end()){
                record.erase(left--);
            }
            while(record.find(right)!=record.end()){
                record.erase(right++);
            }
            
            res = max(res,right-left -1);
        }
        return res;
    }
};


//Solution 2:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int ans = 1;
        int count = 1;
        set<int> record(nums.begin(),nums.end());
        vector<int> res(record.begin(),record.end());
        
        for(int i = 0;i<res.size()-1;i++){
            if(res[i] + 1 == res[i+1]){
                count ++;
            }else{
                count = 1;
            }
            ans = max(ans,count);
        }
        return ans;
        
    }
};
//Refrence : https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
