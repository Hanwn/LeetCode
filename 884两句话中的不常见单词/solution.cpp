class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> mymap;
        vector<string> res;
        int k = 0;
        int i = 0;
        int j = 0;
        for( ; i < A.size(); i++){
            if(A[i] == ' '){
                mymap[A.substr(k,i-k)]++;
                k = i + 1;
            }
        }
        mymap[A.substr(k,i-k)]++;
        for( k = 0; j < B.size(); j++){
            if(B[j] == ' '){
                mymap[B.substr(k,j - k)]++;
                k = j + 1;
            }
        }
        mymap[B.substr(k,j-k)]++;
        for (auto& it:mymap){
            // cout<<it.first<<" ";
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        
        return res;
    }
};
