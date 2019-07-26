class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> res;
        for (int i = 0; n ; i++) {
            res.push_back(n&1);
            n = n>>1;
        }
        for(int i = 1 ; i < res.size(); i++) {
            if(res[i] == res[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
