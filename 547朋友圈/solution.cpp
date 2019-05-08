//solution1:DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int res = 0;
        int n = nums.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++){
            if(visited[i]){
                continue;
            }
            dfs(nums , i , visited);
            res ++;
        }
        return res;
    }
    void dfs(vector<vector<int>>& nums,int i , vector<bool>& visited){
        visited[i] = true;
        for(int k = 0 ; k <nums.size(); k++){
            if(nums[i][k] && !visited[k]){
                dfs(nums,k,visited);
            }
        }
    }
};

//solution2:BFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int res = 0;
        int n = nums.size();
        vector<bool> visited(n,false);
        for(int i = 0 ; i < n ; i++){
            if(visited[i]){
                continue;
            }
            dfs(nums , i , visited);
            res ++;
        }
        return res;
    }
    void dfs(vector<vector<int>>& nums,int i , vector<bool>& visited){
        visited[i] = true;
        for(int k = 0 ; k <nums.size(); k++){
            if(nums[i][k] && !visited[k]){
                dfs(nums,k,visited);
            }
        }
    }
};
//solution3:Union Find 这个方法不是很明白
class Solution {
public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        int res = n;
        vector<int> root(n);
        for(int i = 0 ; i < n ; i++){
            root[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i][j]){
                    int p1 = getRoot(root,i);
                    int p2 = getRoot(root,j);
                    if(p1 != p2){
                        res--;
                        root[p2] = p1;
                    }
                }
            }
        }
        return res;
    }
    int getRoot(vector<int>& root,int i){
        while(i != root[i]){
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};
