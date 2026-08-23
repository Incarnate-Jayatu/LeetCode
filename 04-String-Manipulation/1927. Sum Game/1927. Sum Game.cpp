1class Solution {
2public:
3    bool sumGame(std::string num) {
4        int n = num.length();
5        int sum_diff = 0;
6        int q_diff = 0;
7        for (int i = 0; i < n; i++) {
8            if (i < n / 2) {
9                if (num[i] == '?') {
10                    q_diff++;
11                } else {
12                    sum_diff += (num[i] - '0');
13                }
14            } else {
15                if (num[i] == '?') {
16                    q_diff--;
17                } else {
18                    sum_diff -= (num[i] - '0');
19                }
20            }
21        }
22        return (sum_diff * 2 != -9 * q_diff);
23    }
24};
25