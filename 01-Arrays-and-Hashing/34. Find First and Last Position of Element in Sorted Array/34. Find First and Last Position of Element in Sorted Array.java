1class Solution {
2    private int f1(int[] nums1, int target1){
3        int l=0;
4        int r=nums1.length-1;
5        int x=-1;
6        while(l<=r){
7            int mid=l+(r-l)/2;
8            if(nums1[mid]==target1){
9                x=mid;
10                r=mid-1;
11            }
12            else if(nums1[mid]>target1){
13                r=mid-1;
14            }
15            else{
16                l=mid+1;
17            }
18        }
19        return x;
20    }
21    private int f2(int[] nums2, int target2){
22        int l=0;
23        int r=nums2.length-1;
24        int y=-1;
25        while(l<=r){
26            int mid=l+(r-l)/2;
27            if(nums2[mid]==target2){
28                y=mid;
29                l=mid+1;
30            }
31            else if(nums2[mid]>target2){
32                r=mid-1;
33            }
34            else{
35                l=mid+1;
36            }
37        }
38        return y;
39    }
40    public int[] searchRange(int[] nums, int target) {
41        int[] arr = {-1, -1};
42        arr[0] = f1(nums, target);
43        arr[1] = f2(nums, target);
44        return arr;
45    }
46}