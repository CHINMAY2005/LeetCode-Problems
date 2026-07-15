# 0007 - Reverse Integer

## Problem
Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

## Key Insight
We can extract digits one by one using the modulo operator (`x % 10`) and division (`x / 10`). To prevent 32-bit overflow before performing multiplication by 10, we must check if our current reversed number has exceeded `INT_MAX / 10` or `INT_MIN / 10`.

## Approach
1. Initialize `rev = 0`.
2. While `x != 0`:
   - Pop the last digit: `pop = x % 10`.
   - Update `x /= 10`.
   - Overflow Check:
     - If `rev > INT_MAX / 10` or (`rev == INT_MAX / 10` and `pop > 7`), return 0.
     - If `rev < INT_MIN / 10` or (`rev == INT_MIN / 10` and `pop < -8`), return 0.
   - Update reversed number: `rev = rev * 10 + pop`.
3. Return `rev`.

*(Note: In Python, we can work with the absolute value to make modulo operations consistent with negative numbers, then restore the sign at the end.)*

## Why It Works
By validating `rev` against the limits *before* we multiply by 10 and add the popped digit, we guarantee that the operation will never overflow the 32-bit storage limits.

## Complexity
- Time: `O(log10(x))` since the number of digits in `x` is approximately $\log_{10}(x)$.
- Space: `O(1)` as we only store a few variables.

## Python
```python
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
```

## Java
```java
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            
            rev = rev * 10 + pop;
        }
        return rev;
    }
}
```

## C++
```cpp
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```
