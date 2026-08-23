class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int sum_diff = 0;
        int q_diff = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    q_diff++;
                } else {
                    sum_diff += (num[i] - '0');
                }
            } else {
                if (num[i] == '?') {
                    q_diff--;
                } else {
                    sum_diff -= (num[i] - '0');
                }
            }
        }
        return (sum_diff * 2 != -9 * q_diff);
    }
};
