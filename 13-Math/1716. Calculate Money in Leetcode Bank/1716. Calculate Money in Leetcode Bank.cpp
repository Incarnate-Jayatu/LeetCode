class Solution {
public:
    int totalMoney(int n) {
        int totalMoney = 0;
        int incrementAmt = 0; 
        int dailyAmt = 1;     
        for (int i = 1; i <= n; i++) {
            totalMoney += (dailyAmt + incrementAmt);
            dailyAmt++;
            if (i % 7 == 0) {
                incrementAmt++;
                dailyAmt = 1;
            }
        }
        return totalMoney;
    }
};
