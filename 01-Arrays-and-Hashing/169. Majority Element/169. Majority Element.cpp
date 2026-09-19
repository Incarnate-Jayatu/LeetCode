1class Solution{
2public:
3    int majorityElement(vector<int>& nums){
4        int element = 0;
5        int count = 0;
6        for(int num : nums){
7            if(count == 0){
8                element = num;
9            }
10
11            if(num == element){
12                count++;
13            }
14            else{
15                count--;
16            }
17        }
18        return element;
19    }
20};