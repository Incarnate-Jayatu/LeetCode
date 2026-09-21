class Solution {
    public int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int delay = arrivalTime+delayedTime;
        if(delay>=24)
            delay = delay - 24;
        return delay;
    }
}
