1class Solution {
2public:
3    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
4        int n = image.size();
5        
6        for (int i = 0; i < n; i++) {
7            int left = 0;
8            int right = n - 1;
9            
10            while (left <= right) {
11                if (image[i][left] == image[i][right]) {
12                    if (image[i][left] == 0) {
13                        image[i][left] = 1;
14                        image[i][right] = 1;
15                    } else {
16                        image[i][left] = 0;
17                        image[i][right] = 0;
18                    }
19                }
20                left++;
21                right--;
22            }
23        }
24        return image;
25    }
26};
27