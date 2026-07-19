class Solution {
    public int divide(int dividend, int divisor) {
        // Overflow bounds
        int MAX_INT = 2147483647;
        int MIN_INT = -2147483648;
        
        // Handle overflow case
        if (dividend == MIN_INT && divisor == -1) {
            return MAX_INT;
        }
        
        // Determine the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Work with 64-bit absolute values to prevent overflow during intermediate calculations
        long absDividend = Math.abs((long) dividend);
        long absDivisor = Math.abs((long) divisor);
        
        long quotient = 0;
        while (absDividend >= absDivisor) {
            long tempDivisor = absDivisor;
            long multiple = 1;
            // Double the divisor until it is larger than the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            quotient += multiple;
        }
        
        long result = sign * quotient;
        if (result > MAX_INT) return MAX_INT;
        if (result < MIN_INT) return MIN_INT;
        return (int) result;
    }
}
