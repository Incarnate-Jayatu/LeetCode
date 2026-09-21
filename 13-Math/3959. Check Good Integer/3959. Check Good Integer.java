1class Solution {
2    public boolean checkGoodInteger(int n) {
3        int s = 0;
4        for (; n > 0; n /= 10) {
5            int x = n % 10;
6            s += x * (x - 1);
7        }
8        return s >= 50;
9    }
10}