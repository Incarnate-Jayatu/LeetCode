1class Solution {
2public:
3    int maxArea(vector<int>& height){
4        int left=0;
5        int right = height.size()-1;
6        int max_area=0;
7        while(left < right){
8            int width = right - left;
9            int current_height = min(height[left], height[right]);
10            int  current_area = width * current_height;
11            max_area = max(max_area, current_area);
12            if (height[left] < height[right]){
13                left++;
14            } 
15            else{
16                right--;
17            }
18        }
19        return max_area;
20    }
21};