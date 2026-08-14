1class Solution {
2public:
3    vector<double> convertTemperature(double celsius) {
4        return {celsius+273.15, celsius*1.80+32.00};
5    }
6};