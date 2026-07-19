# 0029 - Divide Two Integers

## Problem
Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` truncates to `8`, and `-2.7335` truncates to `-2`.

Return the quotient after dividing `dividend` by `divisor`.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: $[-2^{31}, 2^{31} - 1]$. For this problem, if the quotient is strictly greater than $2^{31} - 1$, then return $2^{31} - 1$, and if the quotient is strictly less than $-2^{31}$, then return $-2^{31}$.

## Key Insight
Instead of subtracting the divisor from the dividend sequentially (which is too slow, running in $O(\text{dividend})$ time), we can perform exponential subtraction using bit shifting. Shifting a number left by $x$ bits is equivalent to multiplying it by $2^x$. This reduces the search space logarithmically, making the solution highly efficient.

## Approach
1. Handle the 32-bit signed integer overflow case: if `dividend` is $-2^{31}$ and `divisor` is $-1$, return $2^{31}-1$.
2. Determine the sign of the result: `sign = -1` if the signs of `dividend` and `divisor` differ, otherwise `1`.
3. Work with 64-bit unsigned/long values representing the absolute values of `dividend` and `divisor` to prevent integer overflow during negation or bit shifting.
4. While `absDividend >= absDivisor`:
   - Initialize `tempDivisor = absDivisor` and `multiple = 1`.
   - Repeatedly shift `tempDivisor` and `multiple` left by 1 (doubling them) as long as `absDividend >= (tempDivisor << 1)`.
   - Subtract `tempDivisor` from `absDividend` and add `multiple` to the running `quotient`.
5. Apply the calculated `sign` to the final `quotient`, clamp the result within the signed 32-bit integer range, and return it.

## Why It Works
By doubling the divisor iteratively, we identify the largest multiple of the divisor ($2^k \cdot \text{divisor}$) that can be subtracted from the remaining dividend. This is analogous to binary search / long division, ensuring we resolve the quotient in $O(\log^2(\text{dividend}))$ time.

## Complexity
- Time: `O(log^2 N)` where `N` is the absolute value of the dividend. In the worst case, the outer loop decreases the dividend, and the inner loop takes `O(log N)` steps.
- Space: `O(1)` as all calculations are done in-place using simple scalar variables.

## Python
```python
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
```

## Java
```java
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
```

## C++
```cpp
#include <algorithm>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow bounds
        int MAX_INT = 2147483647;
        int MIN_INT = -2147483648;
        
        // Handle overflow case
        if (dividend == MIN_INT && divisor == -1) {
            return MAX_INT;
        }
        
        // Determine the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Work with 64-bit absolute values to prevent overflow
        long long absDividend = std::abs((long long)dividend);
        long long absDivisor = std::abs((long long)divisor);
        
        long long quotient = 0;
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            // Double the divisor until it is larger than the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            absDividend -= tempDivisor;
            quotient += multiple;
        }
        
        long long result = sign * quotient;
        if (result > MAX_INT) return MAX_INT;
        if (result < MIN_INT) return MIN_INT;
        return (int)result;
    }
};
```
