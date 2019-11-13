int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0) dfs(grid,i,0);
            if (grid[i][col - 1] == 0) dfs(grid,i,col - 1);
        }
        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 0) dfs(grid,0,i);
            if (grid[row - 1][i] == 0) dfs(grid,row - 1,i);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& nums,int i,int j) {
        nums[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int dx = x[k] + i;
            int dy = y[k] + j;
            if (dx >= 0 && dx < nums.size() && dy >= 0 && dy < nums[0].size() && (nums[dx][dy] == 0)) {
                dfs(nums,dx,dy);
            }
        }
    }
};
