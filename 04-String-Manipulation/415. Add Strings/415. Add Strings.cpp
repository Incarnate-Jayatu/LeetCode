class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = ;
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += num1[i--] - '0';
            if (j >= 0) carry += num2[j--] - '0';
            res.push_back((carry % 10) + '0');
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
