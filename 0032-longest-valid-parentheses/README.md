# 0032 - Longest Valid Parentheses

## Problem
Given a string containing just the characters `'('` and `')'`, return the length of the longest valid (well-formed) parentheses substring.

## Key Insight
Instead of using a stack or dynamic programming, we can calculate the result in $O(1)$ space using a two-pass scanner. By traversing the string once from left to right and once from right to left, we can balance the count of `'('` and `')'` to determine valid matched sequences.

## Approach
1. Initialize `left = 0`, `right = 0`, and `maxLen = 0`.
2. **Left-to-Right Scan**:
   - Iterate through the string from left to right.
   - Increment `left` for `'('` and `right` for `')'`.
   - If `left == right`, a valid sequence of length `2 * right` is found. Update `maxLen = max(maxLen, 2 * right)`.
   - If `right > left`, the sequence becomes invalid (too many closing parentheses). Reset `left = 0` and `right = 0`.
3. Reset `left = 0` and `right = 0`.
4. **Right-to-Left Scan**:
   - Iterate through the string from right to left.
   - Increment `left` for `'('` and `right` for `')'`.
   - If `left == right`, a valid sequence of length `2 * left` is found. Update `maxLen = max(maxLen, 2 * left)`.
   - If `left > right`, the sequence becomes invalid (too many opening parentheses). Reset `left = 0` and `right = 0`.
5. Return `maxLen`.

## Why It Works
A left-to-right scan will miss valid substrings that end with unclosed opening parentheses (for example, `((())` where `left` is always greater than `right`). A right-to-left scan catches these by doing the inverse validation. Combining both passes guarantees we find all possible valid balanced substrings.

## Complexity
- Time: `O(n)` where `n` is the length of string `s`. We traverse the string exactly twice.
- Space: `O(1)` auxiliary space, as we only maintain counters.

## Python
```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        left = right = max_len = 0
        
        # Left-to-right scan
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1
                
            if left == right:
                max_len = max(max_len, 2 * right)
            elif right > left:
                left = right = 0
                
        left = right = 0
        # Right-to-left scan
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1
                
            if left == right:
                max_len = max(max_len, 2 * left)
            elif left > right:
                left = right = 0
                
        return max_len
```

## Java
```java
class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();
        
        // Left-to-right scan
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = Math.max(maxLen, 2 * right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        // Right-to-left scan
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = Math.max(maxLen, 2 * left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return maxLen;
    }
}
```

## C++
```cpp
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();
        
        // Left-to-right scan
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        // Right-to-left scan
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return maxLen;
    }
};
```
