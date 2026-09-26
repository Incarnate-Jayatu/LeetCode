class Solution {
    public int minQueenMoves(int[] source, int[] target) {
        int rowOne = source[0], colOne = source[1];
        int rowTwo = target[0], colTwo = target[1];
        if(rowOne == rowTwo && colOne == colTwo)
        {
             return 0;   
        }
        if(rowOne == rowTwo || colOne == colTwo || Math.abs(rowOne-rowTwo) == Math.abs(colOne-colTwo)){
             return 1;   
        }
        return 2;
    }
}
