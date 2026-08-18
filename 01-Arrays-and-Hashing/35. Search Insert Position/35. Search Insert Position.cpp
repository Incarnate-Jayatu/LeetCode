1class Solution {
2public:
3    int searchInsert(vector<int>& nums, int target) {
4        int left = 0;
5        int right = nums.size() - 1;
6        while (left <= right) {
7            int mid = left + (right - left) / 2; 
8            
9            if (nums[mid] == target) {
10                return mid;
11            } else if (nums[mid] < target) {
12                left = mid + 1;
13            } else {
14                right = mid - 1;
15            }
16        }
17        
18        return left;
19    }
20};