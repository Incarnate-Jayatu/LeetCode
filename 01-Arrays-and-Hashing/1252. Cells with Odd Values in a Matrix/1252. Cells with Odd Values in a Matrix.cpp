1class Solution {
2public:
3    int oddCells(int m, int n, vector<vector<int>>& indices) {
4        vector<int> row(m, 0);
5        vector<int> col(n, 0);
6        for (auto& index : indices) {
7            row[index[0]]++;
8            col[index[1]]++;
9        }
10        int oddCount = 0;
11        for (int i = 0; i < m; ++i) {
12            for (int j = 0; j < n; ++j) {
13                if ((row[i] + col[j]) % 2 != 0) {
14                    oddCount++;
15                }
16            }
17        }
18        return oddCount;
19    }
20};