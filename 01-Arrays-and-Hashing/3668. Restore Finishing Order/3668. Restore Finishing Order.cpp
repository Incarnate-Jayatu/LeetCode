class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;
        for (int i = 0; i < order.size(); ++i) {
            for (int j = 0; j < friends.size(); ++j) {
                if (order[i] == friends[j]) {
                    result.push_back(order[i]);
                    break;
                }
            }
        }
        return result;
    }
};
