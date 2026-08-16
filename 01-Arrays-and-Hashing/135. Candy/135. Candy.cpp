class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {    //leftt neighbour
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int total_candies = candies[n - 1];     //right neighbor
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            total_candies += candies[i];
        }
        return total_candies;
    }
};
