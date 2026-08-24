1class Solution {
2public:
3    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
4        sort(nums1.begin(), nums1.end());
5        sort(nums2.begin(), nums2.end());
6        
7        vector<int> result;
8        int i = 0, j = 0;
9        
10        while (i < nums1.size() && j < nums2.size()) {
11            if (nums1[i] < nums2[j]) {
12                i++;
13            } else if (nums1[i] > nums2[j]) {
14                j++;
15            } else {
16                if (result.empty() || result.back() != nums1[i]) {
17                    result.push_back(nums1[i]);
18                }
19                i++;
20                j++;
21            }
22        }
23        return result;
24    }
25};