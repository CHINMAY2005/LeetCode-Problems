class Solution:
    def reverse(self, x):
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        sign = -1 if x < 0 else 1
        x = abs(x)
        rev = 0
        
        while x != 0:
            pop = x % 10
            x //= 10
            
            if rev > (INT_MAX - pop) // 10:
                return 0
                
            rev = rev * 10 + pop
            
        return sign * rev
