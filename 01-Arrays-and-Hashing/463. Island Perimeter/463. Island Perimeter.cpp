class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int islands = 0;
        int neighbors = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        neighbors++;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        neighbors++;
                    }
                }
            }
        }
        return (islands * 4) - (neighbors * 2);
    }
};
