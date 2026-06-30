# 0005 - Longest Palindromic Substring

## Problem
Given a string `s`, return the longest substring that reads the same forward and backward.

If there are multiple answers, returning any one of them is acceptable.

## Key Insight
Every palindrome has a center.

That center is either:
- one character for odd-length palindromes, such as `racecar`
- two characters for even-length palindromes, such as `abba`

## Approach
For each index, expand in both directions from:
- `(i, i)` for odd-length palindromes
- `(i, i + 1)` for even-length palindromes

Track the longest palindrome found while scanning the string.

## Why This Works
A palindrome is fully determined by its center.
Checking all possible centers guarantees we inspect every possible palindrome without using extra storage for dynamic programming.

## Complexity
- Time: `O(n^2)`
- Space: `O(1)`

## Python
```python
class Solution:
    def longestPalindrome(self, s):
        if len(s) < 2:
            return s

        start = 0
        end = 0

        def expand(left, right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            return left + 1, right - 1

        for i in range(len(s)):
            left1, right1 = expand(i, i)
            left2, right2 = expand(i, i + 1)

            if right1 - left1 > end - start:
                start, end = left1, right1
            if right2 - left2 > end - start:
                start, end = left2, right2

        return s[start:end + 1]
```

## Java
```java
class Solution {
    public String longestPalindrome(String s) {
        if (s.length() < 2) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = Math.max(len1, len2);

            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    private int expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
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
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);

            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
```
