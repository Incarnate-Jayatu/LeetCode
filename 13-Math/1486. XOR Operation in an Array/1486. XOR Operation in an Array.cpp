1class Solution {
2public:
3    int xorOperation(int n, int start) {
4        int res = 0;
5        for (int i = 0; i < n; ++i) {
6            res ^= (start + 2 * i);
7        }
8        return res;
9    }
10};