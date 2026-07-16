# 0009 - Palindrome Number

## Problem
Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

## Key Insight
Instead of converting the integer to a string, which requires auxiliary space, we can reverse the second half of the number and compare it with the first half. A negative number or a number ending in 0 (except 0 itself) cannot be a palindrome.

## Approach
1. Handle edge cases: If `x < 0` or (`x % 10 == 0` and `x != 0`), return `false`.
2. Initialize `revertedNumber = 0`.
3. Loop while `x > revertedNumber`:
   - Append the last digit of `x` to `revertedNumber`: `revertedNumber = revertedNumber * 10 + x % 10`.
   - Update `x /= 10`.
4. When the loop terminates, check if `x == revertedNumber` (even number of digits) or `x == revertedNumber / 10` (odd number of digits, ignoring the middle digit).

## Why It Works
By reversing only the second half of the integer, we avoid potential integer overflow issues while still performing a digit-by-digit comparison in $O(\log_{10} n)$ time.

## Complexity
- Time: `O(log10(n))` where `n` is the value of `x`.
- Space: `O(1)` as we only store `revertedNumber`.

## Python
```python
class Solution:
    def isPalindrome(self, x):
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
            
        reverted_number = 0
        while x > reverted_number:
            reverted_number = reverted_number * 10 + x % 10
            x //= 10
            
        return x == reverted_number or x == reverted_number // 10
```

## Java
```java
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        return x == revertedNumber || x == revertedNumber / 10;
    }
}
```

## C++
```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
```
