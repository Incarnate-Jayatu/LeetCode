class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int numberOfRows = score.size();
        for (int i = 0; i < numberOfRows; i++) {
            for (int j = i + 1; j < numberOfRows; j++) {
                if (score[j][k] > score[i][k]) {
                    swap(score[i], score[j]); 
                }
            }
        }
        return score;
    }
};
