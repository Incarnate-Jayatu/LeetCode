1class Solution {
2public:
3    int dayOfYear(string date) {
4        int year = stoi(date.substr(0, 4));
5        int month = stoi(date.substr(5, 2));
6        int day = stoi(date.substr(8));
7        vector<int> days = {
8            31, isLeapYear(year) ? 29 : 28, 
9            31, 30, 31, 30, 31, 31, 30, 31, 30, 31
10        };
11        int totalDays = day;
12        for (int i = 0; i < month - 1; ++i) {
13            totalDays += days[i];
14        }
15        return totalDays;
16    }
17private:
18    bool isLeapYear(int year) {
19        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
20    }
21};