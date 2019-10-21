class Solution {
public:
    bool check(int mid,vector<int>& weights,int D) {
        int sum = 0,cnt = 1;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (sum > mid) {
                sum = weights[i];
                cnt++;
                if (cnt > D) {
                    return true;
                }
            }
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int max_ = INT_MIN;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            max_ = max(max_,weights[i]);
            sum += weights[i];
        }
        int ans = 0;
        int left = max_;
        int right = sum;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (check(mid,weights,D)){
                ans = left;
                left = mid + 1;
            }else {
                right = mid;
            }
        }
        return left;
    }
};
