class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) return 0;

        int num_rows = grid.size();
        int num_cols = grid.at(0).size();
        int num_islands = 0;

        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (grid[i][j] == '1') {
                    // Island found
                    num_islands++;
                    DFS(i, j, grid);
                }
            }
        }
        return num_islands;
    }

private:
    void DFS(int r, int c, vector<vector<char>> &grid) {
        int row = grid.size();
        int col = grid.at(0).size();

        grid[r][c] = '0'; // Mark visited

        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            // Look left
            DFS(r, c - 1, grid);

        if (c + 1 < col && grid[r][c + 1] == '1')
            // Look right
            DFS(r, c + 1, grid);

        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            // Look up
            DFS(r - 1, c, grid);

        if (r + 1 <  row && grid[r + 1][c] == '1')
            // Look down
            DFS(r + 1, c, grid);
    }
};
