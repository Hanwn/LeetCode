class Solution {
public:
    bool check(int mid, const vector<int> &nums, int k) {
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum >= mid) {
                sum = 0;
                cnt++;
                if (cnt >= k)
                    return true;
            }
        }
        return false;
    }
    int maximizeSweetness(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        int min_ = INT_MAX;
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            min_ = min(min_,nums[i]);
        }
        int top = sum + 1;
        int ans = 0;
        k++;
        while (min_ < top) {
            int mid = min_ + (top - min_)/2;
            if (check(mid,nums,k)) {min_ = mid + 1;}
            else top = mid;
            
        }
        return min_ - 1;
    }
};
