1class Solution {
2public:
3    int numJewelsInStones(string jewels, string stones) {
4        int count=0;
5        for(int i=0; i<jewels.length(); i++){
6            for(int j=0; j<stones.length(); j++){
7                if(jewels[i] == stones[j])
8                    count++;
9            }
10        }
11        return count;
12    }
13};