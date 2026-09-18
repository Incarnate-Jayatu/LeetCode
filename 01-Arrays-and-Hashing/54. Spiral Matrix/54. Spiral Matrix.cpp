1class Solution{
2public:
3    vector<int> spiralOrder(vector<vector<int>>& matrix) {
4        vector<int> result;
5        if(matrix.empty()) return result;
6        int top = 0;
7        int bottom = matrix.size() - 1;
8        int left = 0;
9        int right = matrix[0].size() - 1;
10        while(top <= bottom && left <= right){
11            for(int i = left; i <= right; i++){
12                result.push_back(matrix[top][i]);
13            }
14            top++;
15            for(int i = top; i <= bottom; i++){
16                result.push_back(matrix[i][right]);
17            }
18            right--;
19            if(top <= bottom){
20                for(int i = right; i >= left; i--){
21                    result.push_back(matrix[bottom][i]);
22                }
23                bottom--;
24            }
25            if(left <= right){
26                for(int i = bottom; i >= top; i--){
27                    result.push_back(matrix[i][left]);
28                }
29                left++;
30            }
31        }   
32        return result;
33    }
34};