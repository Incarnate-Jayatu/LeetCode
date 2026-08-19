1class Solution {
2public:
3    int thirdMax(vector<int>& arr) {
4        int n = arr.size();
5        for (int i = 1; i < n; i++) {
6            int key = arr[i];
7            int j = i - 1;
8            while (j >= 0 && arr[j] < key) {
9                arr[j + 1] = arr[j];
10                j--;
11            }
12            arr[j + 1] = key;
13        }
14        
15        int distinct_count = 1;
16        int result = arr[0];
17        for (int i = 1; i < n; i++) {
18            if (arr[i] != arr[i - 1]) {
19                distinct_count++;
20            }
21            if (distinct_count == 3) {
22                return arr[i];
23            }
24        }
25        return arr[0]; 
26    }
27};
28