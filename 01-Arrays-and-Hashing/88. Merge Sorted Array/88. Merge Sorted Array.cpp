1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int p1 = m - 1;
5        int p2 = n - 1;
6        int p = m + n - 1;
7        
8        while (p1 >= 0 && p2 >= 0) {
9            if (nums1[p1] > nums2[p2]) {
10                nums1[p] = nums1[p1];
11                p1--;
12            } else {
13                nums1[p] = nums2[p2];
14                p2--;
15            }
16            p--;
17        }
18        
19        while (p2 >= 0) {
20            nums1[p] = nums2[p2];
21            p2--;
22            p--;
23        }
24    }
25};