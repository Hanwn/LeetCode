//Solution 1:
//
//这道题也有一点滑动窗口的味道
//用双指针分别标志当前位置和无重复的起始位置
//值得深思
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int ans = 0;
        for(int i = 0,j = 0;j<s.size();j++){
            if(++hash[s[j]]>1){
                while(i<j){
                    hash[s[i]]--;
                    i++;
                    if(hash[s[j]] == 1){
                        break;
                    }
                }
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};

//Solution 2:
//
//temp里save的是不重复字母的index
//
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> temp(256,-1);
	int start = -1;
	int res = 0;
	for(int i = 0;i<s.size();i++){
	    if(temp[s[i]]>start){
	        start = temp[s[i]];
	    }
	    temp[s[i]] = i;
	    res = max(res,i-start);
	}
	return res;
    }
};

//Reference : https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1737/C%2B%2B-code-in-9-lines.

