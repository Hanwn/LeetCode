class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return dfs(s,pos).first;
    }
    pair<string,int> dfs(string s, int pos) {
        int num = 0;
        string word = "";
        for (; pos < s.size(); pos++) {
            if (s[pos] >= '0'&&s[pos] <= '9') {
                num = num* 10 + s[pos] - '0';
            }else if (s[pos] == ']'){
                return {word,pos};
            }else if (s[pos] == '[') {
                pair<string,int> cur = dfs(s,++pos);
                pos = cur.second;
                for (;num;num--) {word += cur.first;}
            }else {
                word += s[pos];
            }
        }
        return {word,pos};
    }
};