1class Solution {
2private:
3    int getNext(int n) {
4        int totalSum = 0;
5        while (n > 0) {
6            int d = n % 10;
7            n = n / 10;
8            totalSum += d * d;
9        }
10        return totalSum;
11    }
12public:
13    bool isHappy(int n) {
14        std::unordered_set<int> seen;
15        while (n != 1 && seen.find(n) == seen.end()) {
16            seen.insert(n);
17            n = getNext(n);
18        }
19        return n == 1;
20    }
21};