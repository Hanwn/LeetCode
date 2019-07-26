//Solution1 :使用一个原矩阵进行标记出现零的位置
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> flag = matrix;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col ; j++){
                if(!flag[i][j] && !matrix[i][j]){
                    for(int k = 0; k < col; k++){
                        matrix[i][k] = 0;
                    }
                    for(int u = 0; u < row; u++){
                        matrix[u][j] = 0;
                    }
                }
            }
        }
    }
};
//Solution2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row(matrix.size(),1);
        vector<bool> col(matrix[0].size(),1);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(!matrix[i][j]){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for(int k = 0 ; k < row.size(); k++){
            if(!row[k]){
                for(int n = 0; n < col.size(); n++){
                    matrix[k][n] = 0;
                }
            }
        }
        for(int u = 0 ; u < col.size(); u++){
            if(!col[u]){
                for(int r = 0 ; r < row.size() ; r++){
                    matrix[r][u] = 0;
                }
            }
        }
    }
};
