1class Solution {
2public:
3    bool checkValidString(string s){
4        int low = 0;
5        int high = 0;
6        for(int i = 0; i < s.size(); i++){
7            if(s[i] == '('){
8                low++;
9                high++;
10            } 
11            else if(s[i] == ')'){
12                if(low > 0){
13                    low--;
14                }
15                high--;
16            } 
17            else{
18                if(low > 0){
19                    low--;
20                }
21                high++;
22            }
23            if(high < 0){
24                return false;
25            }
26        }
27        return low == 0;
28    }
29};