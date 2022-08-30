class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix[0].size()-1;
        while(start < end){
            for(int i = 0; i < matrix.size(); ++i){
                int tmp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = tmp;
                //cout << matrix[i][start] << ' ' << matrix[i][end] << endl;
            }
            ++start;
            --end;
        }

        vector<vector<int>> visited(matrix.size(), vector<int>(matrix.size(), 0));
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix.size(); ++j){
                if(visited[i][j]) continue;
                int tmp = matrix[i][j];
                int row = matrix.size() - j - 1;
                int col = matrix.size() - i - 1;
                matrix[i][j] = matrix[row][col];
                matrix[row][col] = tmp;
                visited[i][j] = 1;
                visited[row][col] = 1;    
            }
        }
    }
};