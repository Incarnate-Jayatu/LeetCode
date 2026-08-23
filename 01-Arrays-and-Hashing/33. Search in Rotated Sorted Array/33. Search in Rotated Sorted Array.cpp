1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int low = 0;
5        int high = nums.size() - 1;
6        while (low <= high) {
7            int mid = low + (high - low) / 2;
8            if (nums[mid] == target) {
9                return mid;
10            }
11            if (nums[low] <= nums[mid]) {
12                if (target >= nums[low] && target < nums[mid]) {
13                    high = mid - 1; 
14                } else {
15                    low = mid + 1;  
16                }
17            } 
18            else {
19                if (target > nums[mid] && target <= nums[high]) {
20                    low = mid + 1; 
21                } else {
22                    high = mid - 1; 
23                }
24            }
25        }
26        return -1; // Target not found
27    }
28};