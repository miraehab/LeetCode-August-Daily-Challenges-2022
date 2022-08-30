class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n, islands = 0, dir[] = {0, 1, 0, -1, 0};
        if(m > 0) n = grid[0].size(); else n = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + dir[k], c = p.second + dir[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};