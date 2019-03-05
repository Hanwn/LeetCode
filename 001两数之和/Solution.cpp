//解法1：暴力解法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* index = (int *)malloc(sizeof(int)*2);
    int flag = 0;
    for(int i = 0;i<numsSize;i++){
        int temp = target-nums[i];
        for(int j = i+1;j<numsSize;j++){
            if(nums[j] == temp){
                index[0] = i;
                index[1] = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    return index;
}
//解法2：hash_map
class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            if(hash.count(target - nums[i])){
                return {i,hash[target - nums[i]]};
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};
