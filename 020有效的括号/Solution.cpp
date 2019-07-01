//Solution 1：利用栈和哈希表
//哈希表：快速找到与欲入栈的字符与栈顶端的字符是否匹配
//栈：用来存储未匹配的字符，等待匹配
class Solution {
public:
    bool isValid(string S) {
        unordered_map<char,char> mymap = {{'(',')'},{')','('},
                                       {'{','}'},{'}','{'},
                                       {'[',']'},{']','['}};
        stack<char> s;
        for(int i = 0 ; i < S.size(); i++){
            if(s.empty()){
                s.push(S[i]);
                continue;
            }
            if(mymap.find(S[i])->second == s.top()){
                s.pop();
            }else{
                s.push(S[i]);
            }
        }
        
        if(s.empty()){
            return true;
        }else{
            return false;
        }
    }
};
