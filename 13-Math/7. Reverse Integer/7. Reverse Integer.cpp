# Runtime: 40 ms, faster than 99.95% of Python3 online submissions for Reverse Integer.
# Memory Usage: 13.2 MB, less than 5.71% of Python3 online submissions for Reverse Integer.

class Solution:
    def reverse(self, x: int) -> int:  
        if x > 0:  # handle positive numbers  
            a =  int(str(x)[::-1])  
        if x <=0:  # handle negative numbers  
            a = -1 * int(str(x*-1)[::-1])  
        # handle 32 bit overflow  
        mina = -2**31  
        maxa = 2**31 - 1  
        if a not in range(mina, maxa):  
            return 0  
        else:  
            return a```