class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # Overflow bounds
        MAX_INT = 2147483647
        MIN_INT = -2147483648
        
        # Handle overflow case
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
            
        # Determine the sign of the result
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        
        # Work with absolute values
        abs_dividend = abs(dividend)
        abs_divisor = abs(divisor)
        
        quotient = 0
        while abs_dividend >= abs_divisor:
            temp_divisor = abs_divisor
            multiple = 1
            # Double the divisor until it is larger than the remaining dividend
            while abs_dividend >= (temp_divisor << 1):
                temp_divisor <<= 1
                multiple <<= 1
            abs_dividend -= temp_divisor
            quotient += multiple
            
        result = sign * quotient
        return min(max(result, MIN_INT), MAX_INT)
