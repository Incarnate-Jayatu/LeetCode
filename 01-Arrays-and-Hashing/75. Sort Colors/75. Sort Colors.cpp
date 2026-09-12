1class Solution {
2public:
3    void sortColors(vector<int>& arr){
4        int n = arr.size();
5        for(int i = 0; i < n; i++){
6            bool swapped = false;
7            for(int j = 0; j < n-i-1; j++){
8                if(arr[j] > arr[j+1]){ swap(arr[j], arr[j+1]); swapped = true; }
9            }
10            if(!swapped) break;
11        }
12        for(int i=0; i<n; i++)
13        cout<<arr[i]<< ;
14    }
15};