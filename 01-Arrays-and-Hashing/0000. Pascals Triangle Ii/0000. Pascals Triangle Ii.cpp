1class Solution {
2public:
3    vector<int> getRow(int rowIndex){
4        vector<int> row(rowIndex + 1, 1);
5        for(int i = 2; i <= rowIndex; ++i){
6            for(int j = i - 1; j > 0; --j){
7                row[j] += row[j - 1];
8            }
9        }
10        return row;
11    }
12};