1class Solution {
2public:
3    vector<int> resultArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> arr1(n);
6        vector<int> arr2(n);
7        int len1 = 0;
8        int len2 = 0;
9        arr1[len1++] = nums[0];
10        arr2[len2++] = nums[1];
11        for (int i = 2; i < n; i++) {
12            if (arr1[len1 - 1] > arr2[len2 - 1]) {
13                arr1[len1++] = nums[i];
14            } else {
15                arr2[len2++] = nums[i];
16            }
17        }
18        vector<int> result(n);
19        int index = 0;
20        for (int i = 0; i < len1; i++) {
21            result[index++] = arr1[i];
22        } 
23        for (int i = 0; i < len2; i++) {
24            result[index++] = arr2[i];
25        }
26        return result;
27    }
28};
29