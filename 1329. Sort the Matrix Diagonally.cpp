class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(),0));
        for(int i = 0; i < mat.size(); ++i){
            for(int j = 0; j < mat[0].size(); ++j){
                if(visited[i][j]) continue;
                int r = i, c = j;
                multiset<int> sorted;
                while(r < mat.size() && c < mat[0].size()){
                    sorted.insert(mat[r][c]);
                    visited[r][c] = 1;
                    ++r;
                    ++c;
                }
                r = i, c = j;
                auto it = sorted.begin();
                while(r < mat.size() && c < mat[0].size()){
                    mat[r][c] = *it;
                    ++r;
                    ++c;
                    it++;
                }
            }
        }
        return mat;
    }
};