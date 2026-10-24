1class Solution {
2public:
3    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
4        vector<int> result;
5        for (int i = 0; i < order.size(); ++i) {
6            for (int j = 0; j < friends.size(); ++j) {
7                if (order[i] == friends[j]) {
8                    result.push_back(order[i]);
9                    break;
10                }
11            }
12        }
13        return result;
14    }
15};