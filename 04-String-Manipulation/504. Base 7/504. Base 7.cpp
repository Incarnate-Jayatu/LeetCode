1class Solution {
2public:
3    string convertToBase7(int num) {
4        if (num == 0)
5            return 0;
6        bool isNegative = false;
7        if (num < 0) {
8            isNegative = true;
9            num = -num; 
10        }
11        string result = ;
12        while (num > 0) {
13            int remainder = num % 7;
14            result = to_string(remainder) + result;
15            num = num / 7;
16        }
17        if (isNegative)
18            result = - + result;
19        return result;
20    }
21};
22