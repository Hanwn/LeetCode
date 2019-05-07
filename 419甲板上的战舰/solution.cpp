//方法一：深搜的方式

class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int row = board.size();
        int col = board[0].size();    
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X'){
                    dfs(board,i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& board,int i,int j){
        board[i][j] = '.';
        for(int u = 0; u < 4; u++){
            int x = i + dx[u];
            int y = j + dy[u];
            if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&board[x][y]=='X'){
                dfs(board,x,y);
            }
        }
    }
};



//方法二
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'X'){
                    if(i>0&&board[i-1][j] == 'X'){
                        continue;
                    }else if(j > 0 && board[i][j-1] == 'X'){
                        continue;
                    }else{
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
