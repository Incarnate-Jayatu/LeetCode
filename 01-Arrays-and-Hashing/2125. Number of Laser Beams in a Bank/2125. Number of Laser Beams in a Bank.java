1class Solution{
2    public int numberOfBeams(String[] bank){
3        int row = bank.length;
4        int ans = 0;
5        ArrayList<Integer> deviceCount = new ArrayList<>();
6        for (int i = 0; i < row; i++){
7            String curr = bank[i];
8            int count = 0;
9            for (int j = 0; j < curr.length(); j++){
10                if (curr.charAt(j) == '1'){
11                    count++;
12                }
13            }
14            if(count > 0) deviceCount.add(count);
15        }
16        for(int i = 0; i < deviceCount.size() - 1; i++){
17            ans += deviceCount.get(i) * deviceCount.get(i + 1);
18        }
19        return ans;
20    }
21}