1class Solution
2{
3public:
4    int char2num(char a)
5    {
6        switch(a){
7            case 'I': return 1;
8            case 'V': return 5;
9            case 'X': return 10;
10            case 'L': return 50;
11            case 'C': return 100;
12            case 'D': return 500;
13            case 'M': return 1000;
14            default: return 0;
15        }
16    }
17    int romanToInt(string s)
18    {
19        int result = 0;
20        for(int i = 0; i < s.length(); i++)
21        {
22            if(i+1<s.length() && char2num(s[i])<char2num(s[i+1])) 
23            {
24                result -= char2num(s[i]);
25            }
26            else
27            {
28                result += char2num(s[i]);
29            }
30        }
31        return result;
32    }
33};