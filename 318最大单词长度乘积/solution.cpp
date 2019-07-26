class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        int len = words.size();
        if (!len) {
            return 0;
        }
        int hash[words.size()] = {0};
        for (int  i = 0 ; i < len; i++) {
            for (int j = 0 ; j < words[i].size(); j++){
                hash[i] |= 1<<(words[i][j] - 'a');
            }
        }
        
        
        for (int i = 0 ; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if((hash[i]&hash[j]) == 0) {
                    res = res>words[i].size() * words[j].size()?res:words[i].size() * words[j].size();
                }
            }
        }
        return res;
    }
};
