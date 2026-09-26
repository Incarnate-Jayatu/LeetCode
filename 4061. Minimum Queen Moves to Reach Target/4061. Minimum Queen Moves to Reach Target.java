1class Solution {
2    public int minQueenMoves(int[] source, int[] target) {
3        int rowOne = source[0], colOne = source[1];
4        int rowTwo = target[0], colTwo = target[1];
5        if(rowOne == rowTwo && colOne == colTwo)
6        {
7             return 0;   
8        }
9        if(rowOne == rowTwo || colOne == colTwo || Math.abs(rowOne-rowTwo) == Math.abs(colOne-colTwo)){
10             return 1;   
11        }
12        return 2;
13    }
14}