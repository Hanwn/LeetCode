class Solution {
public:
    int brokenCalc(int x, int y) {
        int ans = 0;
        while (x < y) {
            if (y&1) {
                y = (y + 1)/2;
                ans += 2;
            }else {
                y /= 2;
                ans++;
            }
        }
        return ans + x - y;
    }
};
