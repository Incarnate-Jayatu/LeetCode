class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i % 2 != 0) {
                    count++;
                }
                if ((n / i) % 2 != 0 && (n / i) != i) {
                    count++;
                }
            }
        }
        return count;
    }
};
