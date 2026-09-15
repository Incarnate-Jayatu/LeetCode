1class Solution {
2public:
3    bool checkPerfectNumber(int num) {
4        bool result;
5        int sum=0;
6        for(int i=1; i<=num/2; i++){
7            if(num%i == 0)
8                sum += i;
9        }
10        if(sum == num)
11            result = true;
12        else
13            result =false;
14        return result;    
15    }
16};