1class Solution {
2public:
3    int islandPerimeter(std::vector<std::vector<int>>& grid) {
4        int islands = 0;
5        int neighbors = 0;
6        int rows = grid.size();
7        int cols = grid[0].size();
8        for (int i = 0; i < rows; ++i) {
9            for (int j = 0; j < cols; ++j) {
10                if (grid[i][j] == 1) {
11                    islands++;
12                    if (i > 0 && grid[i - 1][j] == 1) {
13                        neighbors++;
14                    }
15                    if (j > 0 && grid[i][j - 1] == 1) {
16                        neighbors++;
17                    }
18                }
19            }
20        }
21        return (islands * 4) - (neighbors * 2);
22    }
23};