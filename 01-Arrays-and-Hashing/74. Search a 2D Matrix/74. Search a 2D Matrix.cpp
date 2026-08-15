1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) { //Using binary search technique for O(log(m*n))
4        int m = matrix.size();
5        if (m == 0) return false;
6        int n = matrix[0].size();
7
8        int low = 0;
9        int high = (m * n) - 1;
10
11        while (low <= high) {
12            int mid = low + (high - low) / 2;
13            int row = mid / n;
14            int col = mid % n;
15            int midValue = matrix[row][col];
16            if (midValue == target) {
17                return true; 
18            } else if (midValue < target) {
19                low = mid + 1; 
20            } else {
21                high = mid - 1; 
22            }
23        }
24        return false;
25    }
26};
27