1class Solution {
2public:
3    string addStrings(string num1, string num2) {
4        string res = ;
5        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
6        while (i >= 0 || j >= 0 || carry) {
7            if (i >= 0) carry += num1[i--] - '0';
8            if (j >= 0) carry += num2[j--] - '0';
9            res.push_back((carry % 10) + '0');
10            carry /= 10;
11        }
12        reverse(res.begin(), res.end());
13        return res;
14    }
15};
16