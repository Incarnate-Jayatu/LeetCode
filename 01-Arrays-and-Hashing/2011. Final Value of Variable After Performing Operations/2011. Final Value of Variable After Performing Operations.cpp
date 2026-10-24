1class Solution {
2public:
3    int finalValueAfterOperations(vector<string>& operations) {
4        int x=0;
5        for(int i=0; i<operations.size(); i++){
6            if(operations[i] == ++X || operations[i] == X++)
7                x+=1;
8            else if(operations[i] == --X || operations[i] == X--)
9                x-=1;
10        }
11        return x;
12    }
13};