class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1(n);
        vector<int> arr2(n);
        int len1 = 0;
        int len2 = 0;
        arr1[len1++] = nums[0];
        arr2[len2++] = nums[1];
        for (int i = 2; i < n; i++) {
            if (arr1[len1 - 1] > arr2[len2 - 1]) {
                arr1[len1++] = nums[i];
            } else {
                arr2[len2++] = nums[i];
            }
        }
        vector<int> result(n);
        int index = 0;
        for (int i = 0; i < len1; i++) {
            result[index++] = arr1[i];
        } 
        for (int i = 0; i < len2; i++) {
            result[index++] = arr2[i];
        }
        return result;
    }
};
