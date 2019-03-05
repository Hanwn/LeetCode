//Solution 1:
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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> temp(256,-1);
        int ans = 0;
        int left = -1;
        for(int i = 0; i < s.size() ; i++){
            left = max(left,temp[s[i]]);
            temp[s[i]] = i;
            ans = max(ans,i-left);
        }
        return ans;
    }
};
