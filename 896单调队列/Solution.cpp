//write:Hanwn

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1 = false,flag2 = false;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            if(nums[i]>nums[i-1]){
                flag1 = true;             
            }else{
                flag2 = true;
            }
        }
        if(flag1&&flag2){
            return false;
        }else{
            return true;
        }
    }
};
