class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        n1.insert(n1.end(), n2.begin(), n2.end());
        sort(n1.begin(), n1.end());
        int mid = n1.size() / 2;
        return n1.size() % 2 ? n1[mid] : (n1[mid - 1] + n1[mid]) / 2.0;
    }
};
