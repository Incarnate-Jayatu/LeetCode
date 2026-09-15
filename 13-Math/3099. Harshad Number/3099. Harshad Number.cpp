1class Solution {
2public:
3    int sumOfTheDigitsOfHarshadNumber(int x){
4        int temp = x;
5        int digitSum = 0;
6        while(temp > 0){
7            digitSum += temp % 10;
8            temp /= 10;
9        }
10        if(x % digitSum == 0){
11            return digitSum;
12        } 
13        else{
14            return -1;
15        }
16    }
17};