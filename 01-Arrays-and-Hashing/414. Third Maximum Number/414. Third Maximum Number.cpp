class Solution {
public:
    int thirdMax(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        
        int distinct_count = 1;
        int result = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                distinct_count++;
            }
            if (distinct_count == 3) {
                return arr[i];
            }
        }
        return arr[0]; 
    }
};
