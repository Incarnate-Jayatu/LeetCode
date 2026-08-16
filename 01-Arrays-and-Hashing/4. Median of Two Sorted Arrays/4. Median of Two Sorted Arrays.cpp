1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
4        n1.insert(n1.end(), n2.begin(), n2.end());
5        sort(n1.begin(), n1.end());
6        int mid = n1.size() / 2;
7        return n1.size() % 2 ? n1[mid] : (n1[mid - 1] + n1[mid]) / 2.0;
8    }
9};