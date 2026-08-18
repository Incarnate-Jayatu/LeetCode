1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        for (int i = 0; i < n >> 1; ++i) {
6            for (int j = 0; j < n; ++j) {
7                swap(matrix[i][j], matrix[n - i - 1][j]);
8            }
9        }
10        for (int i = 0; i < n; ++i) {
11            for (int j = 0; j < i; ++j) {
12                swap(matrix[i][j], matrix[j][i]);
13            }
14        }
15    }
16};