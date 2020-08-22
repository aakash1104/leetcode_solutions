class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if (!grid.size())
            return 0;
        
        int r = grid.size();
        int c = grid[0].size();
        int max_area = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // Found an island
                    int area = 1;
                    DFS(i, j, grid, area);
                    max_area = std::max(area, max_area);
                }
            }
        }
        return max_area;
    }
private:
    void DFS(int i, int j, vector<vector<int>> &grid, int &area) {
        int r = grid.size();
        int c = grid[0].size();
        
        grid[i][j] = 0;
        
        // Look left
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            DFS(i, j - 1, grid, ++area);
        
        // Look right
        if (j + 1 < c && grid[i][j + 1] == 1)
            DFS(i, j + 1, grid, ++area);
        
        // Look up
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            DFS(i - 1, j, grid, ++area);
        
        // Look down
        if (i + 1 < r && grid[i + 1][j] == 1)
            DFS(i + 1, j, grid, ++area);
    }
};
