1class Solution {
2    public int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
3        int delay = arrivalTime+delayedTime;
4        if(delay>=24)
5            delay = delay - 24;
6        return delay;
7    }
8}