1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        int n = digits.size();
5        bool vis[1000]{};
6        int ans = 0;
7        for(int i = 0; i < n; ++i){
8            if(digits[i] == 0){
9                continue;
10            }
11            for(int j = 0; j < n; ++j){
12                if(j == i){
13                    continue;
14                }
15                for(int k = 0; k < n; ++k){
16                    if(k == i || k == j || digits[k] % 2 != 0){
17                        continue;
18                    }
19                    int x = digits[i] * 100 + digits[j] * 10 + digits[k];
20                    if(!vis[x]){
21                        vis[x] = true;
22                        ++ans;
23                    }
24                }
25            }
26        }
27        return ans;
28    }
29};