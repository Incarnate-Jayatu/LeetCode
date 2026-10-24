1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution{
5public:
6    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
7        auto toDays = [](string s){
8            int month = stoi(s.substr(0, 2));
9            int day = stoi(s.substr(3, 2));
10            int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
11            int total = day;
12            for (int i = 0; i < month - 1; i++)
13                total += days[i];
14            return total;
15        };
16        int start = max(toDays(arriveAlice), toDays(arriveBob));
17        int end = min(toDays(leaveAlice), toDays(leaveBob));
18        return max(0, end - start + 1);
19    }
20};