1class Solution {
2public:
3    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
4        int numberOfRows = score.size();
5        for (int i = 0; i < numberOfRows; i++) {
6            for (int j = i + 1; j < numberOfRows; j++) {
7                if (score[j][k] > score[i][k]) {
8                    swap(score[i], score[j]); 
9                }
10            }
11        }
12        return score;
13    }
14};
15