1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        bool firstRowZero = false;
7        bool firstColZero = false;
8       
9        for(int j = 0; j < n; j++) {
10            if(matrix[0][j] == 0) firstRowZero = true;
11        }
12        for(int i = 0; i < m; i++) {
13            if(matrix[i][0] == 0) firstColZero = true;
14        }
15
16        for(int i = 1; i < m; i++) {
17            for(int j = 1; j < n; j++) {
18                if(matrix[i][j] == 0) {
19                    matrix[i][0] = 0;
20                    matrix[0][j] = 0;
21                }
22            }
23        }
24        
25        for(int i = 1; i < m; i++) {
26            for(int j = 1; j < n; j++) {
27                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
28                    matrix[i][j] = 0;
29                }
30            }
31        }
32       
33        if(firstRowZero) {
34            for(int j = 0; j < n; j++) matrix[0][j] = 0;
35        }
36        if(firstColZero) {
37            for(int i = 0; i < m; i++) matrix[i][0] = 0;
38        }
39    }
40};
41