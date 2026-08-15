class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //Using binary search technique for O(log(m*n))
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int low = 0;
        int high = (m * n) - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n;
            int col = mid % n;
            int midValue = matrix[row][col];
            if (midValue == target) {
                return true; 
            } else if (midValue < target) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return false;
    }
};
