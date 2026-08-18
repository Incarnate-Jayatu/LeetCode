class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = n - 1;
            
            while (left <= right) {
                if (image[i][left] == image[i][right]) {
                    if (image[i][left] == 0) {
                        image[i][left] = 1;
                        image[i][right] = 1;
                    } else {
                        image[i][left] = 0;
                        image[i][right] = 0;
                    }
                }
                left++;
                right--;
            }
        }
        return image;
    }
};
