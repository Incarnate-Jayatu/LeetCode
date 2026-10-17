1class Solution {
2    public int minSwaps(int[] nums) {
3        int n = nums.length;
4        int[][] a = new int[n][3];
5        for (int i = 0; i < n; i++) {
6            int s = 0, x = nums[i];
7            while (x > 0) {
8                s += x % 10;
9                x /= 10;
10            }
11            a[i][0] = s;
12            a[i][1] = nums[i];
13            a[i][2] = i;
14        }
15        Arrays.sort(a, (p, q) -> p[0] != q[0]
16                ? Integer.compare(p[0], q[0])
17                : Integer.compare(p[1], q[1]));
18
19        boolean[] vis = new boolean[n];
20        int swaps = 0;
21        for (int i = 0; i < n; i++) {
22            if (vis[i] || a[i][2] == i) continue;
23            int j = i, len = 0;
24            while (!vis[j]) {
25                vis[j] = true;
26                j = a[j][2];
27                len++;
28            }
29            swaps += len - 1;
30        }
31        return swaps;
32    }
33}