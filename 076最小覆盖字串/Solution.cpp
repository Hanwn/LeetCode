//动态规划
//滑动窗口
//哈希表
class Solution {
public:
    string minWindow(string s, string t) {
        int begin = 0,end = 0;
        int head = 0,d = INT_MAX;
        vector<int> res(128,0);
        for(auto ele:t){
            res[ele]++;
        }
        int count = t.size();
        while(end<s.size()){
            if(res[s[end++]]-->0){
                count --;
            }
            while(!count){
                if(end-begin<d){
                    d = end-( head = begin);
                }
                if(res[s[begin++]]++ == 0){
                    count++;
                }
            }
        }
        return d == INT_MAX?"":s.substr(head,d);
    }
};
