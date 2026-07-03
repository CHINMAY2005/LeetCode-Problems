# 0028 - Find the Index of the First Occurrence in a String

## Problem
Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

## Key Insight
Instead of rechecking characters from scratch after every mismatch, use the pattern itself to know how far to shift.

The Knuth-Morris-Pratt algorithm preprocesses the pattern so the search runs in linear time.

## Approach
Build the longest-prefix-suffix table for `needle`.

- `lps[i]` stores the length of the longest proper prefix of `needle[:i+1]` that is also a suffix.
- During the scan of `haystack`, if characters mismatch, jump the pattern index back using `lps` instead of restarting.
- If the full pattern is matched, return the start index.

## Why It Works
The `lps` table captures the largest valid overlap between a matched prefix and a suffix of the same text window.

That means every shift preserves all useful partial matches and avoids skipping any possible first occurrence.

## Complexity
- Time: `O(m + n)`
- Space: `O(n)`

## Python
```python
class Solution:
    def strStr(self, haystack, needle):
        if needle == '':
            return 0

        lps = [0] * len(needle)
        length = 0
        i = 1

        while i < len(needle):
            if needle[i] == needle[length]:
                length += 1
                lps[i] = length
                i += 1
            elif length > 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

        i = 0
        j = 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1
                if j == len(needle):
                    return i - j
            elif j > 0:
                j = lps[j - 1]
            else:
                i += 1

        return -1
```

## Java
```java
class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.isEmpty()) {
            return 0;
        }

        int[] lps = buildLps(needle);
        int i = 0;
        int j = 0;

        while (i < haystack.length()) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                i++;
                j++;
                if (j == needle.length()) {
                    return i - j;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }

    private int[] buildLps(String needle) {
        int[] lps = new int[needle.length()];
        int length = 0;
        int i = 1;

        while (i < needle.length()) {
            if (needle.charAt(i) == needle.charAt(length)) {
                length++;
                lps[i] = length;
                i++;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }
}
```

## C++
```cpp
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        vector<int> lps = buildLps(needle);
        int i = 0;
        int j = 0;

        while (i < (int)haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == (int)needle.size()) {
                    return i - j;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }

private:
    vector<int> buildLps(const string& needle) {
        vector<int> lps(needle.size(), 0);
        int length = 0;
        int i = 1;

        while (i < (int)needle.size()) {
            if (needle[i] == needle[length]) {
                length++;
                lps[i] = length;
                i++;
            } else if (length > 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        return lps;
    }
};
```