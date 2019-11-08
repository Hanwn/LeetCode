class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        int ans = n;
        //以s[i]个元素为中心的回文数组，也就是奇数个
        for (int i = 1; i < n - 1; i++) {
            int L = i - 1,R = i + 1;
            while (L >= 0 && R < n) {
                if (s[L] == s[R]){
                    ans++;
                    L--;
                    R++;
                }else {
                    break;
                }
            }
        }
        //偶数个组成的回文数组
        for (int i = 0; i < n; i++) {
            int L = i,R = i + 1;
            while (L>=0&&R<n) {
                if (s[L] == s[R]) {
                    ans++;
                    L--;
                    R++;
                }else {
                    break;
                }
            }
        }
        return ans;
    }
};
