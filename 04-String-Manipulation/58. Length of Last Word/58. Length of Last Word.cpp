1class Solution 
2{
3    public:
4        int lengthOfLastWord(string s) 
5        {
6            int count = 0;
7            for (int i = s.length() - 1; i >= 0; i--) 
8            {
9                if (s[i] != ' ') 
10                {
11                    count++;
12                }
13                else if (s[i] == ' ' && count > 0) 
14                {
15                return count;
16                }
17            }
18        return count;
19        }
20};