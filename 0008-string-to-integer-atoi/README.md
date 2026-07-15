# 0008 - String to Integer (atoi)

## Problem
Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The algorithm is as follows:
1. Read and ignore leading whitespace.
2. Check for a sign character (`'-'` or `'+'`). This determines if the final result is negative or positive.
3. Read the next characters until a non-digit character is met. Ignore the remainder of the string.
4. Convert digits to an integer. If no digits were read, return 0.
5. If the integer is out of range, clamp it to `[-2^31, 2^31 - 1]`.

## Key Insight
We can convert the string in a single pass by processing character by character. To prevent overflow before multiplying by 10, we validate the current result against `INT_MAX / 10`.

## Approach
1. Skip leading whitespaces by advancing the index `i`.
2. Determine the sign by checking `s[i]` for `'-'` or `'+'`.
3. Loop through digit characters `s[i]`:
   - Compute `digit = s[i] - '0'`.
   - Overflow Check: If `res > INT_MAX / 10` or (`res == INT_MAX / 10` and `digit > 7`), return `INT_MAX` (if positive) or `INT_MIN` (if negative).
   - Update `res = res * 10 + digit`.
4. Return `sign * res`.

## Why It Works
By validating `res` against bounds *before* the multiplication step, we prevent the environment from throwing overflow errors or wrapping values.

## Complexity
- Time: `O(n)` where `n` is the length of the string, as we traverse the string at most once.
- Space: `O(1)` auxiliary space.

## Python
```python
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
```

## Java
```java
class Solution {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        int n = s.length();
        int i = 0;
        
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        char firstChar = s.charAt(i);
        if (firstChar == '-') {
            sign = -1;
            i++;
        } else if (firstChar == '+') {
            i++;
        }
        
        int res = 0;
        while (i < n && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';
            
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && digit > 7)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            res = res * 10 + digit;
            i++;
        }
        
        return sign * res;
    }
}
```

## C++
```cpp
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        
        int res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            res = res * 10 + digit;
            i++;
        }
        
        return sign * res;
    }
};
```
