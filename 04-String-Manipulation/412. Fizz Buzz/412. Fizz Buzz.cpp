1class Solution {
2public:
3    vector<string> fizzBuzz(long int n) {
4        vector<string> answer(n);
5        for (long int i = 1; i <= n; i++) {
6            if (i % 3 == 0 && i % 5 == 0) {
7                answer[i - 1] = FizzBuzz;
8            } else if (i % 3 == 0) {
9                answer[i - 1] = Fizz;
10            } else if (i % 5 == 0) {
11                answer[i - 1] = Buzz;
12            } else {
13                answer[i - 1] = to_string(i); 
14            }
15        }
16        return answer;
17    }
18};