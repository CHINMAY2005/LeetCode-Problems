class Solution:
    def myAtoi(self, s):
        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        n = len(s)
        i = 0
        
        while i < n and s[i] == ' ':
            i += 1
            
        if i == n:
            return 0
            
        sign = 1
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
            
        res = 0
        while i < n and s[i].isdigit():
            digit = int(s[i])
            
            if res > INT_MAX // 10 or (res == INT_MAX // 10 and digit > 7):
                return INT_MAX if sign == 1 else INT_MIN
                
            res = res * 10 + digit
            i += 1
            
        return sign * res
