const int N = 1e5 + 10;
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int dpf[N];
        int dpt[N];
        int n = A.size();
        if (n < 3) return 0;
        memset(dpf,0,sizeof(dpf));
        memset(dpt,0,sizeof(dpt));
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                // dpf[i] = dpf[i - 1] + 1;
                cnt++;
            }else {
                /*for (int j = 0; j < i; j++) {
                    if (A[i] > A[j]) {
                        dpf[i] = max(dpf[i],dpf[j] + 1);
                    }
                }*/
                cnt = 0;
            }
            dpf[i] = cnt;
        }
        cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                // dpt[i] = dpt[i + 1] + 1;
                cnt++;
            }else {
                /*for (int j = i + 1; j < n; j++) {
                    if (A[i] > A[j]) {
                        dpt[i] = max(dpt[i],dpt[j] + 1);
                    }
                }*/
                cnt = 0;
            }
            dpt[i] = cnt;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (dpt[i]&&dpf[i]&&(dpt[i] + dpf[i] >= 2))
                ans = max(ans,dpt[i] + dpf[i] + 1);
            // cout<<dpf[i]<<" "<<dpt[i]<<endl;
        }
        return ans;
    }
};
