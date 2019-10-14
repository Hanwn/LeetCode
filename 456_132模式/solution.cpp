class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (third > nums[i]) {
                return true;
            }
            while(!s.empty()&&s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
