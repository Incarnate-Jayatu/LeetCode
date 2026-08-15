1class Solution {
2public:
3    vector<int> selfDividingNumbers(int left, int right) {
4        vector<int> result;
5        for(int i=left; i <=right; i++){
6            if (isSelfDividing(i)) {
7                result.push_back(i);
8            }
9        }
10        return result;
11    }
12private:
13    bool isSelfDividing(int num) {
14        int temp = num; 
15        while (temp > 0) {
16            int digit = temp % 10;   //accessing last digit of the number
17            if (digit == 0 || num % digit != 0) {
18                return false;
19            }
20            temp /= 10; 
21        }
22        return true;
23    }    
24};