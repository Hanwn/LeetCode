class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        int len = A.size();
        unordered_map<int,int> hash;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                hash[-(A[i] + B[j])]++;
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int temp = C[i] + D[j];
                if (hash.find(temp) != hash.end()) {
                    ans += hash[temp];
                }
            }
        }
        return ans;
    }
};
