class Solution {
public:
    int findComplement(int num) {
        int cur = num;
        int res = 0;
        while(cur) {
            cur >>= 1;
            res = (res <<1) + 1;
        }
        return res^num;
    }
};
