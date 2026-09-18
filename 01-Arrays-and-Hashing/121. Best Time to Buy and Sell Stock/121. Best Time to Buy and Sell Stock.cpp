1class Solution { 
2public: 
3    int maxProfit(vector<int>& prices) { 
4        if (prices.empty()) return 0;
5        
6        int min = prices[0];       
7        int max_profit = 0;         
8        int n = prices.size() - 1;
9        for(int i = 0; i <= n; i++){ 
10            if(prices[i] < min){ 
11                min = prices[i]; 
12            } 
13            else if(prices[i] - min > max_profit){ 
14                max_profit = prices[i] - min; 
15            } 
16        } 
17        return max_profit; 
18    } 
19};
20